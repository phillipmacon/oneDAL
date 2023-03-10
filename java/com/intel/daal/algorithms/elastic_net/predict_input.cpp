/* file: predict_input.cpp */
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

#include "com_intel_daal_algorithms_elastic_net_prediction_Input.h"

#include "com/intel/daal/common_helpers.h"

#include "com_intel_daal_algorithms_elastic_net_prediction_PredictionMethod.h"
#define defaultDenseValue com_intel_daal_algorithms_elastic_net_prediction_PredictionMethod_defaultDenseValue
#include "com_intel_daal_algorithms_elastic_net_prediction_PredictionInputId.h"
#define dataId  com_intel_daal_algorithms_elastic_net_prediction_PredictionInputId_dataId
#define modelId com_intel_daal_algorithms_elastic_net_prediction_PredictionInputId_modelId

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::elastic_net::prediction;

/*
 * Class:     com_intel_daal_algorithms_elastic_net_prediction_Input
 * Method:    cSetInput
 * Signature:(JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_elastic_1net_prediction_Input_cSetInput(JNIEnv * env, jobject thisObj, jlong inputAddr, jint id,
                                                                                              jlong ntAddr)
{
    if (id == dataId)
    {
        jniInput<elastic_net::prediction::Input>::set<elastic_net::prediction::NumericTableInputId, NumericTable>(
            inputAddr, elastic_net::prediction::data, ntAddr);
    }
    else if (id == modelId)
    {
        jniInput<elastic_net::prediction::Input>::set<elastic_net::prediction::ModelInputId, elastic_net::Model>(
            inputAddr, elastic_net::prediction::model, ntAddr);
    }
}

/*
 * Class:     com_intel_daal_algorithms_elastic_net_prediction_PredictionBatch
 * Method:    cGetInput
 * Signature:(JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_elastic_1net_prediction_Input_cGetInput(JNIEnv * env, jobject thisObj, jlong inputAddr,
                                                                                               jint id)
{
    if (id == dataId)
    {
        return jniInput<elastic_net::prediction::Input>::get<elastic_net::prediction::NumericTableInputId, NumericTable>(
            inputAddr, elastic_net::prediction::data);
    }
    else if (id == modelId)
    {
        return jniInput<elastic_net::prediction::Input>::get<elastic_net::prediction::ModelInputId, elastic_net::Model>(
            inputAddr, elastic_net::prediction::model);
    }

    return (jlong)0;
}
