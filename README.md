# clox

### Building

Make sure you have `gcc` installed and then run, defining your own target [list of targets here](https://gcc.gnu.org/install/specific.html):

```
gcc -Wall -target arm64-apple-macos11 -g *.c -o ./out/prog.out
```

then execute the REPL: `./out/prog.out`

#### Examples

1. Declaring variables:

```
var name = "your name";
var number = 10;
var bool = true;

{
    var scoped = 10;
    print scoped; // 10;
}

print scoped; // undefinded variable;
```

2. Operations:

```
"full" + "name"; // fullname
10 + 15; // 25
1 < 0; // false
```

3. Control Flow:

- Conditions:
```
var i = 0;
if (i == 0) {
    print "here";
} else {
    print "there";
}
```

- Loops:

```
while (true) { print "infinity"; }
```

```
var i = 0;
while (i < 10) { print i; i = i + 1; }

for (var i = 0; i < 10; i = i + 1) {
    print i;
}
```


#### Limitation

1. currently only supports 256 in the constants pool

Currently `clox` stores the constants value into an array and uses the index in to load the constant. This index is used by the vm instruction set and the instruction set is built uppon a `uint8_t` array which means, for now, we only can use 256 simultaneosly constants. 

##### String Intern

The `clox` handle strings comparision using a sort of pool of known strings (using a hash set table), when a string is created for the first time it value will be setted in the pool and when the same string needs to be created again this time we go in the pool search and return the reference for it, this way we can keep the `==` comparision working without using the `memcmp(a_chars, b_chars, length) == 0` every time we need to check two strings are equals.