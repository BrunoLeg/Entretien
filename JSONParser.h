#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>

class JSONParser {
public:
    JSONParser (const std::string& aInputText);

    bool isInputValid();

private:
    void skipWhitespace();





    std::string mInputText;
    int mCurrentIndex;

};

#endif
