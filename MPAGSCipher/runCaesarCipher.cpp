// Include standard libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>


std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encryption) 
/*Encyrpt or decrypt an input text
  std::string& inputText: the input that needs encrypting or decrypting
  const size_t key: the shift to apply to the input string
  const bool encryption: asking whether we want to input or decrypt

  return: string of the encrypted/decrypted text */

{
  // Create alphabet container and output string
  const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  const size_t alphabetSize { alphabet.size() };
  
  std::string outputEncrypt{""};

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key % alphabetSize };

  // Loop over the input text
  for (const char& element : inputText){
    // Loop through the alphabet and find a match for the input character
    for(size_t i{0}; i<alphabet.size(); ++i){
      if (alphabet[i]==element){
	/* if the alphabet character matches the input character, either add or
	   subtract the key from the position in the alphabet vector, depending
	   on whether encrypting or decrypting, and then retrieve the new 
	   alphabet character and add it to the output */
	if(encryption){
	  size_t j { (i+truncatedKey) % alphabetSize };
	  outputEncrypt += alphabet[j];
	}
	else {
	  size_t k { (i+alphabetSize-truncatedKey) % alphabetSize };
	  outputEncrypt += alphabet[k];
	}
      }
    }
  }
  return outputEncrypt;
}
