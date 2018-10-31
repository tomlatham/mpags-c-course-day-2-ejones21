#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>
#include <cctype>

// Do the encryption/decryption
std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encryption);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP
