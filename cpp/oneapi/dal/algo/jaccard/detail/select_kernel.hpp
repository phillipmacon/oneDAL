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

#include "oneapi/dal/algo/jaccard/common.hpp"
#include "oneapi/dal/algo/jaccard/detail/vertex_similarity_default_kernel.hpp"
#include "oneapi/dal/algo/jaccard/vertex_similarity_types.hpp"
#include "oneapi/dal/graph/detail/undirected_adjacency_vector_graph_impl.hpp"

namespace oneapi::dal::preview::jaccard::detail {

template <typename Policy, typename Descriptor, typename Topology>
struct backend_base {
    using float_t = typename Descriptor::float_t;
    using task_t = typename Descriptor::task_t;
    using method_t = typename Descriptor::method_t;

    virtual vertex_similarity_result<task_t> operator()(const Policy& ctx,
                                                        const Descriptor& descriptor,
                                                        const Topology& t,
                                                        caching_builder& result_builder) = 0;
    virtual ~backend_base() = default;
};

template <typename Policy, typename Descriptor, typename Topology>
struct backend_default : public backend_base<Policy, Descriptor, Topology> {
    static_assert(dal::detail::is_one_of_v<Policy, dal::detail::host_policy>,
                  "Host policy only is supported.");

    using float_t = typename Descriptor::float_t;
    using task_t = typename Descriptor::task_t;
    using method_t = typename Descriptor::method_t;

    virtual vertex_similarity_result<task_t> operator()(const Policy& ctx,
                                                        const Descriptor& descriptor,
                                                        const Topology& t,
                                                        caching_builder& result_builder) {
        return vertex_similarity_kernel_cpu<float_t, method_t, task_t, Topology>()(ctx,
                                                                                   descriptor,
                                                                                   t,
                                                                                   result_builder);
    }
};

template <typename Policy, typename Descriptor, typename Topology>
dal::detail::shared<backend_base<Policy, Descriptor, Topology>> get_backend(const Descriptor& desc,
                                                                            const Topology& t) {
    return std::make_shared<backend_default<Policy, Descriptor, Topology>>();
}

} // namespace oneapi::dal::preview::jaccard::detail
