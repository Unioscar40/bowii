#include <iostream>
#include <cstdint>
#include <cstring>

#include <stdio.h>
#include <string.h>

#include <bowii/BVector.h>
#include "Utils.h"
#include "immintrin.h"

namespace Bowii {

//CLASS BVector
BVector::BVector() {
    mElem = (float*)Utils::AlignedMemory(sizeof(float));
    mTam = 0;
}

BVector::BVector(size_t tam) {

    if(tam < 0)
        throw std::length_error{"Vector constructor: negative size"};

    mElem = (float *)Utils::AlignedMemory(tam*sizeof(float));
    mTam = tam;
}

BVector::BVector(const float* v, size_t tam) {
    mElem = (float *)Utils::AlignedMemory(tam*sizeof(float));
    memcpy((void *)mElem, (void *)v, tam*sizeof(float));
    mTam = tam;
}

BVector::BVector(const BVector& mv) {

    mElem = (float *)Utils::AlignedMemory(mv.Size()*sizeof(float));
    __m128 v1;

    int resto {(int)mv.Size() % 4};
    int slice {(int)mv.Size() - resto};
    size_t i = 0;


    if(slice >= 4)
        for(; i < slice; i+=4) {
            v1 = _mm_load_ps(&mv.Data()[i]);
            _mm_store_ps(&mElem[i],v1);
        }
        
    for(;i < mv.Size(); i++) {
        mElem[i] = mv.Data()[i];
    }
    mTam = mv.Size();
}

BVector::BVector(BVector&& mv) {

    mElem = (float *)Utils::AlignedMemory(mv.Size()*sizeof(float));
    __m128 v1;

    int resto {(int)mv.Size() % 4};
    int slice {(int)mv.Size() - resto};
    size_t i = 0;

    if(slice >= 4)
        for(; i < slice; i+=4) {
            v1 = _mm_load_ps(&mv.Data()[i]);
            _mm_store_ps(&mElem[i],v1);
        }
        
    for(;i < mv.Size(); i++) {
        mElem[i] = mv.Data()[i];
    }
    mTam = mv.Size();
    mv.mTam = 0;
    mv.mElem = nullptr;
}

BVector::~BVector() {
    delete[] mElem;
}

float& BVector::operator[] (int i) {
    if(i < 0 || Size() < i)
        throw std::out_of_range{"BVector::operator[]"};

    return mElem[i];
}

const float& BVector::operator[] (int i) const{
    if(i < 0 || Size() < i)
        throw std::out_of_range{"BVector::operator[]"};

    return mElem[i];
}

BVector& BVector::operator=(const BVector& mv){
    delete[] mElem;
    mElem = (float *)Utils::AlignedMemory(mv.Size()*sizeof(float));
    __m128 v1;

    int resto {(int)mv.Size() % 4};
    int slice {(int)mv.Size() - resto};
    size_t i = 0;


    if(slice >= 4)
        for(; i < slice; i+=4) {
            v1 = _mm_load_ps(&mv.Data()[i]);
            _mm_store_ps(&mElem[i],v1);
        }
        
    for(;i < mv.Size(); i++) {
        mElem[i] = mv.Data()[i];
    }
    mTam = mv.Size();
    return *this;
}

BVector& BVector::operator=(BVector&& mv){

    delete[] mElem;
    mElem = mv.mElem;
    mTam = mv.mTam;
    mv.mElem = nullptr;
    mv.mTam = 0;
    return *this;
}

BVector BVector::operator+(const BVector& mv) {
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    BVector copy(mElem, mTam);

    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&copy.mElem[i]);
            v2 = _mm_load_ps(&mv.mElem[i]);
            res = _mm_add_ps(v1, v2); 
            _mm_store_ps(&copy.mElem[i],res);
        }

    for(; i < mTam; i++) {
        copy.mElem[i] = mv.mElem[i] + copy.mElem[i];
    }
    
    return copy;
}

BVector BVector::operator-(const BVector& mv){
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    BVector copy(mElem, mTam);
    
    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&copy.mElem[i]);
            v2 = _mm_load_ps(&mv.mElem[i]);
            res = _mm_sub_ps(v1, v2); 
            _mm_store_ps(&copy.mElem[i],res);
        }

    for(; i < mTam; i++) {
        copy.mElem[i] = copy.mElem[i] - mv.mElem[i];
    }

    return copy;
}

BVector BVector::operator*(const BVector& mv){
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    BVector copy(mElem, mTam);
    
    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&copy.mElem[i]);
            v2 = _mm_load_ps(&mv.mElem[i]);
            res = _mm_mul_ps(v1, v2); 
            _mm_store_ps(&copy.mElem[i],res);
        }

    for(; i < mTam; i++) {
        copy.mElem[i] = copy.mElem[i] * mv.mElem[i];
    }

    return copy;
}

BVector BVector::operator/(const BVector& mv){
    
    __m128 v1,v2,res;

    if(mv.Size() != mTam)
        throw std::out_of_range{"The size is diferent"};

    BVector copy(mElem, mTam);
    
    int resto {(int)mTam % 4};
    int slice {(int)mTam - resto};
    size_t i = 0;
    if(slice >= 4)
        for(; i < slice ; i+=4) {
            v1 = _mm_load_ps(&copy.mElem[i]);
            v2 = _mm_load_ps(&mv.mElem[i]);
            res = _mm_div_ps(v1, v2); 
            _mm_store_ps(&copy.mElem[i],res);
        }

    for(; i < mTam; i++) {
        copy.mElem[i] = copy.mElem[i] - mv.mElem[i];
    }

    return copy;
}

bool BVector::operator==(const BVector& mv) {

    if(mTam != mv.Size()) {
        return false;
    }

    for(size_t i = 0; i < mTam; i++) {
        if(mElem[i] != mv.mElem[i])
            return false;
    }
    
    return true;
}

bool BVector::operator!=(const BVector& mv) {

    if(mTam != mv.Size()) {
        return true;
    }

    for(size_t i = 0; i < mTam; i++) {
        if(mElem[i] != mv.mElem[i])
            return true;
    }
    
    return false;
}

size_t BVector::Size() const {
    return mTam;
}

const float* BVector::Data() const {
    return mElem;
}

float BVector::DotProduct(const BVector& mv1, const BVector& mv2){
    
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

std::ostream& operator<<(std::ostream& os, const BVector& mv) {
    os << "[";
    for(size_t i = 0; i < mv.Size(); i++) {
        os << " " << mv[i];
    }
    os << " ]";

    return os;
}

} 


