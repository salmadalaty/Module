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
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!getline(ss, date, '|') || !getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = date.substr(0, date.find_last_not_of(" ") + 1);
        valueStr = valueStr.substr(valueStr.find_first_not_of(" "));

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
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) // extract
        return false;

    if (month < 1 || month > 12 || day < 1 || day > 31)
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
