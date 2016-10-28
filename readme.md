
# [42 Project](www.42.fr)

Project validate with 116%.

## Malloc / Free / Realloc / Calloc

Implement those functions with pre-allocate memory pages to heberge all allocation size.
Memory page size depend on `get_page_size()`

- TINY
- SMALL
- LARGE

Functions are thread safe.

## show\_alloc\_mem

Print the current state of memory page allocation.

```
TINY 0x10aa9d078
[V] 0x10aa9d098 - 0x10aaa3000 : 24424 octets
[X] 0x10aa9d020 - 0x10aa9d078 : 88 octets

Total: 24576
SMALL 0x10aac1d16
[V] 0x10aac1d36 - 0x10aac3000 : 4810 octets
[X] 0x10aaba020 - 0x10aac1d16 : 31990 octets

Total: 36864
LARGE 0x10ac85000
[X] 0x10ac85020 - 0x10acd7c47 : 338983 octets
[X] 0x10ac48020 - 0x10ac84142 : 246050 octets
[X] 0x10ac16020 - 0x10ac47c02 : 203746 octets
[X] 0x10abf5020 - 0x10ac158b3 : 133267 octets
[X] 0x10ab96020 - 0x10abf4c13 : 388083 octets
[X] 0x10ab37020 - 0x10ab9590b : 387307 octets
[X] 0x10aae4020 - 0x10ab36f4d : 339757 octets
[X] 0x10aac3020 - 0x10aae3ffa : 135130 octets
[X] 0x10aaa3020 - 0x10aab9bb5 : 93077 octets

Total: 2265688
```

## License

Project is under MIT license.
