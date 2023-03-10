/* file: InitDistributedStep2Local.java */
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

/**
 * @ingroup implicit_als_init_distributed
 * @{
 */
package com.intel.daal.algorithms.implicit_als.training.init;

import com.intel.daal.utils.*;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.algorithms.TrainingDistributed;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__IMPLICIT_ALS__TRAINING__INIT__INITDISTRIBUTEDSTEP2LOCAL"></a>
 * @brief Initializes the implicit ALS model in the second step of the distributed processing mode
 */
public class InitDistributedStep2Local extends TrainingDistributed {
    public InitDistributedStep2LocalInput input;     /*!< %Input data */
    public InitMethod                     method;    /*!< Initialization method for the algorithm */
    private Precision                     precision; /*!< Precision of intermediate computations */

    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs an algorithm for computing initial values for the implicit ALS algorithm in the distributed processing mode
     * by copying input objects and parameters of another algorithm for computing initial values for the implicit ALS algorithm
     *
     * @param context   Context to manage the implicit ALS algorithm
     * @param other     An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     */
    public InitDistributedStep2Local(DaalContext context, InitDistributedStep2Local other) {
        super(context);
        this.method = other.method;
        precision = other.precision;

        this.cObject = cClone(other.cObject, precision.getValue(), method.getValue());

        input = new InitDistributedStep2LocalInput(getContext(), cObject, precision, method);
    }

    /**
     * Constructs an algorithm for computing initial values for the implicit ALS algorithm in the distributed processing mode
     *
     * @param context   Context to manage the implicit ALS algorithm
     * @param cls       Data type to use in intermediate computations for the implicit ALS algorithm,
     *                  Double.class or Float.class
     * @param method    Implicit ALS initialization method, @ref TrainingMethod
     */
    public InitDistributedStep2Local(DaalContext context, Class<? extends Number> cls, InitMethod method) {
        super(context);

        this.method = method;
        if (cls != Double.class && cls != Float.class) {
            throw new IllegalArgumentException("type unsupported");
        }

        if (this.method != InitMethod.fastCSR) {
            throw new IllegalArgumentException("method unsupported");
        }

        if (cls == Double.class) {
            precision = Precision.doublePrecision;
        } else {
            precision = Precision.singlePrecision;
        }

        this.cObject = cInit(precision.getValue(), method.getValue());

        input = new InitDistributedStep2LocalInput(getContext(), cObject, precision, method);
    }

    /**
     * Computes initial values for the implicit ALS algorithm
     * @return Computed initial values
     */
    @Override
    public InitDistributedPartialResultStep2 compute() {
        super.compute();
        InitDistributedPartialResultStep2 partialResult = new InitDistributedPartialResultStep2(getContext(), cGetPartialResult(cObject, precision.getValue(), method.getValue()));
        return partialResult;
    }

    /**
     * Registers user-allocated memory to store partial results of the implicit ALS initialization algorithm
     * @param partialResult   Structure to store partial results of the implicit ALS initialization algorithm
     */
    public void setPartialResult(InitDistributedPartialResultStep2 partialResult) {
        cSetPartialResult(cObject, precision.getValue(), method.getValue(), partialResult.getCObject());
    }

    /**
     * Returns the newly allocated algorithm for computing initial values for the implicit ALS algorithm
     * in the distributed processing mode with a copy of input objects of this algorithm for computing initial values
     * for the implicit ALS algorithm
     * @param context   Context to manage the implicit ALS algorithm
     *
     * @return The newly allocated algorithm
     */
    @Override
    public InitDistributedStep2Local clone(DaalContext context) {
        return new InitDistributedStep2Local(context, this);
    }

    private native long cInit(int precision, int method);

    private native long cGetPartialResult(long cObject, int prec, int method);
    private native void cSetPartialResult(long cObject, int prec, int method, long cResult);

    private native long cClone(long algAddr, int prec, int method);
}
/** @} */
