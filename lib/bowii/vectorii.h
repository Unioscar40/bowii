#pragma once
#include <stdlib.h>

/**
 * This function do the dot product of two float arrays
 * The size of arrays must be multiple of 4 
 * Return de dot product
*/

namespace bowii::vector {

float dotProductSSE(const float *array1, const float *array2, const size_t tam);

}