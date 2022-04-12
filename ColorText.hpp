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
    bool c_time = false, w_time = false, b_slash = false;
    string t;
    Color color = Color::White, bg = Color::Black;
    static const auto& hand = GetStdHandle(STD_OUTPUT_HANDLE);
    for (const auto& i : v) {
        if (c_time) {
            if (i >= '0' and i <= '9') {
                if (w_time) {
                    bg = Color(i - '0');
                    w_time = false;
                }
                else {
                    color = Color(i - '0');
                    c_time = false;
                }
            }
            else if (i >= 'a' and i <= 'f') {
                if (w_time) {
                    bg = Color(10 + i - 'a');
                    w_time = false;
                }
                else {
                    color = Color(10 + i - 'a');
                    c_time = false;
                }
            }
            else {
                os << i;
                c_time = false;
                continue;
            };
            SetConsoleTextAttribute(hand, (WORD)bg * 16 + (WORD)color);
            continue;
        }
        switch (i) {
        case '\\':
            b_slash = !b_slash;
            break;
        case '%':
            if (!b_slash)
                c_time = true;
            break;
        case '$':
            if (!b_slash)
                w_time = c_time = true;
            break;
        default:
            b_slash = false;
            os << i;
        };
    };
    SetConsoleTextAttribute(hand, (WORD)15);
    return os;
};
inline constexpr color_string operator ""_c(const char* str, size_t) { return color_string(str); };
