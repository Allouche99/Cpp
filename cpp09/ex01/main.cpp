#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid arguments" << std::endl;
        return 1;
    }

    try
    {
        RPN calculator(argv[1]);
        calculator.calculate();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
