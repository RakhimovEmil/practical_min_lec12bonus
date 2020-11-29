#include <iostream>
#include <cassert>
#include <cstdint>
#include "main.hpp"

void test_first() {
    int64_t e = 5, n = 323;
    std::string pattern = "bcd";

    assert(result(e, n, pattern) == pattern);
}

void test_second() {
    int64_t e = 7, n = 33;
    std::string pattern = "e";

    assert(result(e, n, pattern) == pattern);
}

void test_third() {
    int64_t e = 302303, n = 270067;
    std::string pattern = "emi";

    assert(result(e, n, pattern) == pattern);
}

int main() {
    test_first();
    test_second();
    test_third();
    std::cout << "OK";
}
