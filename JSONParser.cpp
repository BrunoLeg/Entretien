#include <iostream>
#include "JSONParser.h"

JSONParser::JSONParser (const std::string& aInputText)
: mInputText(aInputText) {
}


bool JSONParser::isInputValid() {
    mCurrentIndex = 0;

    skipWhitespace();
    while (mCurrentIndex < mInputText.size())
    {
        char currentChar = mInputText[mCurrentIndex];

        switch (currentChar) {
            case '{':
            break;


        }
        ++mCurrentIndex;

        skipWhitespace();
    }



    return true;
}




void JSONParser::skipWhitespace() {
    char currentChar = mInputText[mCurrentIndex];
    while ( currentChar == ' ' || currentChar == '\n' || currentChar == '\r' || currentChar == '\t')
    {
        ++mCurrentIndex;
        currentChar = mInputText[mCurrentIndex];
    }
}