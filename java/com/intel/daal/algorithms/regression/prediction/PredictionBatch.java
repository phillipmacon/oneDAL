/* file: PredictionBatch.java */
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
 * @defgroup regression_prediction_batch Batch
 * @ingroup prediction
 * @{
 */
package com.intel.daal.algorithms.regression.prediction;

import com.intel.daal.utils.*;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__REGRESSION__PREDICTION__PREDICTIONBATCH"></a>
 * @brief Base class for regression model-based prediction in the batch processing mode
 *
 * @par References
 *      - NumericTableInputId class
 *      - ModelInputId class
 *      - PredictionResultId class
 */
public abstract class PredictionBatch extends com.intel.daal.algorithms.Prediction {
    protected Precision    prec;

    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the regression model-based prediction algorithm by copying input objects and parameters
     * of another regression model-based prediction algorithm
     * @param context   Context to manage regression algorithm
     * @param other     An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     */
    public PredictionBatch(DaalContext context, PredictionBatch other) {
        super(context);
        prec = other.prec;
    }

    /**
     * Constructs the regression model-based prediction algorithm
     * @param context   Context to manage regression algorithm
     */
    public PredictionBatch(DaalContext context) {
        super(context);
    }

    /**
     * Computes prediction results based on the model of the regression algorithm
     * @return %Prediction results
     */
    @Override
    public PredictionResult compute() {
        super.compute();
        return new PredictionResult(getContext(), cObject);
    }

    /**
     * Registers user-allocated memory for storing results
     * @param result Structure for storing results
     */
    public void setResult(PredictionResult result) {
        cSetResult(cObject, result.getCObject());
    }

    /**
     * Returns the newly allocated regression model-based prediction algorithm with a copy of input objects
     * and parameters of this algorithm
     * @param context   Context to manage regression algorithm
     *
     * @return The newly allocated algorithm
     */
    @Override
    public abstract PredictionBatch clone(DaalContext context);

    private native void cSetResult(long cAlgorithm, long cResult);
}
/** @} */
