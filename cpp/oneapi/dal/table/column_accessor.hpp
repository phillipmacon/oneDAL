/*******************************************************************************
* Copyright 2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include "oneapi/dal/table/detail/table_utils.hpp"
#include "oneapi/dal/table/detail/table_builder.hpp"

namespace oneapi::dal {
namespace v1 {

/// Provides access to the range of values within a single column as one
/// contiguous homogeneous block of memory.
///
/// @tparam T The type of data values in blocks returned by the accessor.
///           Should be const-qualified for read-only access. An accessor
///           supports at least :literal:`float`, :literal:`double`, and
///           :literal:`std::int32_t`.
template <typename T>
class column_accessor {
public:
    using data_t = std::remove_const_t<T>;
    static constexpr bool is_readonly = std::is_const_v<T>;

public:
    /// Creates a read-only accessor object from the table. Available only for
    /// const-qualified :literal:`T`.
    template <typename U = T, std::enable_if_t<std::is_const_v<U>, int> = 0>
    explicit column_accessor(const table& table)
            : pull_iface_(detail::get_pull_column_iface(table)) {
        if (!pull_iface_) {
            using msg = detail::error_messages;
            throw invalid_argument{ msg::object_does_not_provide_read_access_to_columns() };
        }
    }

    explicit column_accessor(const detail::table_builder& builder)
            : pull_iface_(detail::get_pull_column_iface(builder)),
              push_iface_(detail::get_push_column_iface(builder)) {
        if (!pull_iface_) {
            using msg = detail::error_messages;
            throw invalid_argument{ msg::object_does_not_provide_read_access_to_columns() };
        }

        if (!is_readonly && !push_iface_) {
            using msg = detail::error_messages;
            throw invalid_argument{ msg::object_does_not_provide_write_access_to_columns() };
        }
    }

    /// Provides access to the column values of the table.
    /// The method returns an array that directly points to the memory within the table
    /// if it is possible. In that case, the array refers to the memory as to immutable data.
    /// Otherwise, the new memory block is allocated, the data from the table rows is converted
    /// and copied into this block. In this case, the array refers to the block as to mutable data.
    ///
    /// @param[in] column_index The index of the column from which the data is returned by the accessor.
    /// @param[in] row_range    The range of rows that should be read in the :literal:`column_index` block.
    ///
    /// @pre ``row_range`` are within the range of ``[0, obj.row_count)``.
    /// @pre ``column_index`` is within the range of ``[0, obj.column_count)``.
    dal::array<data_t> pull(std::int64_t column_index, const range& row_range = { 0, -1 }) const {
        dal::array<data_t> block;
        pull(block, column_index, row_range);
        return block;
    }

    /// Provides access to the column values of the table.
    /// The method returns an array that directly points to the memory within the table
    /// if it is possible. In that case, the array refers to the memory as to immutable data.
    /// Otherwise, the new memory block is allocated, the data from the table rows is converted
    /// and copied into this block. In this case, the array refers to the block as to mutable data.
    /// The method updates the :expr:`block` array.
    ///
    /// @param[in,out] block    The block which memory is reused (if it is possible) to obtain the data
    ///                         from the table. The block memory is reset either when its size is not big
    ///                         enough, or when it contains immutable data, or when direct memory from the
    ///                         table can be used. If the block is reset to use a direct memory pointer
    ///                         from the object, it refers to this pointer as to immutable memory block.
    /// @param[in] column_index The index of the column from which the data is returned by the accessor.
    /// @param[in] row_range    The range of rows that should be read in the :literal:`column_index` block.
    ///
    /// @pre ``row_range`` are within the range of ``[0, obj.row_count)``.
    /// @pre ``column_index`` is within the range of ``[0, obj.column_count)``.
    T* pull(dal::array<data_t>& block,
            std::int64_t column_index,
            const range& row_range = { 0, -1 }) const {
        pull_iface_->pull_column(detail::default_host_policy{}, block, column_index, row_range);
        return get_block_data(block);
    }

#ifdef ONEDAL_DATA_PARALLEL
    /// Provides access to the column values of the table.
    /// The method returns an array that directly points to the memory within the table
    /// if it is possible. In that case, the array refers to the memory as to immutable data.
    /// Otherwise, the new memory block is allocated, the data from the table rows is converted
    /// and copied into this block. In this case, the array refers to the block as to mutable data.
    ///
    /// @param[in] queue        The SYCL* queue object.
    /// @param[in] column_index The index of the column from which the data is returned by the accessor.
    /// @param[in] row_range    The range of rows that should be read in the :literal:`column_index` block.
    /// @param[in] alloc        The requested kind of USM in the returned block.
    ///
    /// @pre ``row_range`` are within the range of ``[0, obj.row_count)``.
    /// @pre ``column_index`` is within the range of ``[0, obj.column_count)``.
    dal::array<data_t> pull(sycl::queue& queue,
                            std::int64_t column_index,
                            const range& row_range = { 0, -1 },
                            const sycl::usm::alloc& alloc = sycl::usm::alloc::shared) const {
        dal::array<data_t> block;
        pull(queue, block, column_index, row_range, alloc);
        return block;
    }
#endif

#ifdef ONEDAL_DATA_PARALLEL
    /// Provides access to the column values of the table.
    /// The method returns an array that directly points to the memory within the table
    /// if it is possible. In that case, the array refers to the memory as to immutable data.
    /// Otherwise, the new memory block is allocated, the data from the table rows is converted
    /// and copied into this block. In this case, the array refers to the block as to mutable data.
    /// The method updates the :expr:`block` array.
    ///
    /// @param[in] queue        The SYCL* queue object.
    /// @param[in,out] block    The block which memory is reused (if it is possible) to obtain the data
    ///                         from the table. The block memory is reset either when its size is not big
    ///                         enough, or when it contains immutable data, or when direct memory from the
    ///                         table can be used. If the block is reset to use a direct memory pointer
    ///                         from the object, it refers to this pointer as to immutable memory block.
    /// @param[in] column_index The index of the column from which the data is returned by the accessor.
    /// @param[in] row_range    The range of rows that should be read in the :literal:`column_index` block.
    /// @param[in] alloc        The requested kind of USM in the returned block.
    ///
    /// @pre ``row_range`` are within the range of ``[0, obj.row_count)``.
    /// @pre ``column_index`` is within the range of ``[0, obj.column_count)``.
    T* pull(sycl::queue& queue,
            dal::array<data_t>& block,
            std::int64_t column_index,
            const range& row_range = { 0, -1 },
            const sycl::usm::alloc& alloc = sycl::usm::alloc::shared) const {
        pull_iface_->pull_column(detail::data_parallel_policy{ queue },
                                 block,
                                 column_index,
                                 row_range,
                                 alloc);
        return get_block_data(block);
    }
#endif

    template <typename U = T, std::enable_if_t<!std::is_const_v<U>, int> = 0>
    void push(const dal::array<data_t>& block,
              std::int64_t column_index,
              const range& row_range = { 0, -1 }) {
        push_iface_->push_column(detail::default_host_policy{}, block, column_index, row_range);
    }

#ifdef ONEDAL_DATA_PARALLEL
    template <typename U = T, std::enable_if_t<!std::is_const_v<U>, int> = 0>
    void push(sycl::queue& queue,
              const dal::array<data_t>& block,
              std::int64_t column_index,
              const range& row_range = { 0, -1 }) {
        push_iface_->push_column(detail::data_parallel_policy{ queue },
                                 block,
                                 column_index,
                                 row_range);
    }
#endif

private:
    static T* get_block_data(const dal::array<data_t>& block) {
        if constexpr (is_readonly) {
            return block.get_data();
        }
        return block.get_mutable_data();
    }

    detail::shared<detail::pull_column_iface> pull_iface_;
    detail::shared<detail::push_column_iface> push_iface_;
};

} // namespace v1

using v1::column_accessor;

} // namespace oneapi::dal
