# format_utf8
Single header extension to std::format for char8_t, char16_t, char32_t, u8string and u8string_view.

Notes:
1. Single character values are always intepreted as numeric values.
2. If the unicode character is desired then use the string form with that single character.
3. When compiling for MSVC, ensure compile flag `/utf-8` is used.
4. On godbolt, `<format> + <iostream>` requires c++20; gcc(x86-64 13.3), clang(x86-64 trunk : 19.1.0 compiler errors), and msvc (x64 19.32)
5. On godbolt, `<print>` requires c++23; gcc(x86-64 14.1), clang(x86-64 latest : 19.1.0 missing <print>), and msvc (x64 19.37)


Examples:

```
#include <print>
#include <string>
#include <string_view>
#include "format_utf8.hpp"

int main() {
    char8_t c8 = 0x41;
    char16_t c16 = 0x42;
    char32_t c32 = 0x0001F600;
    std::u8string s8{u8"hello😀"};
    std::u8string_view sv8{s8};
    std::string test{"hello😀"};

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
    std::println("{}", std::u8string{u8"hello😀"});
    std::println("{}", std::u8string_view{u8"hello😀"});
    std::println("");

    return 0;
}
```

```
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include "format_utf8.hpp"

int main() {
    char8_t c8 = 0x41;
    char16_t c16 = 0x42;
    char32_t c32 = 0x0001F600;
    std::u8string s8{u8"hello😀"};
    std::u8string_view sv8{s8};

    std::cout << std::format("Normal char strings\n");
    std::cout << std::format("{}\n", "hello😀");
    std::cout << std::format("{}\n", "\U0001F600");
    std::cout << std::format("\n");

    std::cout << std::format("char8_t\n");
    std::cout << std::format("{}\n", c8);
    std::cout << std::format("{:#x}\n", c8);
    std::cout << std::format("{:05d}\n", c8);
    std::cout << std::format("\n");

    std::cout << std::format("char16_t\n");
    std::cout << std::format("{}\n", c16);
    std::cout << std::format("{:#x}\n", c16);
    std::cout << std::format("{:05d}\n", c16);
    std::cout << std::format("\n");

    std::cout << std::format("char32_t\n");
    std::cout << std::format("{}\n", c32);
    std::cout << std::format("{:#x}\n", c32);
    std::cout << std::format("{:#010x}\n", c32);
    std::cout << std::format("{:d}\n", c32);
    std::cout << std::format("{:08d}\n", c32);
    std::cout << std::format("\n");

    std::cout << std::format("utf-8 strings\n");
    std::cout << std::format("{}\n", u8"hello 😀 there");
    std::cout << std::format("{}\n", s8);
    std::cout << std::format("{}\n", std::u8string{u8"hello😀"});
    std::cout << std::format("{}\n", std::u8string_view{u8"hello😀"});
    std::cout << std::format("\n");

    return 0;
}
```
