/* file: prediction.cpp */
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

#include <jni.h>
#include "com_intel_daal_algorithms_Prediction.h"

#include "services/daal_defines.h"
#include "algorithms/algorithm.h"
#include "com/intel/daal/common_helpers_functions.h"

using namespace daal::services;
using namespace daal::algorithms;

/*
 * Class:     com_intel_daal_algorithms_Prediction
 * Method:    cCompute
 * Signature:(J)I
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_Prediction_cCompute(JNIEnv * env, jobject thisObj, jlong algAddr)
{
    SharedPtr<Prediction> alg = staticPointerCast<Prediction, AlgorithmIface>(*(SharedPtr<AlgorithmIface> *)algAddr);
    DAAL_CHECK_THROW(alg->compute());
}

/*
 * Class:     com_intel_daal_algorithms_Prediction
 * Method:    cDispose
 * Signature:(J)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_Prediction_cCheckComputeParameters(JNIEnv * env, jobject thisObj, jlong algAddr)
{
    SharedPtr<Prediction> alg = staticPointerCast<Prediction, AlgorithmIface>(*(SharedPtr<AlgorithmIface> *)algAddr);
    DAAL_CHECK_THROW(alg->checkComputeParams());
}

/*
 * Class:     com_intel_daal_algorithms_Prediction
 * Method:    cDispose
 * Signature:(J)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_Prediction_cDispose(JNIEnv * env, jobject thisObj, jlong algAddr)
{
    delete (SharedPtr<AlgorithmIface> *)algAddr;
}
