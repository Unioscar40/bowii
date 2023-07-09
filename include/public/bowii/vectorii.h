#pragma once
#include <stdlib.h>



namespace bowii::vector {
/**
 * This function do the dot product of two float arrays
 * The size of arrays must be multiple of 4 
 * Return de dot product
*/
float DotProductSSE(const float *array1, const float *array2, const size_t tam);

float* SubVectorSSE(const float *array1, const float *array2, const size_t tam);

float* AddVectorSSE(const float *array1, const float *array2, const size_t tam);

}