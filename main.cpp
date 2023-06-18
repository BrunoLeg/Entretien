#include <iostream>
#include "JSONParser.h"

int main() {
    std::string inputText;
    std::string line;

    std::cout << "Enter text (quit to stop) :" << std::endl;

    while (std::getline(std::cin, line)) {
        if (line == "quit") {
            break;
        }

        inputText += line + "\n";
    }

    std::cout << std::endl << "Input text : " << std::endl;
    std::cout << inputText << std::endl;

    JSONParser myParser = JSONParser(inputText);

    if (myParser.isInputValid()) {
        std::cout << "The input is in valid json format";
    }
    else {
        std::cout << "The input format is invalid";
    }

    return 0;
}
