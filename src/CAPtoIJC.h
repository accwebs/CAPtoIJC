//----------------------------------------------------------------------
// CAPtoIJC - A simple command line tool that calls the GlobalPlatform 
//            library's "CAP to IJC" file conversion function.
//
// Written by Aaron Curley
//----------------------------------------------------------------------

#ifndef CAPtoIJC_H_Included
#define CAPtoIJC_H_Included

//----------------------------------------------------------------------
// includes
#include <string>

//----------------------------------------------------------------------
// program constants
const std::string PROGRAM_NAME("CAPtoIJC");
const std::string PROGRAM_EXECUTABLE("CAPtoIJC.exe");
const std::string PROGRAM_VERSION("1.1");
const std::string PROGRAM_DESCRIPTION(std::string("A simple command line tool that calls the GlobalPlatform library\'s\n") +
                                                  "\"CAP to IJC\" file conversion function.");

//----------------------------------------------------------------------
// prototypes
int main(const int argc, const char** const argv);

//----------------------------------------------------------------------

#endif 
