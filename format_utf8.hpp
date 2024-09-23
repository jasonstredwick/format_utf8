// Copyright (C) 2024 Jason Stredwick
// MIT License

#pragma once


#include <algorithm>
#include <bit>
#include <cstdint>
#include <format>
#include <string>
#include <string_view>


template <>
struct std::formatter<char8_t> : public std::formatter<uint8_t> {
    auto format(const char8_t& c, std::format_context& ctx) const {
        return std::formatter<uint8_t>::format(std::bit_cast<char8_t, uint8_t>(c), ctx);
    }
};


template <>
struct std::formatter<char16_t> : public std::formatter<uint16_t> {
    auto format(const char16_t& c, std::format_context& ctx) const {
        return std::formatter<uint16_t>::format(std::bit_cast<char16_t, uint16_t>(c), ctx);
    }
};


template <>
struct std::formatter<char32_t> : public std::formatter<uint32_t> {
    auto format(const char32_t& c, std::format_context& ctx) const {
        return std::formatter<uint32_t>::format(std::bit_cast<char32_t, uint32_t>(c), ctx);
    }
};


template <size_t N>
struct std::formatter<char8_t[N], char> : std::formatter<std::string_view> {
    auto format(const char8_t(&input)[N], std::format_context& ctx) const {
        std::ranges::transform(input, ctx.out(), [](auto c) { return static_cast<char>(c); });
        return ctx.out();
    }
};


template <>
struct std::formatter<std::u8string> : public std::formatter<std::string> {
    auto format(const std::u8string& input, std::format_context& ctx) const {
        std::ranges::transform(input, ctx.out(), [](auto c) { return static_cast<char>(c); });
        return ctx.out();
    }
};


template <>
struct std::formatter<std::u8string_view> : public std::formatter<std::string_view> {
    auto format(const std::u8string_view& input, std::format_context& ctx) const {
        std::ranges::transform(input, ctx.out(), [](auto c) { return static_cast<char>(c); });
        return ctx.out();
    }
};
