# CodingTools

My tools for c++


## online boost compiler  
https://www.onlinegdb.com

## DO NOT use
1. declare anything by MACRO
2. friend
3. static variable
4. link-reference type data structure, eg. set/map/list/......


## Performance issue
0. use Clang++
1. use unsigned as possible
2. use Type of 32 byte such as int uint float......
3. use hash table as possible
4. use switch as possible
5. call by value on Class small than 128 byte
6. use move on vector/string as possible
7. use constexpr as possible
8. inline most common used function
9. Prefer initialization to assignment
