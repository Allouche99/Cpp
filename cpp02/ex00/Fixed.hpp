#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>


class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &other);
        Fixed & operator=(Fixed const &other);
        ~Fixed();
        int getRawBits(void) const;
		void setRawBits(int const raw);
    private:
        int _value;
        static int const _nbBits;
};

#endif