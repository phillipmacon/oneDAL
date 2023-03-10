/* file: train_types.cpp */
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
#include "com_intel_daal_algorithms_gbt_classification_training_Parameter.h"
#include "com_intel_daal_algorithms_gbt_classification_training_TrainingResult.h"
#include "algorithms/gradient_boosted_trees/gbt_classification_training_types.h"
#include "com/intel/daal/common_helpers.h"
#include "com/intel/daal/common_defines.i"

USING_COMMON_NAMESPACES()

namespace gbtc  = gbt::classification;
namespace gbtt  = gbt::training;
namespace gbtct = daal::algorithms::gbt::classification::training;

#include "com_intel_daal_algorithms_classifier_training_TrainingResultId.h"
#define ModelResult com_intel_daal_algorithms_classifier_training_TrainingResultId_Model

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetSplitMethod
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetSplitMethod(JNIEnv *, jobject, jlong parAddr)
{
    return (jint)(*(gbtct::Parameter *)parAddr).splitMethod;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetSplitMethod
* Signature: (JI)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetSplitMethod(JNIEnv *, jobject, jlong parAddr,
                                                                                                            jint value)
{
    (*(gbtct::Parameter *)parAddr).splitMethod = (gbtt::SplitMethod)value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMaxIterations
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMaxIterations(JNIEnv *, jobject, jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).maxIterations;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMaxIterations
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMaxIterations(JNIEnv *, jobject, jlong parAddr,
                                                                                                              jlong value)
{
    (*(gbtct::Parameter *)parAddr).maxIterations = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetObservationsPerTreeFraction
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetObservationsPerTreeFraction(JNIEnv *, jobject,
                                                                                                                            jlong parAddr,
                                                                                                                            jdouble value)
{
    (*(gbtct::Parameter *)parAddr).observationsPerTreeFraction = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetObservationsPerTreeFraction
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetObservationsPerTreeFraction(JNIEnv *, jobject,
                                                                                                                               jlong parAddr)
{
    return (jdouble)(*(gbtct::Parameter *)parAddr).observationsPerTreeFraction;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetFeaturesPerNode
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetFeaturesPerNode(JNIEnv *, jobject, jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).featuresPerNode;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetFeaturesPerNode
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetFeaturesPerNode(JNIEnv *, jobject, jlong parAddr,
                                                                                                                jlong value)
{
    (*(gbtct::Parameter *)parAddr).featuresPerNode = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMaxTreeDepth
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMaxTreeDepth(JNIEnv *, jobject, jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).maxTreeDepth;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMaxTreeDepth
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMaxTreeDepth(JNIEnv *, jobject, jlong parAddr,
                                                                                                             jlong value)
{
    (*(gbtct::Parameter *)parAddr).maxTreeDepth = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMinObservationsInLeafNode
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMinObservationsInLeafNode(JNIEnv *, jobject,
                                                                                                                           jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).minObservationsInLeafNode;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMinObservationsInLeafNode
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMinObservationsInLeafNode(JNIEnv *, jobject,
                                                                                                                          jlong parAddr, jlong value)
{
    (*(gbtct::Parameter *)parAddr).minObservationsInLeafNode = value;
}

/*
 * Class:     com_intel_daal_algorithms_decision_forest_classification_training_Parameter
 * Method:    cSetEngine
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_training_Parameter_cSetEngine(JNIEnv * env, jobject thisObj,
                                                                                                                    jlong cParameter,
                                                                                                                    jlong engineAddr)
{
    (((gbtct::Parameter *)cParameter))->engine = staticPointerCast<engines::BatchBase, AlgorithmIface>(*(SharedPtr<AlgorithmIface> *)engineAddr);
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetShrinkage
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetShrinkage(JNIEnv *, jobject, jlong parAddr,
                                                                                                          jdouble value)
{
    (*(gbtct::Parameter *)parAddr).shrinkage = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetShrinkage
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetShrinkage(JNIEnv *, jobject, jlong parAddr)
{
    return (jdouble)(*(gbtct::Parameter *)parAddr).shrinkage;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMinSplitLoss
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMinSplitLoss(JNIEnv *, jobject, jlong parAddr,
                                                                                                             jdouble value)
{
    (*(gbtct::Parameter *)parAddr).minSplitLoss = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMinSplitLoss
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMinSplitLoss(JNIEnv *, jobject, jlong parAddr)
{
    return (jdouble)(*(gbtct::Parameter *)parAddr).minSplitLoss;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetLambda
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetLambda(JNIEnv *, jobject, jlong parAddr,
                                                                                                       jdouble value)
{
    (*(gbtct::Parameter *)parAddr).lambda = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetLambda
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetLambda(JNIEnv *, jobject, jlong parAddr)
{
    return (jdouble)(*(gbtct::Parameter *)parAddr).lambda;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMaxBins
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMaxBins(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(gbtct::Parameter *)parAddr).maxBins = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMaxBins
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMaxBins(JNIEnv *, jobject, jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).maxBins;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cSetMinBinSize
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cSetMinBinSize(JNIEnv *, jobject, jlong parAddr,
                                                                                                           jlong value)
{
    (*(gbtct::Parameter *)parAddr).minBinSize = value;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_Parameter
* Method:    cGetMinBinSize
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_Parameter_cGetMinBinSize(JNIEnv *, jobject, jlong parAddr)
{
    return (jlong)(*(gbtct::Parameter *)parAddr).minBinSize;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_TrainingResult
* Method:    cGetResult
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_TrainingResult_cGetResult(JNIEnv *, jobject, jlong algAddr,
                                                                                                             jint cmode)
{
    SerializationIfacePtr * ptr = new SerializationIfacePtr();

    if (cmode == jBatch)
    {
        SharedPtr<classifier::training::Batch> alg =
            staticPointerCast<classifier::training::Batch, AlgorithmIface>(*(SharedPtr<AlgorithmIface> *)algAddr);
        *ptr = alg->getResult();
    }
    return (jlong)ptr;
}

/*
* Class:     com_intel_daal_algorithms_gbt_classification_training_TrainingResult
* Method:    cGetModel
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_classification_training_TrainingResult_cGetModel(JNIEnv *, jobject thisObj, jlong resAddr,
                                                                                                            jint id)
{
    gbtc::ModelPtr * m = new gbtc::ModelPtr();
    classifier::training::ResultPtr res =
        services::staticPointerCast<classifier::training::Result, SerializationIface>(*((SerializationIfacePtr *)resAddr));

    switch (id)
    {
    case ModelResult: *m = services::staticPointerCast<gbtc::Model, classifier::Model>(res->get(classifier::training::model)); break;
    default: break;
    }
    return (jlong)m;
}
