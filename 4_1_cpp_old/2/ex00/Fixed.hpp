#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int fpv;
		static const int numFractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(Fixed const &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif