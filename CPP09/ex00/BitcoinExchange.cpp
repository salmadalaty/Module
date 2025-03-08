#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    // Read the first line (expected to be a header)
    if (!getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }

    // Check if the first line is the expected header
    std::stringstream ss(line);
    std::string firstWord, separator, secondWord;

    ss >> firstWord >> separator >> secondWord;

    if (firstWord != "date" || separator != "|" || secondWord != "value")
    {
        std::cerr << "Error: missing or invalid header. Expected: 'date | value'" << std::endl;
        return;
    }

    // Process the rest of the file
    while (getline(file, line))
    {
        // Trim spaces and ignore empty lines
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;

        if (!getline(ss, date, '|') || !getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(valueStr))
        {
            std::cerr << "Error: not a valid number." << std::endl;
            continue;
        }

        double value = atof(valueStr.c_str());
        double rate = getExchangeRate(date);

        if (rate != -1)
        {
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 2000 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2)
    {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 28 + leapYear)
            return false;
    }
    else if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    double num = atof(value.c_str());
    return (num >= 0 && num <= 1000);
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.end() || it->first != date)
    {
        if (it == exchangeRates.begin())
        {
            std::cerr << "Error: No valid exchange rate found for date " << date << std::endl;
            return -1;
        }
        --it;
    }

    return it->second;
}

void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open exchange rate database." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (getline(ss, date, ',') && getline(ss, rateStr))
        {
            double rate = atof(rateStr.c_str());
            exchangeRates[date] = rate;
        }
    }

    file.close();
}