#include <iostream>
#include <chrono>
#include "TickerDL.h"
#include "Date.h"

int main(int argc, char *argv[]){

    if(argc > 4 || argc < 2){
        std::cerr << "Error 0: Invalid number of arguments\n";
        return -1;
    }

    time_t now = time(nullptr);

    //Used for our TickerDl object constructor
    std::string Security;
    std::string startDate;
    std::string endDate;

    Security = argv[1];

    switch(argc){

        case 2: //Input looks like -  YahooFinanceAPI "AAPL"
        {
            std::cout << "Case 1: Retrieving 5 year daily data for " << argv[1] << ".\n ";

            startDate = std::to_string((unsigned long)now-158112000); //Unix time of exactly 5 years before the command is run
            endDate = std::to_string((unsigned long)now); //Unix time of when the command is run

            TickerDL security(Security,startDate,endDate); //Download object creation

            security.getCSV(); //Method to attempt to download our desired csv from Yahoo Finance

            break;
        }

        case 3: //Input looks like - YahooFinanceAPI "AAPL" 2/15/2020
        {
            std::cout << "Case 2: Retrieving daily data for " << argv[1] << " from the date " << argv[2] << " to today.\n";
            std::string date1 = argv[2];
            Date dateObj(date1); //Date object to get the unix time from string
            startDate = std::to_string(dateObj.getUnixTime()); //Unix time from our string
            endDate = std::to_string((unsigned long)now); //Unix time of when the command is run

            TickerDL security(Security,startDate,endDate); //Download object creation

            security.getCSV(); //Method to attempt to download our desired csv from Yahoo Finance
            break;
        }

        case 4: //Input looks like - YahooFinanceAPI "AAPL" 2/15/2020 9/27/2020
        {
            std::cout << "Case 3: Retrieving daily data for " << argv[1] << " from the date range " << argv[2] << " to " << argv[3] << ".\n";
            std::string date1 = argv[2]; //First date in our range for our data
            std::string date2 = argv[3]; //Second date in our range for our data
            Date dateObj1(date1); //First chronological date object to get the unix time from string
            Date dateObj2(date2); //Second chronological date object to get the unix time from string
            startDate = std::to_string(dateObj1.getUnixTime()); //Unix time from our string
            endDate = std::to_string(dateObj2.getUnixTime()); //Unix time of when the command is run

            TickerDL security(Security,startDate,endDate); //Download object creation

            security.getCSV(); //Method to attempt to download our desired csv from Yahoo Finance
            break;
        }
        default:
            std::cout<< "Please enter a valid ticker, dates can be entered optionally in the form mm/dd/yyyy\n";

    }
    return 0;
}
