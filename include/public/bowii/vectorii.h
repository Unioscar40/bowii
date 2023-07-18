#pragma once
#include <stdlib.h>
#include <iterator>

namespace Bowii {

class Iterator : public std::iterator<std::input_iterator_tag, float> {
    float* p;
    public:
        Iterator(float *x);
        Iterator(const Iterator& mit);
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
        float& operator*();

};

class MathVector {
public:
    MathVector() = default;
    MathVector(size_t tam);
    MathVector(const float* v);
    MathVector(const MathVector& v);
    ~MathVector();
    float& operator[](int i); //For class vector no const
    const float& operator[](int i) const; //For class vector const
    MathVector& operator=(const MathVector& mv);
    MathVector& operator+(const MathVector& mv);
    MathVector& operator-(const MathVector& mv);
    size_t Size() const;
    const float* Data() const;
    Iterator Begin();
    const Iterator Begin() const;
    Iterator End();
    const Iterator End() const;

private:
    float* mElem; 
    size_t mTam; 
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