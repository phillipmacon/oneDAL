/* file: model.cpp */
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
#include "com_intel_daal_algorithms_decision_forest_classification_Model.h"
#include "com/intel/daal/common_helpers.h"
#include "com/intel/daal/common_helpers_functions.h"
#include "../../classifier/tree_node_visitor.h"
#include "../../tree_utils/classification/tree_node_visitor.h"

USING_COMMON_NAMESPACES()
namespace dfc = daal::algorithms::decision_forest::classification;

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cGetNumberOfTrees
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cGetNumberOfTrees(JNIEnv *, jobject, jlong modAddr)
{
    return (jlong)(*(dfc::ModelPtr *)modAddr)->getNumberOfTrees();
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseDF
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseDF(JNIEnv * env, jobject, jlong modAddr,
                                                                                                        jlong iTree, jobject visitor)
{
    JavaVM * jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if (status != 0) throwError(env, "Couldn't get Java VM interface");
    daal::classification::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseDF((size_t)iTree, visitorImpl);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseBF
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseBF(JNIEnv * env, jobject, jlong modAddr,
                                                                                                        jlong iTree, jobject visitor)
{
    JavaVM * jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if (status != 0) throwError(env, "Couldn't get Java VM interface");
    daal::classification::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseBF((size_t)iTree, visitorImpl);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cClear
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cClear(JNIEnv *, jobject, jlong modAddr)
{
    (*(dfc::ModelPtr *)modAddr)->clear();
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseDFS
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseDFS(JNIEnv * env, jobject, jlong modAddr,
                                                                                                         jlong iTree, jobject visitor)
{
    JavaVM * jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if (status != 0) throwError(env, "Couldn't get Java VM interface");
    daal::classification::tree_utils::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseDFS((size_t)iTree, visitorImpl);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_Model
* Method:    cTraverseBFS
* Signature: (JJLcom/intel/daal/algorithms/decision_forest/classification/NodeVisitor;)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_Model_cTraverseBFS(JNIEnv * env, jobject, jlong modAddr,
                                                                                                         jlong iTree, jobject visitor)
{
    JavaVM * jvm;
    // Get pointer to the Java VM interface function table
    jint status = env->GetJavaVM(&jvm);
    if (status != 0) throwError(env, "Couldn't get Java VM interface");
    daal::classification::tree_utils::JavaTreeNodeVisitor visitorImpl(jvm, visitor);
    (*(dfc::ModelPtr *)modAddr)->traverseBFS((size_t)iTree, visitorImpl);
}
