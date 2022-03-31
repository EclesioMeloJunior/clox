# clox

#### Limitation

1. currently only supports 256 in the constants pool

Currently `clox` stores the constants value into an array and uses the index in to load the constant. This index is used by the vm instruction set and the instruction set is built uppon a `uint8_t` array which means, for now, we only can use 256 simultaneosly constants. 

##### String Intern

The `clox` handle strings comparision using a sort of pool of known strings (using a hash set table), when a string is created for the first time it value will be setted in the pool and when the same string needs to be created again this time we go in the pool search and return the reference for it, this way we can keep the `==` comparision working without using the `memcmp(a_chars, b_chars, length) == 0` every time we need to check two strings are equals.