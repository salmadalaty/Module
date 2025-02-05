#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream> //String stream for parsing file contents.
#include <cstdlib> // Contains std::atof() for converting strings to floating-point numbers.

class BitcoinExchange
{
private:
    std::map<std::string, double> exchangeRates;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadExchangeRates(const std::string &filename);
    void processInputFile(const std::string &filename);
    double getExchangeRate(const std::string &date) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
};

#endif
