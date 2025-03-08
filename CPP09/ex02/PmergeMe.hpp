#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;

    void mergeInsertSortVector(std::vector<int> &arr);
    void mergeInsertSortDeque(std::deque<int> &arr);

    void sortPairs(std::vector<std::pair<int, int> > &pairs);
    void insertElement(std::vector<int> &mainChain, int element);
    void insertElement(std::deque<int> &mainChain, int element);

    std::vector<int> generateJacobsthalNumbers(int limit);


public:
template <typename T>
int binarySearchInsertPosition(const T &arr, int target);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    PmergeMe(int argc, char **argv);
    void sortAndDisplay();
    class InvalidInputException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Invalid input";
        }
    };  
    
};

#endif