#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &other);
        Fixed(int const nb);
        Fixed(float const nb);
        Fixed & operator=(Fixed const &other);
        ~Fixed();
        int     getRawBits(void) const;
		void    setRawBits(int const raw);
        float	toFloat(void) const;
        int		toInt(void) const;
        bool operator<(Fixed const & other) const;
        bool operator<=(Fixed const & other) const;
        bool operator>(Fixed const & other) const;
        bool operator>=(Fixed const & other) const;
        bool operator!=(Fixed const & other) const;
        bool operator==(Fixed const & other) const;
        Fixed operator+(Fixed const & other) const;
        Fixed operator-(Fixed const & other) const;
        Fixed operator*(Fixed const & other) const;
        Fixed operator/(Fixed const & other) const;
        Fixed & operator++(void);
        Fixed   operator++(int);
        Fixed & operator--(void);
        Fixed   operator--(int);
        static Fixed & min(Fixed & a, Fixed & b);
        static Fixed const & min(Fixed const & a, Fixed const & b);
        static Fixed & max(Fixed & a, Fixed & b);
        static Fixed const & max(Fixed const & a, Fixed const & b);
    private:
        int _value;
        static int const _nbBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif