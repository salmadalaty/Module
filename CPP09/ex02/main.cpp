#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: All arguments must be positive integers." << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    PmergeMe sorter;
    sorter.sortAndDisplay(vec, deq);

    return 0;
}