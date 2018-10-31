// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"

// For std::isalpha and std::isupper
#include <cctype>

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  bool encrypt {true};
  size_t key {0};
  if(processCommandLine(
			cmdLineArgs, 
			helpRequested,
			versionRequested, 
			inputFile, 
			outputFile,
			encrypt,
			key))
    {return 1;}

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -k KEY           Specify the cipher KEY\n"
      << "                   A null key, i.e. no encryption, is used if not supplied\n\n"
      << "  -e               Will use the cipher to encrypt the input text (default behaviour)\n\n"
      << "  -d               Will use the cipher to decrypt the input text\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.2.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string outputText {""};
  std::string encryptedCode{""};

  // Read in user input from stdin/file
  if (!inputFile.empty()) {
    std::ifstream in_file{inputFile};
    bool ok_to_read = in_file.good();
    if(ok_to_read){
      while(in_file>>inputChar)
      {
	outputText += transformChar(inputChar);
      }
    }
    else{
      // Loop over each character from user input
      // (until Return then CTRL-D (EOF) pressed)
      std::cerr << "[error] failed to create istream on file '" << inputFile << "'" << std::endl;
      std::cout<<"Type the input and press ctrl-D to exit"<<std::endl;
      while(std::cin >> inputChar)
      {
	outputText += transformChar(inputChar);
      }
    }
  } else {
      // Loop over each character from user input
      // (until Return then CTRL-D (EOF) pressed)
      std::cout<<"Type the input and press ctrl-D to exit"<<std::endl;
      while(std::cin >> inputChar)
      {
	outputText += transformChar(inputChar);
      }
  }

  // Run the encryption code 
  encryptedCode = runCaesarCipher(outputText, key, encrypt);


  // Output the transliterated text
  if (!outputFile.empty()) {
    std::ofstream out_file {outputFile};
    bool ok_to_write = out_file.good();

    if(ok_to_write){
      out_file <<encryptedCode<< std::endl;
    }
    else{  
      std::cerr << "[error] failed to open file for output: '" << outputFile << "'" << std::endl;
      std::cout << encryptedCode << std::endl;
    }
  } else {
      std::cout << encryptedCode << std::endl;
  }
  
  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}


