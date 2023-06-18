#include <iostream>
#include "JSONParser.h"

JSONParser::JSONParser (const std::string& aInputText)
: mInputText(aInputText), mCurrentIndex(0) {
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
            return parseArray();
        break;

        default:
        break;

    }
    return false;
}

bool JSONParser::parseArray() {
    ++mCurrentIndex;
    skipWhitespace();

    while (getCurrentChar() != ']') {
        skipWhitespace();
        
        if (!parseValue())
            return false;

        skipWhitespace();
        if (getCurrentChar() == ',') {
            ++mCurrentIndex;
        }
        else if (getCurrentChar() != ']') 
            return false;
    }

    ++mCurrentIndex;
    return true;
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
            ++mCurrentIndex;
        }
        else if (getCurrentChar() != '}') 
            return false;
    }

    ++mCurrentIndex;
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
        case 't':
            return parseTrue();
        break;
        case 'f':
            return parseFalse();
        break;
        case 'n':
            return parseNull();
        break;
        case '[':
            return parseArray();
        break;
        default:
            return parseNumber();
        break;
    }
}


bool JSONParser::parseTrue() {
    if( mInputText.substr(mCurrentIndex, 4) == "true") {
        mCurrentIndex += 4;
        return true;
    }
    return false;
}
bool JSONParser::parseFalse() {
    if( mInputText.substr(mCurrentIndex, 4) == "false") {
        mCurrentIndex += 4;
        return true;
    }
    return false;
}
bool JSONParser::parseNull() {
    if( mInputText.substr(mCurrentIndex, 4) == "null") {
        mCurrentIndex += 4;
        return true;
    }
    return false;
}


bool JSONParser::parseNumber() {
    if(!std::isdigit(getCurrentChar())) {
        return false;
    }

    ++mCurrentIndex;
    while (std::isdigit(getCurrentChar()))
        ++mCurrentIndex;

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