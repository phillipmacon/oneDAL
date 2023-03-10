/* file: PredictionResultId.java */
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
 * @ingroup prediction
 * @{
 */
package com.intel.daal.algorithms.regression.prediction;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__REGRESSION__PREDICTION__PREDICTIONRESULTID"></a>
 * @brief Available identifiers of results of the regression model-based prediction algorithm
 */
public final class PredictionResultId {
    private int _value;

    /**
     * Constructs the prediction result object identifier using the provided value
     * @param value     Value corresponding to the prediction result object identifier
     */
    public PredictionResultId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the prediction result object identifier
     * @return Value corresponding to the prediction result object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int Prediction = 0;

    /** Prediction results */
    public static final PredictionResultId prediction = new PredictionResultId(Prediction);

    public static boolean validate(PredictionResultId id) {
        return id.getValue() == prediction.getValue();
    }

    public static void throwIfInvalid(PredictionResultId id) {
        if (id == null) {
            throw new IllegalArgumentException("Null result id");
        }
        if (!PredictionResultId.validate(id)) {
            throw new IllegalArgumentException("Unsupported result id");
        }
    }
}
/** @} */
