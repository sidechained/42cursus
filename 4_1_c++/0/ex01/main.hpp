#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream> // cout and string

#define MAX_CONTACTS 8

class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string bithday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
};

#endif