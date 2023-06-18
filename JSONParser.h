#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>

class JSONParser {
public:
    JSONParser (const std::string& aInputText);

    bool isInputValid();

private:
    bool parseArray();
    
    bool parseObject();
    bool parseString();
    bool parseValue();

    bool parseTrue();
    bool parseFalse();
    bool parseNull();
    bool parseNumber();

    void skipWhitespace();
    char getCurrentChar();

    std::string mInputText;
    int mCurrentIndex;

};

#endif
