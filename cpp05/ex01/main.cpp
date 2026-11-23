
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try { Form f("Bad", 0, 50); }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    try { Form f("Bad", 50, 151); }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    try {
        Bureaucrat boss("Boss", 5);
        Bureaucrat noob("Noob", 100);
        Form f("Form42", 50, 20);

        std::cout << f << std::endl;
        noob.signForm(f);   // échec : grade trop bas
        boss.signForm(f);   // succès
        std::cout << f << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    return 0;
}