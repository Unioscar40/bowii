#include "utils.h"

void* algined_memorySSE(size_t alignment, size_t size) {
    return aligned_alloc(alignment, size);
}