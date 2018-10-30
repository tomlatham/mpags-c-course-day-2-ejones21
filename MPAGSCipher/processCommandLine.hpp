#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

//! Process the command line arguments
bool processCommandLine(
			const std::vector<std::string>& argsin, 
			bool& helpRequestedin,
			bool& versionRequestedin, 
			std::string& inputFileNamein, 
			std::string& outputFileNamein);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
