#include <bowii/utils.h>
#include "constants.h"
namespace bowii::utils {

#define _ALIGNED_BYTES 16

void* aligned_memorySSE(size_t size) {
    return aligned_alloc(_ALIGNED_BYTES_SSE, size);
}

} //namespace bowii::utils