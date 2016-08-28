![logo](https://i.imgur.com/EfyWPnu.png)

FrozenStorm is a project to make cryptography, hashing, checksumming, compression and transformation algorithms available over a unified interface.

### Easy in C

FrozenStorm has a simple an unified C interface for its various components. This is how you generate a SHA1 hash and print it to the console in C:

```c
#include <stdio.h>
#include "FrozenStorm.h"

void sha1example()
{
    const char* data = "sha1";
    unsigned char* hash;
    size_t hashsize, i;

    hash_sha1(data, strlen(data), &hash, &hashsize);
    for (i = 0; i < hashsize; i++)
        printf("%02x", hash[i]);
    puts("");

    frozen_free(hash);
}
```

### Even easier in C++

If you use the provided C++ wrapper it looks like this:

```c++
#include <stdio.h>
#include "FrozenStormWrapper.h"

void sha1example()
{
    auto data = "sha1";
    auto hash = FrozenStorm::hash_sha1(data, strlen(data));
    puts(FrozenStorm::hash_ToString(hash).c_str());
}
```
