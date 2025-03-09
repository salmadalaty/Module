#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>

class PmergeMe
{
public:
    // Constructor and Destructor
    PmergeMe();
    ~PmergeMe();

    // Public methods
    void sortAndDisplay(std::vector<int> &vec, std::deque<int> &deq);

private:
    // Helper methods
    template <typename Container>
    void mergeSort(Container &container, int left, int right);

    template <typename Container>
    void merge(Container &container, int left, int mid, int right);

    std::vector<int> generateJacobsthalNumbers(int n);

    template <typename Container>
    void binarySearchAndInsert(Container &data, int value);

    template <typename Container>
    void fordJohnsonSort(Container &container);

    // Display methods
    void displaySequence(const std::string &message, const std::vector<int> &sequence);
    void displayTime(const std::string &containerType, size_t size, double time);
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