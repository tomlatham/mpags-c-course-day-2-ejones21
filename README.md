# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 4.8 or better, Clang 3.4 or better are recommended) and `make`
on a UNIX operating system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window.
To compile the code, navigate to the mpags-cipher2.build folder and type make.
To run the code:
```
$ ./mpags-cipher
```
The options to add are:
    to specify an input file: -i "input file"
    to specify and output file: -o "output file" 
    to choose to encrypt: -e
    to choose to decrypt: -d
    to specify the cipher key: -k "number to shift"
The user must choose to encrypt or decrypt and specify the key.
If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
If no output file is specified, `mpags-cipher` will display the output on the screen.

To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are output after CTRL-D.


# Source Code Layout
Under this directory, the code and associated files are organised as
follows:
```
$ tree
├── cipher.txt
├── CMakeLists.txt
├── LICENSE
├── MPAGSCipher
│   ├── processCommandLine.cpp
│   ├── processCommandLine.hpp
│   ├── TransformChar.cpp
│   ├── TransformChar.hpp
├── mpags-cipher.cpp
└── README.md

1 directory, 9 files
```
# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.
