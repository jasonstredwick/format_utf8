# format_utf8
Single header extension to std::format for char8_t, u8string and u8string_view.  Also threw in conversion 
of char16_t and char32_t to their unsigned equivalents.

Notes:
1. When compiling for MSVC on godbolt.org, emoji has issues displaying from u8 strings but not normal strings.
   compiler complains about code page.  I did not have the code page issue on my local machine.
2. This code was compiled with gcc, clang, and msvc using std c++23.


Examples:

```
#include <print>
#include <string>
#include <string_view>
#include "format_utf8.hpp"

char8_t c8 = 0x41;
char16_t c16 = 0x42;
char32_t c32 = 0x0001F600;
std::u8string s8{u8"hello😀"};
std::u8string_view sv8{s8};

std::println("Normal char strings");
std::println("{}", "hello😀");
std::println("{}", "\U0001F600");
std::println("");

std::println("char8_t");
std::println("{}", c8);
std::println("{:#x}", c8);
std::println("{:05d}", c8);
std::println("");

std::println("char16_t");
std::println("{}", c16);
std::println("{:#x}", c16);
std::println("{:05d}", c16);
std::println("");

std::println("char32_t");
std::println("{}", c32);
std::println("{:#x}", c32);
std::println("{:#010x}", c32);
std::println("{:d}", c32);
std::println("{:08d}", c32);
std::println("");

std::println("utf-8 strings");
std::println("{}", u8"hello 😀 there");
std::println("{}", s8);
std::println("{}", std::u8string{"hello😀"});
std::println("{}", std::u8string_view{"hello😀"});
std::println("");
```
