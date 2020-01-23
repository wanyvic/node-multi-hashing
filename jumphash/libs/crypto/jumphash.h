#include "w_blake.h"
#include "w_bmw.h"
#include "w_groestl.h"
#include "w_jh.h"
#include "w_keccak.h"
#include "w_skein.h"
#include "w_luffa.h"
#include "w_cubehash.h"
#include "w_shavite.h"
#include "w_simd.h"
#include "w_echo.h"
#include "w_hamsi.h"
#include "w_fugue.h"

#include "w_shabal.h"
#include "w_sha2big.h"
#include "w_haval.h"
#include "w_panama.h"
#include "w_blake256.h"
#include "w_skein256.h"
#include <string.h>
#include "stdlib.h"
#include "sha256.h"
#include <stdio.h>
static const int hashcount=18;
static void (*jump13[])(unsigned char* input, unsigned char* output)={
    blake_scanHash_post,bmw_scanHash_post,groestl_scanHash_post,skein_scanHash_post,
    jh_scanHash_post,keccak_scanHash_post,luffa_scanHash_post,cubehash_scanHash_post,
    shavite_scanHash_post, simd_scanHash_post, echo_scanHash_post, hamsi_scanHash_post,fugue_scanHash_post
};
static void (*jump18[])(unsigned char* input, unsigned char* output)={
    blake_scanHash_post,bmw_scanHash_post,groestl_scanHash_post,skein_scanHash_post,
    jh_scanHash_post,keccak_scanHash_post,luffa_scanHash_post,cubehash_scanHash_post,
    shavite_scanHash_post, simd_scanHash_post, echo_scanHash_post, hamsi_scanHash_post,
	shabal_scanHash_post,sha2big_scanHash_post,haval_scanHash_post,panama_scanHash_post,
	blake256_scanHash_post,skein256_scanHash_post
};
static void Bin2Hex(unsigned char *sSrc, unsigned char *sDest, int nSrcLen)
{
	int  i;
	char szTmp[3];

	for (i = 0; i < nSrcLen; i++)
	{
		sprintf(szTmp, "%02X", (unsigned char)sSrc[i]);
		memcpy(&sDest[i * 2], szTmp, 2);
	}
	return;
}
	// o out ,x in
static bool Hex2Bin(void *o, const char *x, size_t len) {
	unsigned char *oc = (unsigned char *)o;
	unsigned char c, hc = 0x10;
	len *= 2;
	while (len)
	{
		switch (x[0]) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			c = x[0] - '0';
			break;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			c = x[0] - 'A' + 10;
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			c = x[0] - 'a' + 10;
			break;
		default:
			return false;
		}
		++x;
		if (hc < 0x10)
		{
			(oc++)[0] = (hc << 4) | c;
			hc = 0x10;
		}
		else
			hc = c;
		--len;
	}
	return !x[0];
}
static int getcount(){return hashcount;};
