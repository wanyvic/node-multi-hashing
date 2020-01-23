#ifndef JUMPHASH_H
#define JUMPHASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void jump_hash(const char* input, char* output, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif