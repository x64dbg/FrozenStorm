#ifndef FROZENSTORMWRAPPER_H
#define FROZENSTORMWRAPPER_H

#include <vector>
#include "FrozenStorm.h"

#define FS_WRAPHASH(hashfunc) \
inline std::vector<unsigned char> hashfunc(const void* data, size_t datasize) { \
    unsigned char* hash = nullptr; \
    size_t hashsize = 0; \
    ::hashfunc(data, datasize, &hash, &hashsize); \
    std::vector<unsigned char> result(hashsize); \
    memcpy(result.data(), hash, hashsize); \
    ::frozen_free(hash); \
    return std::move(result); }

namespace FrozenStorm
{
    inline std::string hash_ToString(const std::vector<unsigned char> & hash)
    {
        std::string result;
        for(size_t i = 0; i < hash.size(); i++)
        {
            char temp[3] = "";
            sprintf_s(temp, "%02x", hash[i]);
            result += temp;
        }
        return std::move(result);
    }

    FS_WRAPHASH(hash_mdc2);
    FS_WRAPHASH(hash_md4);
    FS_WRAPHASH(hash_md5);
    FS_WRAPHASH(hash_sha1);
    FS_WRAPHASH(hash_sha224);
    FS_WRAPHASH(hash_sha256);
    FS_WRAPHASH(hash_sha384);
    FS_WRAPHASH(hash_sha512);
};

#endif //FROZENSTORMWRAPPER_H