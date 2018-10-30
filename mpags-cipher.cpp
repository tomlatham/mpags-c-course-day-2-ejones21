// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"

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
  if(processCommandLine(
			cmdLineArgs, 
			helpRequested,
			versionRequested, 
			inputFile, 
			outputFile))
    {return 1;}

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string outputText {""};

  std::ifstream in_file{inputFile};
  bool ok_to_read = in_file.good();

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "[warning] input from file ('"
              << inputFile
              << "') not implemented yet, using stdin\n";
  }
  if(ok_to_read){
    while(in_file>>inputChar)
      {
	outputText += transformChar(inputChar);
      }
  }
  else{
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    std::cout<<"Type the input and press ctrl-D to exit"<<std::endl;
      while(std::cin >> inputChar)
	{
	  outputText += transformChar(inputChar);
	}
  }

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout << "[warning] output to file ('"
              << outputFile
              << "') not implemented yet, using stdout\n";
  }

  std::ofstream out_file {outputFile};
  bool ok_to_write = out_file.good();

  if(ok_to_write){
    out_file <<outputText<< std::endl;
  }
  else{  
    std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}


