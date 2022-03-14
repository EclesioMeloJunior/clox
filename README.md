# clox

#### Limitation

1. currently only supports 256 in the constants pool

Currently `clox` stores the constants value into an array and uses the index in to load the constant. This index is used by the vm instruction set and the instruction set is built uppon a `uint8_t` array which means, for now, we only can use 256 simultaneosly constants. 