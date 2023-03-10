/* file: resultcollection.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "daal.h"
#include "com_intel_daal_algorithms_quality_metric_set_ResultCollection.h"

using namespace daal;
using namespace daal::algorithms;
using namespace daal::data_management;
using namespace daal::algorithms::quality_metric_set;

/*
 * Class:     com_intel_daal_algorithms_ResultCollection
 * Method:    cInit
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cInit(JNIEnv *, jobject, jlong algAddr)
{
    ResultCollectionPtr * shPtr = new ResultCollectionPtr();
    *shPtr                      = ((Batch *)algAddr)->getResultCollection();
    return (jlong)shPtr;
}

/*
 * Class:     com_intel_daal_algorithms_ResultCollection
 * Method:    cAddResult
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cAddResult(JNIEnv *, jobject, jlong colAddr, jint key,
                                                                                                       jlong resAddr)
{
    ResultCollectionPtr * shPtr = (ResultCollectionPtr *)colAddr;
    ResultCollection * resCol   = shPtr->get();
    resCol->add(key, *(ResultPtr *)resAddr);
}

/*
 * Class:     com_intel_daal_algorithms_quality_metric_set_ResultCollection
 * Method:    cGetResult
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cGetResult(JNIEnv *, jobject, jlong colAddr, jint key)
{
    SerializationIfacePtr * resShPtr = new SerializationIfacePtr();
    ResultCollectionPtr shPtr        = (*(ResultCollectionPtr *)colAddr);
    *resShPtr                        = shPtr->getResult((size_t)key);
    return (jlong)(resShPtr);
}
