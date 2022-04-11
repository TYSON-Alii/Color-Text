#include <iostream>
#include <Windows.h>
using namespace std;

enum class Color {
    Black = 0x0,
    DarkBlue = 0x1,
    DarkGreen = 0x2,
    DarkCyan = 0x3,
    DarkRed = 0x4,
    DarkMagenta = 0x5,
    DarkYellow = 0x6,
    Grey = 0x7,
    DarkGrey = 0x8,
    Blue = 0x9,
    Green = 0xA,
    Cyan = 0xB,
    Red = 0xC,
    Purple = 0xD,
    Yellow = 0xE,
    White = 0xF
};

class color_string : public string { };
ostream& operator<<(ostream& os, const color_string& v) {
    bool c_time = false;
    string t;
    Color color = Color::White;
    static const auto& hand = GetStdHandle(STD_OUTPUT_HANDLE);
    for (const auto& i : v) {
        if (c_time) {
            if (i >= '0' and i <= '9')
                color = Color(i - '0');
            else if (i >= 'a' and i <= 'f')
                color = Color(10 + i - 'a');
            else {
                os << i;
                continue;
            };
            SetConsoleTextAttribute(hand, (WORD)color);
            c_time = false;
            continue;
        };
        switch (i) {
        case '%':
            c_time = true;
            break;
        default:
            os << i;
        };
    };
    SetConsoleTextAttribute(hand, (WORD)15);
    return os;
};
inline constexpr color_string operator ""_c(const char* str, size_t) { return color_string(str); };
