#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>

class Contact
{
	private:
		int _index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _login;
		std::string _postalAddress;
		std::string _emailAddress;
		std::string _phoneNumber;
		std::string _birthdayDate;
		std::string _favouriteMeal;
		std::string _underwearColor;
		std::string _darkestSecret;
		void _printAttr(const std::string& fieldName, const std::string& fieldValue);
		void _promptAttr(const std::string& prompt, std::string& field);
		std::string _format_for_display(std::string string_to_format);
	public:
		void add(int i);
		void printAttrs();
		void display();
};

#endif