#include <iostream>

#include <bowii/vectorii.h>
#include "immintrin.h"

namespace bowii::vector {

float dotProductSSE(const float *array1, const float *array2, const size_t tam) {
    
    float result {0.f};

    __m128 v1,v2,res;

    for(size_t i = 0 ; i < tam ; i+=4) {
        v1 = _mm_load_ps(&array1[i]);
        v2 = _mm_load_ps(&array2[i]);
        res = _mm_dp_ps(v1, v2, 0xff);
        result += _mm_cvtss_f32(res);
    }

    return result;
}

} //end bowii::vector