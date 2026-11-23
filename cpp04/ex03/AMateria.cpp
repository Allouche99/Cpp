#include "AMateria.hpp"
#include "ICharacter.hpp"


AMateria::AMateria(std::string const & type): type(type)
{
    // std::cout<<"AMateria " << type << "constroctored" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{

}
AMateria &AMateria::operator=(const AMateria &other)
{
    // std::cout <<"AMateria copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{}

const std::string &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}