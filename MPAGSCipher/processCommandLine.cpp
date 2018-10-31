#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

//! Process the command line arguments
bool processCommandLine(
			const std::vector<std::string>& args, 
			bool& helpRequested,
			bool& versionRequested, 
			std::string& inputFileName, 
			std::string& outputFileName,
			bool& doencrypt,
		        size_t& thekey)
{

  // Add a typedef that assigns another name for the given type for clarity

  typedef std::vector<std::string>::size_type size_type;
  const size_type nargs {args.size()};


  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nargs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
      break;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
      break;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
	// return true to indicate failure
	return true;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFileName = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
	// return true to indicate failure
	return true;
      }
      else {
	// Got filename, so assign value and advance past it
	outputFileName = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-e"){
        // This is asking for encryption
	doencrypt = true;
    }
    else if (args[i] == "-d"){
	// This is asking for decryption
        doencrypt = false;
    }
    else if (args[i] == "-k"){
      // Handle cipher key
      // Next element is cipher key unless -k is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -k requires a key argument" << std::endl;
	// return true to indicate failure
	return true;
      }
      else{
	// Got a cipher key so assign a value and advance past it
	if ( args[i+1].front() == '-' ) {
	  std::cerr << "[error] -k requires a positive integer as the key argument" << std::endl;
	  // return true to indicate failure
	  return true;
	}
	thekey = std::stoul(args[i+1]);
	++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return true to
      // indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return true;
    }
  }

  // return false to indicate no problems encountered
  return false;
}
