#include <iostream>
#include "MyClass.h"

int main() {
    std::map<int, std::string> myMap;

    myMap[1] = "Value1";
    myMap[2] = "Value2";

    MyClass::printMap(myMap);

    return 0;
}
