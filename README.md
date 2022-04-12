### Color-Text
#### Example
```cpp
const auto& code = R"(%8#include %6<iostream>
%9using %9namespace %fstd%7;

%9auto %fmain%7() -> %9int %7{
    %9if %7(%e2 %7+ %e2 %7== %e4%7)
        %fcout %7<< $f2"Hello, World."$07 << %a'\n'%7;
    %creturn %e0%7;
};
)"_c;

auto main() -> int {
    cout << code << '\n';
};
```
![](https://github.com/TYSON-Alii/Color-Text/blob/43f37a4abcc3c770e59305e4111ba96bcd9e7e72/testke.png)
#### Docs
`% + text_color`

`$ + bg_color + text_color`

Colors:
```
Black       %0
DarkBlue    %1
DarkGreen   %2
DarkCyan    %3
DarkRed     %4
DarkMagenta %5
DarkYellow  %6
Grey        %7
DarkGrey    %8
Blue        %9
Green       %a
Cyan        %b
Red         %c
Purple      %d
Yellow      %e
White       %f
```
