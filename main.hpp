#pragma once
#include <iostream>
#include <algorithm>

inline int64_t gcdex(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int64_t x1, y1;
    int64_t d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

inline int64_t invmod(int64_t a, int64_t b) {
    int64_t x, y;
    gcdex(a, b, x, y);
    x = (x % b + b) % b;
    return x;
}

inline int64_t gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

inline int64_t phi(int64_t n) {
    int64_t result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

inline int64_t modexp(int64_t x, int64_t y, int64_t N) {
    if (y == 0) return 1;
    int64_t z = modexp(x, y / 2, N);
    if (y % 2 == 0)
        return (z*z) % N;
    else
        return (x*z*z) % N;
}

std::string result(int64_t e, int64_t n, std::string s) {
    uint64_t m = 0, help[s.size()];
    for (std::size_t i = 0; i < s.size(); ++i) {
        int lol = static_cast<uint64_t>(s[i] - 'a'), c = 0;
        while (lol > 0) {
            c++;
            lol /= 10;
        }
        m *= pow(10, c);
        help[i] = c;
        m += static_cast<uint64_t>(s[i] - 'a');
    }
    int64_t c = modexp(m, e, n);
    int64_t d = invmod(e, phi(n));
    int64_t ans = modexp(c, d, n);
    std::string ans_ = "";
    for (std::size_t i = s.size() - 1; i >= 0; --i) {
        int kek = 1, cur = 0;
        while (help[i] > 0) {
            cur *= kek;
            cur += ans % 10;
            kek *= 10;
            ans /= 10;
            help[i]--;
        }
        int cur_ = 0;
        while(cur) { // переворот числа
            cur_ = cur_ * 10 + cur % 10;
            cur /= 10;
        }
        ans_ += cur_ + 'a';
        if (i == 0) {
            break;
        }
    }
    reverse(ans_.begin(), ans_.end());
    return ans_;
}
