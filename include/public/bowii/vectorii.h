#pragma once
#include <stdlib.h>



namespace Bowii {

class MathVector {
public:
    MathVector() = default;
    MathVector(size_t tam);
    MathVector(const float* v);
    MathVector(const MathVector& v);
    ~MathVector();
    float& operator[](int i); //For class vector no const
    const float& operator[](int i) const; //For class vector const
    
    size_t Size() const;
    MathVector& operator=(const float* v);
    MathVector& operator=(const MathVector& mv);
    float* Data() const;

private:
    float* mElem; 
    size_t tam; 
};
/**
 * This function do the dot product of two float arrays
 * The size of arrays must be multiple of 4 
 * Return de dot product
*/
float DotProduct(const MathVector& v1, const MathVector& v2);

void SubVectorSSE(const float* array1, const float* array2, float *sol, size_t tam);

void AddVectorSSE(const float* array1, const float* array2, float *sol, size_t tam);

void CopyVectorSSE(const float* source, float* dest, size_t tam);

// void CopyVectorSSE(const float* source, float* dest, size_t tam) {
    
//     __m128 v1;

//     for(size_t i = 0; i < tam; i+=4) {
//         v1 = _mm_load_ps(&source[i]);
//         _mm_store_ps(&dest[i],v1);
//     }
// }


}