#include <cctype>
#include <iostream>
#include <string>
#include <vector>
int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };
    std::string inputFile;
    std::string outputFile;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            std::cout << "Usage: program_name [options]\n"
                      << "Options:\n"
                      << "  -h, --help           Show this help message\n"
                      << "  --version            Show version information\n"
                      << "  -i <input_file>      Specify input file\n"
                      << "  -o <output_file>     Specify output file\n";
            return 0;
        } else if (arg == "--version") {
            std::cout << "Program version 1.0.0\n";
            return 0;
        } else if (arg == "-i") {
            if (i + 1 < argc) {
                inputFile = argv[++i];
            } else {
                std::cerr << "Error: -i requires an input file argument\n";
                return 1;
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) {
                outputFile = argv[++i];
            } else {
                std::cerr << "Error: -o requires an output file argument\n";
                return 1;
            }
        } else {
            std::cerr << "Warning: Unknown option '" << arg << "' ignored\n";
        }
    }

    std::cout << "Input File: " << (inputFile.empty() ? "None" : inputFile) << "\n";
    std::cout << "Output File: " << (outputFile.empty() ? "None" : outputFile) << "\n";

     


    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}
