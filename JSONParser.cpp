#include <iostream>
#include "JSONParser.h"

JSONParser::JSONParser (const std::string& aInputText)
: mInputText(aInputText) {
}


bool JSONParser::isInputValid() {
    mCurrentIndex = 0;

    skipWhitespace();
    if(getCurrentChar() != '{' && getCurrentChar() != '[')
        return false;

    switch (getCurrentChar()) {
        case '{':
            return parseObject();
        break;
        case '[':
        break;

        default:
        break;

    }

}

bool JSONParser::parseObject() {
    ++mCurrentIndex;
    skipWhitespace();

    while (getCurrentChar() != '}') {
        skipWhitespace();
        if (!parseString()) 
            return false;

        if (getCurrentChar()  != ':')
            return false;
        
        ++mCurrentIndex;
        skipWhitespace();
        if (!parseValue())
            return false;

        skipWhitespace();
        if (getCurrentChar() == ',') {
            mCurrentIndex++;
        }
        else if (getCurrentChar() != '}') 
            return false;
    }

    return true;
}

bool JSONParser::parseString() {
    if (getCurrentChar() != '\"')
        return false;

    ++mCurrentIndex;
    while (getCurrentChar() != '\"') {
        ++mCurrentIndex;
        if (mCurrentIndex >= mInputText.size())
            return false;
    }

    ++mCurrentIndex;
    return true;
}

bool JSONParser::parseValue() {
    skipWhitespace();

    switch (getCurrentChar()) {
        case '{':
            return parseObject();
        break;
        case '\"':
            return parseString();
        break;

        default:
            return parseNumber();
        break;
    }
}

bool JSONParser::parseNumber() {

    return true;
}



void JSONParser::skipWhitespace() {
    while (mCurrentIndex < mInputText.size() && ( getCurrentChar() == ' ' || getCurrentChar() == '\n' || getCurrentChar() == '\r' || getCurrentChar() == '\t'))
    {
        ++mCurrentIndex;
    }
}

char JSONParser::getCurrentChar() {
    return mInputText[mCurrentIndex];
}