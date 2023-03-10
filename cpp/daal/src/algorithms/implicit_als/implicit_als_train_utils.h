/* file: implicit_als_train_utils.h */
/*******************************************************************************
* Copyright 2014 Intel Corporation
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

#ifndef __IMPLICIT_ALS_TRAIN_UTILS_H__
#define __IMPLICIT_ALS_TRAIN_UTILS_H__

#include "services/env_detect.h"
#include "services/error_handling.h"

namespace daal
{
namespace algorithms
{
namespace implicit_als
{
namespace training
{
namespace internal
{
template <typename algorithmFPType, CpuType cpu>
services::Status csr2csc(size_t nItems, size_t nUsers, const algorithmFPType * csrdata, const size_t * colIndices, const size_t * rowOffsets,
                         algorithmFPType * cscdata, size_t * rowIndices, size_t * colOffsets);
}
} // namespace training
} // namespace implicit_als
} // namespace algorithms
} // namespace daal
#endif
