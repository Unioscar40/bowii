#include <iostream>
#include <cstdint>
#include <cstring>

#include <bowii/vectorii.h>
#include <bowii/utils.h>
#include "immintrin.h"

namespace Bowii {

MathVector::MathVector(size_t tam) {

    if(tam < 0)
        throw std::length_error{"Vector constructor: negative size"};

    mElem = (float *)Utils::AlignedMemory(tam);
}

MathVector::MathVector(const float* v) {
    this->Copy(v);
}

MathVector::MathVector(const MathVector& mv) {
    this->Copy(mv);
}

MathVector::~MathVector() {
    delete[] mElem;
}

float& MathVector::operator[] (int i) {
    if(i < 0 || Size() < i)
        throw std::out_of_range{"MathVector::operator[]"};

    return mElem[i];
}

const float& MathVector::operator[] (int i) const{
    if(i < 0 || Size() < i)
        throw std::out_of_range{"MathVector::operator[]"};

    return mElem[i];
}

MathVector& MathVector::operator=(const float* v) {
    mElem = (float *)Utils::AlignedMemory(sizeof(v));
    std::memcpy((void *)v, (void *)mElem, sizeof(v));
}

MathVector& MathVector::operator=(const MathVector& mv) {
    *this = mv.Data();
}

float* MathVector::Data() const {
    return mElem;
}

// float DotProductSSE(const float *array1, const float *array2, size_t tam) {
    
//     float result {0.f};

//     __m128 v1,v2,res;

//     for(size_t i = 0 ; i < tam ; i+=4) {
//         v1 = _mm_load_ps(&array1[i]);
//         v2 = _mm_load_ps(&array2[i]);
//         res = _mm_dp_ps(v1, v2, 0xff);
//         result += _mm_cvtss_f32(res);
//     }

//     return result;
// }

// void SubVectorSSE(const float *array1, const float *array2, float *sol, size_t tam) {
    
//     __m128 v1,v2,res;

//     for(size_t i = 0 ; i < tam ; i+=4) {
//         v1 = _mm_load_ps(&array1[i]);
//         v2 = _mm_load_ps(&array2[i]);
//         res = _mm_sub_ps(v1, v2); 
//         _mm_store_ps(&sol[i],res);
//     }

// }

// void AddVectorSSE(const float *array1, const float *array2, float *sol, size_t tam) {
    
//     __m128 v1,v2,res;

//     for(size_t i = 0 ; i < tam ; i+=4) {
//         v1 = _mm_load_ps(&array1[i]);
//         v2 = _mm_load_ps(&array2[i]);
//         res = _mm_add_ps(v1, v2); 
//         _mm_store_ps(&sol[i],res);
//     }

// }

// void CopyVectorSSE(const float* source, float* dest, size_t tam) {
    
//     __m128 v1;

//     for(size_t i = 0; i < tam; i+=4) {
//         v1 = _mm_load_ps(&source[i]);
//         _mm_store_ps(&dest[i],v1);
//     }
// }

} //end bowii::vector


    

