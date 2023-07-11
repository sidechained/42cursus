#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		int		num_contacts;
		Contact	_contacts[MAX_CONTACTS];
		void	addContact();
		void 	searchContact();
		void	displaySummary();
		bool	isStringDigit(const std::string& str);
	public:
		PhoneBook();
};

#endif