#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange btc;
    btc.loadExchangeRates("data.csv");
    btc.processInputFile(argv[1]);

    return EXIT_SUCCESS;
}
