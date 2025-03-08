#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return 1;
    }

    PmergeMe sorter(argc, argv);
    sorter.sortAndDisplay();

    return 0;
}