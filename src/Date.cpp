//
// Created by Humphrey De Guzman on 2/17/2021.
//

#include <iostream>
#include "Date.h"

std::vector<std::string> split(const std::string &s, char delim){
    std::vector<std::string> result;
    std::stringstream token(s);
    std::string substring;
    while(getline(token,substring,delim)){
        result.push_back(substring);
    }
    return result;
}

Date::Date(std::string &mmDDyy) {
    std::vector<std::string> stringDate = split(mmDDyy,'/');
    Month = (unsigned int) stoi(stringDate[0]);
    Day = (unsigned int) stoi(stringDate[1]);
    Year = (unsigned int) stoi(stringDate[2]);
    unixTime = 86400*days_from_civil(Year, Month, Day);
}

unsigned long long Date::getUnixTime() const {
    return unixTime;
}
