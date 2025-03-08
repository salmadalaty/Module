#include "PmergeMe.hpp"
#include <cctype> 
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
       
        for (size_t j = 0; j < std::strlen(argv[i]); ++j) {
            if (!std::isdigit(argv[i][j])) {
                std::cerr << "Error: Invalid input. Non-digit characters detected." << std::endl;
                return;
            }
        }

        try {
            int num = std::atoi(argv[i]); 
            if (num < 0) throw std::invalid_argument("Negative number");
            vec.push_back(num);
            deq.push_back(num);
        } catch (std::exception& e) {
            std::cerr << "Error: Invalid input" << std::endl;
            exit(1);
        }
    }
}


std::vector<int> PmergeMe::generateJacobsthalNumbers(int limit) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0); 
    jacobsthal.push_back(1);

    while (true) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > limit) break; 
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}


void PmergeMe::sortPairs(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    std::sort(pairs.begin(), pairs.end());
}


void PmergeMe::insertElement(std::vector<int>& mainChain, int element) {
    std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    mainChain.insert(it, element);
}

void PmergeMe::insertElement(std::deque<int>& mainChain, int element) {
    std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    mainChain.insert(it, element);
}


void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

 
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    sortPairs(pairs);


    std::vector<int> mainChain;
    std::vector<int> pendChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }
    if (arr.size() % 2 != 0) {
        pendChain.push_back(arr.back());
    }


    mergeInsertSortVector(mainChain);

   
    std::vector<int> jacobsthal = generateJacobsthalNumbers(pendChain.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t index = static_cast<size_t>(jacobsthal[i]); 
        if (index >= pendChain.size()) continue; 
        insertElement(mainChain, pendChain[index]);
    }

    arr = mainChain;
}


void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

   
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    sortPairs(pairs);

 
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }
    if (arr.size() % 2 != 0) {
        pendChain.push_back(arr.back());
    }


    mergeInsertSortDeque(mainChain);


    std::vector<int> jacobsthal = generateJacobsthalNumbers(pendChain.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t index = static_cast<size_t>(jacobsthal[i]); 
        if (index >= pendChain.size()) continue;
        insertElement(mainChain, pendChain[index]);
    }

    arr = mainChain;
}

void PmergeMe::sortAndDisplay() {
 
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

  
    clock_t start = clock();
    mergeInsertSortVector(vec);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds


    start = clock();
    mergeInsertSortDeque(deq);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

    
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime << " us" << std::endl;
}