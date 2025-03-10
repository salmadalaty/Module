#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream> // String stream for parsing file contents.
#include <cstdlib> // Contains std::atof() for converting strings to floating-point numbers.

class BitcoinExchange
{
private:
    std::map<std::string, double> exchangeRates;

public:
    // Orthodox Canonical Form
    BitcoinExchange();                               // Default Constructor
    BitcoinExchange(const BitcoinExchange &other);  // Copy Constructor
    BitcoinExchange &operator=(const BitcoinExchange &other); // Copy Assignment Operator
    ~BitcoinExchange();                              // Destructor

    void loadExchangeRates(const std::string &filename);
    void processInputFile(const std::string &filename);
    double getExchangeRate(const std::string &date) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
};

#endif // BITCOINEXCHANGE_HPP
