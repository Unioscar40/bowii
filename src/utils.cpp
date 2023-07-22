#include "Utils.h"
#include "Constants.h"
namespace Bowii::Utils {

#define _ALIGNED_BYTES 16

void* AlignedMemory(size_t size) {
    return aligned_alloc(_ALIGNED_BYTES_SSE, size);
}

} //namespace bowii::utils