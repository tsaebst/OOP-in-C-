#pragma once
#include "String.h"
#include "Task10.h"
#include <stdexcept>
#include <string>
#include <optional>

template <int n>
class ShortString 
{
private:
    String _string; // рядок,  обмежений до довжини n
public:
    // Конструктор
    ShortString() : _string() {}

    // Конструктор С-рядка
    ShortString(const char* str) 
    {
        if (std::strlen(str) <= n) 
        {
            _string = str;
        }
        else 
        {
            // якщо рядок довший за n, обрізаємо його
            char temp[n + 1];
            strncpy_s(temp, sizeof(temp), str, n);
            temp[n] = '\0'; // правильне завершення рядка
            _string = temp;
        }
    }

    // Конструктор std string
    ShortString(const std::string& value)
    { // NOLINT(*-explicit-constructor)
        if (value.length() > n)
        {
            throw BadShortString("String length must not exceed " + std::to_string(n) + ", got \"" + value + "\"");
        }
        _string = value;
    }

    // Утиліта виводу
    friend std::ostream& operator<<(std::ostream& os, const ShortString& ss) 
    {
        os << ss._string;
        return os;
    }

    //Конкатенація +=
    void operator+=(const std::string& other)
    {
        properLength(other);
        _string += other;
    }

    //Конкатенація +
    ShortString operator+(const std::string& other) 
    {
        properLength(other);
        return ShortString<_string.length() + other.length()>(_string + other);
    }


private:
    // Перевірка, чи не перевищує загальна довжина n
    void properLength(const std::string& other) const
    {
        if (_string.length() + other.length() > n) 
        {
            throw BadShortString(("The length is over limit." ), other.length());
        }
    }
};
