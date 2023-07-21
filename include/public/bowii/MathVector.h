#pragma once
#include <stdlib.h>
#include <iterator>
#include <iostream>
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
    friend std::ostream& operator<<(std::ostream& os, const MathVector& mv);
public:
    /**
     * Default constructor
    */
    MathVector();
    /**
     * Create a MathVector with asigned tam 
    */
    MathVector(size_t tam);
    /**
     * Create a MathVector from an array of floats and his size
    */
    MathVector(const float* v, size_t tam);
    /**
     * Copy constructor
    */
    MathVector(const MathVector& mv);
    /**
     * Move constructor
    */
    MathVector(MathVector&& mv);
    /**
     * Default destructor 
    */
    ~MathVector();
    /**
     * 
    */
    float& operator[](int i); //For class vector no const
    const float& operator[](int i) const; //For class vector const
    MathVector& operator=(const MathVector& mv);
    MathVector& operator=(MathVector&& mv);
    MathVector operator+(const MathVector& mv);
    MathVector operator-(const MathVector& mv);
    MathVector operator*(const MathVector& mv);
    MathVector operator/(const MathVector& mv);
    bool operator==(const MathVector& mv);
    size_t Size() const;
    const float* Data() const;
    Iterator Begin();
    const Iterator Begin() const;
    Iterator End();
    const Iterator End() const;
    static float DotProduct(const MathVector& v1, const MathVector& v2);

private:
    float* mElem; 
    size_t mTam; 
};

}

