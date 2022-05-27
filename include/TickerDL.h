//
// Created by Humphrey De Guzman on 2/13/2021.
//

#pragma  once
#include <string>

class TickerDL {
public:
    TickerDL(std::string &security, std::string &start, std::string &end);
    void getCSV();
    std::string getTicker();
    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
private:
    std::string ticker; //Security ticker
    std::string endDate; //Last date for price data in unix time
    std::string startDate; //First date for price data in unix time
};


