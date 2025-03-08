#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        PmergeMe pmergeMe(argc, argv);
        pmergeMe.sortAndDisplay();

    }
    catch(const std::exception& e)
    {
        
        std::cerr << e.what() << '\n';
    }
    
}
