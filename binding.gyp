{
    "targets": [
        {
            "target_name": "multihashing",
            "sources": [
                "multihashing.cc",
                "scryptn.c",
                "yescrypt/sha256_Y.c",
                "yescrypt/yescrypt-best.c",
                "yescrypt/yescryptcommon.c",
                "keccak.c",
                "skein.c",
                "x11.c",
                "quark.c",
                "bcrypt.c",
                "groestl.c",
                "blake.c",
                "fugue.c",
                "qubit.c",
                "hefty1.c",
                "shavite3.c",
                "cryptonight.c",
                "x13.c",
                "x14.c",
                "phi1612.c",
                "sha3/sm3.c",
                "sha3/gost.c",
                "sha3/sph_sha2.c",
                "sha3/sph_haval.c",
                "sha3/sph_sha2big.c",
                "sha3/hamsi.c",
                "boolberry.cc",
                "nist5.c",
                "sha1.c",
                "x15.c",
                "fresh.c",
                "s3.c",
                "neoscrypt.c",
                "dcrypt.c",
                "jh.c",
                "c11.c",
                "lbry.c",
                "Sponge.c",
                "Lyra2.c",
                "Lyra2RE.c",
                "Lyra2Z.c",
                "sha3/sph_hefty1.c",
                "sha3/sph_fugue.c",
                "sha3/aes_helper.c",
                "sha3/sph_blake.c",
                "sha3/sph_bmw.c",
                "sha3/sph_cubehash.c",
                "sha3/sph_echo.c",
                "sha3/sph_groestl.c",
                "sha3/sph_jh.c",
                "sha3/sph_keccak.c",
                "sha3/sph_luffa.c",
                "sha3/sph_shavite.c",
                "sha3/sph_simd.c",
                "sha3/sph_skein.c",
                "sha3/sph_whirlpool.c",
                "sha3/sph_shabal.c",
                "sha3/hamsi.c",
                "crypto/oaes_lib.c",
                "crypto/c_keccak.c",
                "crypto/c_groestl.c",
                "crypto/c_blake256.c",
                "crypto/c_jh.c",
                "crypto/c_skein.c",
                "crypto/hash.c",
                "crypto/aesb.c",
                "crypto/wild_keccak.cpp",
                "jumphash/libs/crypto/w_blake.c",
                "jumphash/libs/crypto/w_bmw.c",
                "jumphash/libs/crypto/w_cubehash.c",
                "jumphash/libs/crypto/w_echo.c",
                "jumphash/libs/crypto/w_fugue.c",
                "jumphash/libs/crypto/w_groestl.c",
                "jumphash/libs/crypto/w_hamsi.c",
                "jumphash/libs/crypto/w_aes_helper.c",
                "jumphash/libs/crypto/w_jh.c",
                "jumphash/libs/crypto/w_keccak.c",
                "jumphash/libs/crypto/w_luffa.c",
                "jumphash/libs/crypto/w_shavite.c",
                "jumphash/libs/crypto/w_simd.c",
                "jumphash/libs/crypto/w_sha2big.c",
                "jumphash/libs/crypto/w_haval.c",
                "jumphash/libs/crypto/w_panama.c",
                "jumphash/libs/crypto/w_blake256.c",
                "jumphash/libs/crypto/w_skein256.c",
                "jumphash/libs/crypto/w_shabal.c",
                "jumphash/libs/crypto/sha256.c",
                "jumphash/libs/crypto/w_skein.c",
                "jumphash.cc"
            ],
            "include_dirs": [
                "crypto",
            ],
            "cflags": [
                "-D_GNU_SOURCE -maes -fPIC -Ofast -flto -fuse-linker-plugin -funroll-loops -funswitch-loops -fpeel-loops"
            ],
            "cflags!": [ 
                "-O2", "-fno-strict-aliasing", "-fno-tree-vrp", "-fno-omit-frame-pointer"
            ],
            "ldflags": [
                "-fPIC -Ofast -flto -fuse-linker-plugin"
            ],
            "cflags_cc": [
                "-std=c++0x -maes -march=native"
            ]
        }
    ]
}
