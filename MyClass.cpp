#include <iostream>
#include "MyClass.h"

void MyClass::printMap(const std::map<int, std::string>& myMap) {
    for (std::map<int, std::string>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}