#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        bob.increment();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrement();
        std::cout << "After decrement: " << bob << std::endl;

        
        Bureaucrat alice("Alice", 0);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
   
        Bureaucrat john("John", 151);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
