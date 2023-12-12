#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

enum State {
    Normal,
    SingleLineComment,
    MultiLineComment,
    StringLiteral,
    PreprocessorDirective
};

std::string manipulateCode(const std::string& sourceCode) {
    std::string result;
    State processingState = Normal;

    for (size_t i = 0; i < sourceCode.size(); ++i) {
        char currentChar = sourceCode[i];

        switch (processingState) {
            case Normal:
                if (currentChar == '/') {
                    if (i + 1 < sourceCode.size() && sourceCode[i + 1] == '/') {
                        processingState = SingleLineComment;
                        ++i;
                    } else if (i + 1 < sourceCode.size() && sourceCode[i + 1] == '*') {
                        processingState = MultiLineComment;
                        ++i;
                    }
                } else if (currentChar == '"') {
                    processingState = StringLiteral;
                } else if (currentChar == '#') {
                    processingState = PreprocessorDirective;
                } else if (!std::isspace(currentChar)) {
                    result += currentChar;
                }
                break;

            case SingleLineComment:
                if (currentChar == '\n') {
                    processingState = Normal;
                }
                break;

            case MultiLineComment:
                if (currentChar == '*' && i + 1 < sourceCode.size() && sourceCode[i + 1] == '/') {
                    processingState = Normal;
                    ++i;
                }
                break;

            case StringLiteral:
                result += currentChar;
                if (currentChar == '"' && (i == 0 || sourceCode[i - 1] != '\\')) {
                    processingState = Normal;
                }
                break;

            case PreprocessorDirective:
                if (currentChar == '\n') {
                    processingState = Normal;
                }
                break;
        }
    }

    return result;
}

int main() {
    std::ifstream inputFile("source.cpp");
    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string inputCode = buffer.str();

    std::string minifiedCode = manipulateCode(inputCode);

    std::ofstream outputFile("output.cpp");
    outputFile << minifiedCode;

    return 0;
}
