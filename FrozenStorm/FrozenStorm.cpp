#include "FrozenStorm.h"
#include <openssl/mdc2.h>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <zlib.h>

#define HASH_ALLOC(length) *hash = (unsigned char*)frozen_alloc(*hashsize = length)
#define HDATA (const unsigned char*)data
#define HSIZE datasize
#define HHASH *hash

void* frozen_alloc(size_t size)
{
    return GlobalAlloc(GMEM_FIXED, size);
}

void frozen_free(void* ptr)
{
    if(ptr)
        GlobalFree(ptr);
}

void hash_mdc2(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(MDC2_DIGEST_LENGTH);
    MDC2(HDATA, HSIZE, HHASH);
}

void hash_md4(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(MD4_DIGEST_LENGTH);
    MD4(HDATA, HSIZE, HHASH);
}

void hash_md5(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(MD5_DIGEST_LENGTH);
    MD5(HDATA, HSIZE, HHASH);
}

void hash_sha1(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(SHA_DIGEST_LENGTH);
    SHA1(HDATA, HSIZE, HHASH);
}

void hash_sha224(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(SHA224_DIGEST_LENGTH);
    SHA224(HDATA, HSIZE, HHASH);
}

void hash_sha256(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(SHA256_DIGEST_LENGTH);
    SHA256(HDATA, HSIZE, HHASH);
}

void hash_sha384(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(SHA384_DIGEST_LENGTH);
    SHA384(HDATA, HSIZE, HHASH);
}

void hash_sha512(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    HASH_ALLOC(SHA512_DIGEST_LENGTH);
    SHA512(HDATA, HSIZE, HHASH);
}

void hash_adler32(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    auto checksum = adler32(0L, (const Bytef*)data, uInt(datasize));
    HASH_ALLOC(sizeof(checksum));
    memcpy(*hash, &checksum, sizeof(checksum));
}

void hash_crc32(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize)
{
    auto checksum = crc32(0L, (const Bytef*)data, uInt(datasize));
    HASH_ALLOC(sizeof(checksum));
    memcpy(*hash, &checksum, sizeof(checksum));
}
