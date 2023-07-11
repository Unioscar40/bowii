#pragma once
#include <stdlib.h>



namespace bowii::vector {
/**
 * This function do the dot product of two float arrays
 * The size of arrays must be multiple of 4 
 * Return de dot product
*/
float DotProductSSE(const float* array1, const float* array2, size_t tam);

void SubVectorSSE(const float* array1, const float* array2, float *sol, size_t tam);

void AddVectorSSE(const float* array1, const float* array2, float *sol, size_t tam);

void CopyVectorSSE(const float* source, float* dest, size_t tam);

}