#include "jumphash.h"
#include "jumphash/libs/crypto/jumphash.h"
void jump_hash(const char *input, char *output, uint32_t size)
{
    CSHA256 sha256hasher, sha256hasher2;
    uint8_t base[32], powHash[32], hashout0[64], hashout1[64];
    sha256hasher.Write((uint8_t *)input, 76).Finalize((uint8_t *)base);
    int jumpid = (((uint16_t *)input)[2]) % 18;
    Bin2Hex((uint8_t *)base, hashout0, 32);
    ((uint32_t *)hashout0)[14] ^= ((uint32_t *)hashout0)[15];
    ((uint32_t *)hashout0)[15] = ((uint32_t *)input)[19];
    jump18[jumpid](hashout0, hashout1);
    sha256hasher2.Write(hashout1, 64).Finalize((uint8_t *)output);
}
