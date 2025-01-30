#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
      
        Bureaucrat alice("Alice", 2);

        Form taxForm("Tax Form", 20, 30);
        alice.signForm(taxForm);  // Alice signs it

     
        std::cout << taxForm << std::endl;
       
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
