
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

#include "sph_blake.h"
#include "sph_bmw.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"
#include "sph_hamsi.h"
#include "sph_fugue.h"
#include "scrypt.h"
class hashPow
{
protected:
	const int count=13;
	static hashPow* _p;
	sph_blake512_context     ctx_blake;
	sph_bmw512_context       ctx_bmw;
	sph_groestl512_context   ctx_groestl;
	sph_skein512_context     ctx_skein;
	sph_jh512_context        ctx_jh;
	sph_keccak512_context    ctx_keccak;
	sph_luffa512_context	ctx_luffa1;
	sph_cubehash512_context	ctx_cubehash1;
	sph_shavite512_context	ctx_shavite1;
	sph_simd512_context		ctx_simd1;
	sph_echo512_context		ctx_echo1;
	sph_hamsi512_context	ctx_hamsi1;
	sph_fugue512_context	ctx_fugue1;
	hashPow();
public:
	static hashPow* getinstance();
	void compute(int id,const unsigned char * input, unsigned char * hash);
	//void write(int id, unsigned char * input);
	int getcount(){return count;};
	//void addFinalize(int id, int nNonce, unsigned char* hash);
	
}; 
