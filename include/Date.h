//
// Created by Humphrey De Guzman on 2/17/2021.
//

#pragma once
#include <string>
#include <chrono>
#include <vector>
#include <sstream>

class Date {
public:
    explicit Date(std::string &mmDDyy);
    unsigned long long getUnixTime() const;
private:
    unsigned int Year;
    unsigned int Month;
    unsigned int Day;
    unsigned long long unixTime;
};


//Low level algorithm to find the number of days between a date and January 1 1970
//Taken from https://howardhinnant.github.io/date_algorithms.html#Introduction
template <class Int>
constexpr
Int
days_from_civil(Int y, unsigned m, unsigned d) noexcept
{
    static_assert(std::numeric_limits<unsigned>::digits >= 18,
             "This algorithm has not been ported to a 16 bit unsigned integer");
    static_assert(std::numeric_limits<Int>::digits >= 20,
             "This algorithm has not been ported to a 16 bit signed integer");
    y -= m <= 2;
    const Int era = (y >= 0 ? y : y-399) / 400;
    const auto yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d-1;  // [0, 365]
    const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;         // [0, 146096]
    return era * 146097 + static_cast<Int>(doe) - 719468;
}
