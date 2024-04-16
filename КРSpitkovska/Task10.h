#pragma once
#include "Task8.h"
//Параматеризований клас обробки помилок
template <int n>
class BadShortString {
private:
    const std::string _error; 
    const size_t _index;     

public:
    BadShortString(std::string error = " ", const size_t index = 0) : _error(error), _index(index) {}

    ~BadShortString() {}

    // повідомлення про помилку
    void error() const
    {
        std::cerr << _error << '\n';
        if (_index != 0)
            std::cerr << ' ' << _index <<  '\n';
    }
};
