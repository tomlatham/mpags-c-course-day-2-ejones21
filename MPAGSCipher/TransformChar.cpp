// Standard library includes
#include <string>
#include <cctype>

// Our project headers
#include "TransformChar.hpp"

std::string transformChar(const char inputChar)
{
  /* Take a user input and output a string of capitalised letters

     inputChar: user input
     return: string of transliterated characters */
  std::string inputText {""};

  // Uppercase alphabetic characters
  if (std::isalpha(inputChar)) {
      inputText += std::toupper(inputChar);
    }

  // Transliterate digits to English words
  switch (inputChar) {
      case '0':
	inputText += "ZERO";
	break;
      case '1':
	inputText += "ONE";
	break;
      case '2':
	inputText += "TWO";
	break;
      case '3':
	inputText += "THREE";
	break;
      case '4':
	inputText += "FOUR";
	break;
      case '5':
	inputText += "FIVE";
	break;
      case '6':
	inputText += "SIX";
	break;
      case '7':
	inputText += "SEVEN";
	break;
      case '8':
	inputText += "EIGHT";
	break;
      case '9':
	inputText += "NINE";
	break;
    }

    return inputText;
    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
}
