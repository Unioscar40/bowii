#include <iostream>
#include <cstdint>
#include <cstring>

#include <bowii/vectorii.h>
#include <bowii/utils.h>
#include "immintrin.h"

//TODO: Revisar métodos de copia

namespace Bowii {

//CLASS ITERATOR
Iterator::Iterator(float *x) {
    p = x;
}

Iterator::Iterator(const Iterator& mit) {
    p = mit.p;
}

Iterator& Iterator::operator++() {
    p++;
    return *this;
}

Iterator Iterator::operator++(int) {
    Iterator tmp(*this);
    operator++();
    return tmp;
}

bool Iterator::operator==(const Iterator& it) const {
    return p == it.p;
}

bool Iterator::operator!=(const Iterator& it) const {
    return p != it.p;
}

float& Iterator::operator*() {
    return *p;
}

//CLASS MATHVECTOR
MathVector::MathVector(size_t tam) {

    if(tam < 0)
        throw std::length_error{"Vector constructor: negative size"};

    mElem = (float *)Utils::AlignedMemory(tam*sizeof(float));
    mTam = tam;
}

MathVector::MathVector(const float* v) {
    mElem = (float *)Utils::AlignedMemory(sizeof(v));
    std::memcpy((void *)mElem, (void *)v, sizeof(v));
    mTam = sizeof(v)/sizeof(float);
}

MathVector::MathVector(const MathVector& mv) {
    mElem = (float *)Utils::AlignedMemory(mv.Size()*sizeof(float));
    std::memcpy((void *)mElem, (void *)mv.Data(), sizeof(mv.Size()*sizeof(float)));
    mTam = mv.Size();
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

MathVector& MathVector::operator=(const MathVector& mv) {
    delete[] mElem;
    mElem = (float *)Utils::AlignedMemory(mv.Size()*sizeof(float));
    std::cout << "SIZE: " << mv.Size() << std::endl;
    std::memcpy((void *)mElem, (void *)mv.Data(), sizeof(mv.Size()*sizeof(float)));
    mTam = mv.Size();
    return *this;
}

MathVector& MathVector::operator+(const MathVector& mv) {
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&mElem[i]);
            v2 = _mm_load_ps(&mv.Data()[i]);
            res = _mm_add_ps(v1, v2); 
            _mm_store_ps(&mElem[i],res);
        }

    for(; i < mTam; i++) {
        mElem[i] = mElem[i] + mv.Data()[i];
    }
    
    return *this;
}

MathVector& MathVector::operator-(const MathVector& mv) {
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&mElem[i]);
            v2 = _mm_load_ps(&mv.Data()[i]);
            res = _mm_sub_ps(v1, v2); 
            _mm_store_ps(&mElem[i],res);
        }

    for(; i < mTam; i++) {
        mElem[i] = mElem[i] - mv[i];
    }
    
    return *this;
}

size_t MathVector::Size() const {
    return mTam;
}

const float* MathVector::Data() const {
    return mElem;
}

Iterator MathVector::Begin() {
    return Iterator(mElem);
}

const Iterator MathVector::Begin() const{
    return Iterator(mElem);
}

Iterator MathVector::End() {
    return Iterator(mElem + mTam);
}

const Iterator MathVector::End() const{
    return Iterator(mElem + mTam);
}

float MathVector::DotProduct(const MathVector& mv1, const MathVector& mv2){
    
    float result {0.f};

    __m128 v1,v2,res;

    if(mv1.Size() != mv2.Size())
        throw std::out_of_range{"The size is diferent"};

    int resto {(int)mv1.Size() % 4};
    int slice {(int)mv1.Size() - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&mv1.Data()[i]);
            v2 = _mm_load_ps(&mv2.Data()[i]);
            res = _mm_dp_ps(v1, v2, 0xff);
            result += _mm_cvtss_f32(res);
        }
    for(; i < mv1.Size(); i++){
        result+= mv1[i] * mv2[i];
    }
    
    return result;
}

} 


    

