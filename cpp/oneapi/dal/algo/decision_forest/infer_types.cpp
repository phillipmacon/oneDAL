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

#include "oneapi/dal/algo/decision_forest/infer_types.hpp"
#include "oneapi/dal/detail/common.hpp"

namespace oneapi::dal::decision_forest {

template <typename Task>
class detail::v1::infer_input_impl : public base {
public:
    infer_input_impl(const model<Task>& trained_model, const table& data)
            : trained_model(trained_model),
              data(data) {}
    model<Task> trained_model;
    table data;
};

template <typename Task>
class detail::v1::infer_result_impl : public base {
public:
    table responses;
    table probabilities;
};

using detail::v1::infer_input_impl;
using detail::v1::infer_result_impl;

namespace v1 {

template <typename Task>
infer_input<Task>::infer_input(const model<Task>& trained_model, const table& data)
        : impl_(new infer_input_impl<Task>(trained_model, data)) {}

template <typename Task>
const model<Task>& infer_input<Task>::get_model() const {
    return impl_->trained_model;
}

template <typename Task>
const table& infer_input<Task>::get_data() const {
    return impl_->data;
}

template <typename Task>
void infer_input<Task>::set_model_impl(const model<Task>& value) {
    impl_->trained_model = value;
}

template <typename Task>
void infer_input<Task>::set_data_impl(const table& value) {
    impl_->data = value;
}

template <typename Task>
infer_result<Task>::infer_result() : impl_(new infer_result_impl<Task>{}) {}

template <typename Task>
const table& infer_result<Task>::get_responses() const {
    return impl_->responses;
}

template <typename Task>
const table& infer_result<Task>::get_probabilities_impl() const {
    return impl_->probabilities;
}

template <typename Task>
void infer_result<Task>::set_responses_impl(const table& value) {
    impl_->responses = value;
}

template <typename Task>
void infer_result<Task>::set_probabilities_impl(const table& value) {
    impl_->probabilities = value;
}

template class ONEDAL_EXPORT infer_input<task::classification>;
template class ONEDAL_EXPORT infer_input<task::regression>;
template class ONEDAL_EXPORT infer_result<task::classification>;
template class ONEDAL_EXPORT infer_result<task::regression>;

} // namespace v1
} // namespace oneapi::dal::decision_forest
