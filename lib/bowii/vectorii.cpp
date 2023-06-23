
#include "vectorii.h"
#include "utils.h"
#include "immintrin.h"

#define _ALIGNED_BYTES 16

namespace bowii::vector {

float dotProduct(const float *array1, const float *array2, const size_t tam) {
    
    float result {0.f};
    
    array1 = (float *)aligned_memorySSE(_ALIGNED_BYTES,sizeof(float) * tam);
    array2 = (float *)aligned_memorySSE(_ALIGNED_BYTES,sizeof(float) * tam);
    
    __m128 v1,v2,res;

    for(size_t i = 0 ; i < tam ; i+=4) {
        v1 = _mm_load_ps(&array1[1]);
        v2 = _mm_load_ps(&array2[1]);
        res = _mm_dp_ps(v1, v2, 0xff);
        result += _mm_cvtss_f32(res);
    }

    return result;
}

} //end bowii::vector