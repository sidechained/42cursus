#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::string command;

	this->num_contacts = 0;
	while(1)
	{
		std::cout << "Enter Command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
		{
			searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "---So Long and Thanks for all the Fish!---\n";
			return ;
		}
		else
			std::cout << "---ERROR: Command Not Found---\n";
	}
}

bool PhoneBook::isStringDigit(const std::string& str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void PhoneBook::displaySummary()
{
	std::cout << "Summary of Entries:\n";
	std::cout << "\n";
	std::cout << "     Index  FirstName   LastName   Nickname\n";
	for (int i = 0; i < num_contacts; i++) {
		_contacts[i].display();
	}
}

void PhoneBook::searchContact()
{
	std::string search_string;
	int search_value;

	if (num_contacts == 0)
	{
		std::cout << "---ERROR: Phone Book Empty (No Contacts Entered)---\n";
		return;
	}
	displaySummary();
	while (1) {
		std::cout << "Enter Index of Contact To Display: ";
		std::getline(std::cin, search_string);
		std::istringstream iss(search_string);
		iss >> search_value;
		if (search_string.empty())
		{
			std::cout << "---ERROR: Nothing was entered---\n";
		}
		else if (!search_value)
		{
			std::cout << "---ERROR: Index is not an integer---\n";
		}
		else if (search_value < 1 || search_value > num_contacts)
		{
			std::cout << "---ERROR: Contact does not exist in phone book---\n";
		}
		else
			break ;
	}
	std::cout << "---Displaying Details of Contact No.";
	std::cout << search_value;
	std::cout << "---\n";
	--search_value;
	_contacts[search_value].printAttrs();
	std::cout << "---Search Complete---\n";
}

void PhoneBook::addContact()
{
	int i;

	i = num_contacts % MAX_CONTACTS;
	_contacts[i].add(i);
	if (num_contacts < MAX_CONTACTS)
		num_contacts++;
}
