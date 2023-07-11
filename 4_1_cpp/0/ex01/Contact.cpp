#include "Contact.hpp"

std::string Contact::_format_for_display(std::string string_to_format)
{
	if (string_to_format.length() <= 10)
	{
		for (unsigned long i = 0; i < (10 - string_to_format.length()); i++)
			std::cout << " ";
		std::cout << string_to_format;	
	}
	else if (string_to_format.length() > 10)
		std::cout << string_to_format.substr(0, 9) << ".";
	return (string_to_format);
}

void Contact::_printAttr(const std::string& fieldName, const std::string& fieldValue) {
    std::cout << fieldName << ": " << fieldValue << "\n";
}

void Contact::printAttrs()
{
	_printAttr("First Name", this->_firstName);
	_printAttr("Last Name", this->_lastName);
	_printAttr("Nickname", this->_nickname);
	_printAttr("Login", this->_login);
	_printAttr("Postal Address", this->_postalAddress);
	_printAttr("Email Address", this->_emailAddress);
	_printAttr("Phone Number", this->_phoneNumber);
	_printAttr("Birthday Date", this->_birthdayDate);
	_printAttr("Favorite Meal", this->_favouriteMeal);
	_printAttr("Underwear Color", this->_underwearColor);
	_printAttr("Darkest Secret", this->_darkestSecret);
}

void Contact::_promptAttr(const std::string& prompt, std::string& field) {
	do {
		std::cout << prompt;
		std::getline(std::cin, field);
		if (field.empty())
			std::cout << "---ERROR: Nothing was entered---\n";
	} while (field.empty());
}

void Contact::add(int i)
{
	this->_index = i;
	std::cout << "---Entering Details for Contact No.";
	std::cout << _index + 1;
	std::cout << "---\n";
	_promptAttr("Enter First Name: ", this->_firstName);
    _promptAttr("Enter Last Name: ", this->_lastName);
	_promptAttr("Enter Nickname: ", this->_nickname);
	_promptAttr("Enter Login: ", this->_login);
	_promptAttr("Enter Postal Address: ", this->_postalAddress);
	_promptAttr("Enter Email Address: ", this->_emailAddress);
	_promptAttr("Enter Phone Number: ", this->_phoneNumber);
	_promptAttr("Enter Birthday Date: ", this->_birthdayDate);
	_promptAttr("Enter Favorite Meal: ", this->_favouriteMeal);
	_promptAttr("Enter Underwear Color: ", this->_underwearColor);
	_promptAttr("Enter Darkest Secret: ", this->_darkestSecret);
	std::cout << "---Entry Complete---\n";
}

void Contact::display()
{
	std::stringstream ss;

	ss << this->_index + 1;
	_format_for_display(ss.str());
	std::cout << "|";
	_format_for_display(this->_firstName);
	std::cout << "|";
	_format_for_display(this->_lastName);
	std::cout << "|";
	_format_for_display(this->_nickname);
	std::cout << "\n";
}