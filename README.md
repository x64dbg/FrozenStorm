![logo](https://i.imgur.com/EfyWPnu.png)

FrozenStorm is a project to make cryptography, hashing, checksumming, compression and transformation algorithms available over a unified interface.

```
#ifndef FROZENSTORM_H
#define FROZENSTORM_H

#include <windows.h>

#ifdef BUILD_FROZENSTORM
#define FROZEN_API extern "C" __declspec(dllexport)
#else
#define FROZEN_API extern "C" __declspec(dllimport)
#endif //BUILD_FROZENSTORM

FROZEN_API void* frozen_alloc(size_t size);
FROZEN_API void frozen_free(void* ptr);

FROZEN_API void hash_mdc2(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_md4(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_md5(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_sha1(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_sha224(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_sha256(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_sha384(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);
FROZEN_API void hash_sha512(const void* data, size_t datasize, unsigned char** hash, size_t* hashsize);

#endif //FROZENSTORM_H
```
