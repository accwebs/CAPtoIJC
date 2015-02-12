//----------------------------------------------------------------------
// See comments in CAPtoIJC.h
//----------------------------------------------------------------------

#include "CAPtoIJC.h"

//----------------------------------------------------------------------

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <locale>

// codecvt_utf8 not supported on GCC
#ifndef __GNUC__
#include <codecvt>
#endif

#include <globalplatform/globalplatform.h>
// workaround to allow stl includes after globalplatform.h includes
#undef max
#undef min

//----------------------------------------------------------------------
// fire off main
int main(const int argc, const char** const argv){
    int retcode;

    // if not 2 command line arguments
    if (argc != 3){
        std::cout << PROGRAM_NAME << "  -  " << PROGRAM_VERSION << std::endl;
        std::cout << PROGRAM_DESCRIPTION << std::endl;
        std::cout << std::endl;
        std::cout << "Usage:  " << PROGRAM_EXECUTABLE << " <CAP file (input)> <IJC file (output)>" << std::endl;
        std::cout << std::endl;
        retcode = 1;
    }else{
        // print program name and version
        std::cout << PROGRAM_NAME << "  -  " << PROGRAM_VERSION << "\n" << std::endl;

        // convert input filename to string
        const std::string input_filename(argv[1]);
        
        // convert output filename to string
        const std::string output_filename(argv[2]);
        
        std::cout << "Input file:  " << input_filename  << "\n"
                  << "Output file: " << output_filename << "\n" << std::endl;

        // codecvt_utf8 not supported on GCC, but don't worry:  libglobalplatform uses chars instead of wchars on Linux!
        #ifdef __GNUC__

        // copy strings without altering them
        std::string input_filename_wide(input_filename);
        std::string output_filename_wide(output_filename);

        #else
        
        typedef std::codecvt_utf8<wchar_t> convert_type;
        std::wstring_convert<convert_type, wchar_t> converter;
                
        // convert filenames from UTF8 to UCS2
        std::wstring input_filename_wide = converter.from_bytes(input_filename);
        std::wstring output_filename_wide = converter.from_bytes(output_filename);
       
        #endif

        try{
            // call GlobalPlatform API to convert CAP to IJC file
            OPGP_ERROR_STATUS status;
            status = OPGP_cap_to_ijc(const_cast<TCHAR*>(input_filename_wide.c_str()), const_cast<TCHAR*>(output_filename_wide.c_str()));
            if (OPGP_ERROR_CHECK(status) != 0){
                
                // codecvt_utf8 not supported on GCC, but don't worry:  libglobalplatform uses chars instead of wchars on Linux!
                #ifdef __GNUC__

                // copy strings without altering them
                std::string utf8_name(status.errorMessage);

                #else

                // convert exception string from UCS2 to UTF8
                std::string utf8_name = converter.to_bytes(status.errorMessage);
                
                #endif
                
                // throw exception
                throw std::runtime_error(std::string("OPGP_cap_to_ijc(): ") + utf8_name);
            }

            std::cout << "Conversion complete!\n" << std::endl;
            retcode = 0;
            
        // error converting
        }catch(std::runtime_error& ex){
            std::cout << "Exception thrown while converting CAP file: " << ex.what();
            std::cout << std::endl;

            retcode = 50;
        }catch(...){
            std::cout << "Unknown exception thrown while converting CAP file.";
            std::cout << std::endl;

            retcode = 50;
        } 
    } // endif arguments are correct

    return retcode;
}

//----------------------------------------------------------------------
