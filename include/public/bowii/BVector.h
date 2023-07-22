#pragma once
#include <stdlib.h>
#include <iterator>
#include <iostream>
namespace Bowii {

class BVector {
    friend std::ostream& operator<<(std::ostream& os, const BVector& mv);
public:
    /**
     * Default constructor
    */
    BVector();
    /**
     * Create a BVector with asigned tam 
    */
    BVector(size_t tam);
    /**
     * Create a BVector from an array of floats and his size
    */
    BVector(const float* v, size_t tam);
    /**
     * Copy constructor
    */
    BVector(const BVector& mv);
    /**
     * Move constructor
    */
    BVector(BVector&& mv);
    /**
     * Default destructor 
    */
    ~BVector();
    /**
     * 
    */
    float& operator[](int i); //For class vector no const
    const float& operator[](int i) const; //For class vector const
    BVector& operator=(const BVector& mv);
    BVector& operator=(BVector&& mv);
    BVector operator+(const BVector& mv);
    BVector operator-(const BVector& mv);
    BVector operator*(const BVector& mv);
    BVector operator/(const BVector& mv);
    bool operator==(const BVector& mv);
    bool operator!=(const BVector& mv);
    size_t Size() const;
    const float* Data() const;
    static float DotProduct(const BVector& v1, const BVector& v2);

private:
    float* mElem; 
    size_t mTam; 
};

}

