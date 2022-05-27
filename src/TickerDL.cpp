//
// Created by Humphrey De Guzman on 2/13/2021.
//

#include "TickerDL.h"
#include <curl/curl.h>
#include <string>
#include <iostream>

//Constructor for our security downloader object
TickerDL::TickerDL(std::string &security, std::string &start, std::string &end)
    :ticker{security},
    startDate{start},
    endDate{end}
{
}

//Method to download daily data of our security from Yahoo! Finance
void TickerDL::getCSV() {

    //Curl object
    CURL *cURL;

    //Strings for data access and directory, needs to be converted to cstring
    std::string dLink = "https://query1.finance.yahoo.com/v7/finance/download/" + ticker + "?period1=" + startDate + "&period2=" + endDate + "&interval=1d&events=history";
    std::string csvDIR = "../IO/" + ticker + ".csv";

    //File object for curl to store csv
    FILE *csvFile;

    //Used to check if security data acquisition was possible
    int result;

    //CURL library set up
    cURL = curl_easy_init();
    csvFile = fopen(csvDIR.c_str(),"wb"); //This sets up where we download our file

    curl_easy_setopt(cURL, CURLOPT_URL, dLink.c_str()); //URL where we download the csv file
    curl_easy_setopt(cURL, CURLOPT_CAINFO, "../chickenpermissions/cacert.pem"); //Certificates used to verify our dl
    curl_easy_setopt(cURL, CURLOPT_WRITEFUNCTION, write_data); //Used for writing our csv
    curl_easy_setopt(cURL, CURLOPT_WRITEDATA, csvFile); //Chooses a directory in which our file is written to
    curl_easy_setopt(cURL, CURLOPT_SSL_VERIFYPEER, 1); //This needs to change as we are currently not verifying anything!
    curl_easy_setopt(cURL,CURLOPT_SSL_VERIFYHOST,2); //This is needed to make sure that the host is what we are looking for
    curl_easy_setopt(cURL,CURLOPT_FAILONERROR, 1); //We simply fail if there is an error during the process

    result = curl_easy_perform(cURL); //We use this to let our user know the result of the operation
    if (result != 0) {
        std::cout << "\nError #" << result << "\tTicker '" << ticker << "' does not exist!\n";
    } else {
        std::cout << "\nDownloaded " << ticker << ".csv successfully!\n";
    }
    curl_easy_cleanup(cURL); //Used for closing our CURL object
    fclose(csvFile); //We close the directory we've created

}

//Returns the ticker of the security
std::string TickerDL::getTicker() {
    return ticker;
}

//Used in our CURL writing, taken from https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c
size_t TickerDL::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
