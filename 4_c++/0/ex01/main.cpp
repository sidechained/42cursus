#include "main.hpp"

std::string format_for_display(std::string string_to_format)
{
	unsigned long i;

	if (string_to_format.length() < 10)
	{
		i = 0;
		while(i < (10 - string_to_format.length()))
		{
			std::cout << " ";
			i++;
		}
		std::cout << string_to_format;	
	}
	else if (string_to_format.length() > 10)
	{
		i = 0;
		while(i < 9)
		{
			std::cout << string_to_format[i];
			i++;
		}
		std::cout << ".";
	}
	return (string_to_format);
}

void	add_contact(int num_contacts, Contact *contacts)
{
	std::cout << "\n";				
	std::cout << "---STATUS: Entering Contact No.";
	std::cout << num_contacts + 1;
	std::cout << "---\n";
	std::cout << "Enter First Name: ";
	std::cin >> contacts[num_contacts].first_name;
	std::cout << "Enter Last Name: ";
	std::cin >> contacts[num_contacts].last_name;
	std::cout << "Enter Nickname: ";
	std::cin >> contacts[num_contacts].nickname;
	std::cout << "Enter Login: ";
	std::cin >> contacts[num_contacts].login;
	std::cout << "Enter Postal Address: ";
	std::cin >> contacts[num_contacts].postal_address;
	std::cout << "Enter Email Address: ";
	std::cin >> contacts[num_contacts].email_address;
	std::cout << "Enter Phone Number: ";
	std::cin >> contacts[num_contacts].phone_number;
	std::cout << "Enter Birthday Date: ";
	std::cin >> contacts[num_contacts].bithday_date;
	std::cout << "Enter Favorite Meal: ";
	std::cin >> contacts[num_contacts].favorite_meal;
	std::cout << "Enter Underwear Color: ";
	std::cin >> contacts[num_contacts].underwear_color;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> contacts[num_contacts].darkest_secret;
	std::cout << "---STATUS: Entry Complete---\n\n";
}

void	search_contact(int num_contacts, Contact *contacts)
{
	int i;
	std::string search_string;
	int i_to_lookup;

	if (num_contacts == 0)
	{
		std::cout << "\n---ERROR: Phone Book Empty (No Contacts Entered)---\n\n";
		return;
	}
	i = 0;
	while(i < num_contacts)
	{
		format_for_display(std::to_string(i+1));
		std::cout << "|";
		format_for_display(contacts[i].first_name);
		std::cout << "|";
		format_for_display(contacts[i].last_name);
		std::cout << "|";				
		format_for_display(contacts[i].nickname);				
		std::cout << "\n";
		i++;
	}
	std::cout << "\n";
	std::cout << "Enter Index of Contact To Display: ";
	std::cin >> search_string;
	// ADD ERROR IF NOT INTEGER OR IF CONTACT DOESN'T EXIST
	if (search_string.length() != 1 || (search_string[0] < '0' || search_string[0] > '9'))
	{
		std::cout << "---ERROR: Index should be a single digit---\n\n";
		return;
	} 
	else
	{
		i_to_lookup = search_string[0] - '0';
	}
	if (i_to_lookup > num_contacts)
	{
		std::cout << "---ERROR: Contact does not exist in phone book---\n\n";
		return;
	}
	std::cout << "\n";				
	std::cout << "---STATUS: Displaying Contact No.";
	std::cout << i_to_lookup;
	std::cout << "---\n";
	std::cout << "First Name: ";
	std::cout << contacts[i_to_lookup - 1].first_name;
	std::cout << "\n";
	std::cout << "Last Name: ";
	std::cout << contacts[i_to_lookup - 1].last_name;
	std::cout << "\n";
	std::cout << "Nickname: ";
	std::cout << contacts[i_to_lookup - 1].nickname;
	std::cout << "\n";
	std::cout << "Login: ";
	std::cout << contacts[i_to_lookup - 1].login;
	std::cout << "\n";
	std::cout << "Postal Address: ";
	std::cout << contacts[i_to_lookup - 1].postal_address;
	std::cout << "\n";
	std::cout << "Email Address: ";
	std::cout << contacts[i_to_lookup - 1].email_address;
	std::cout << "\n";
	std::cout << "Phone Number: ";
	std::cout << contacts[i_to_lookup - 1].phone_number;
	std::cout << "\n";
	std::cout << "Birthday Date: ";
	std::cout << contacts[i_to_lookup - 1].bithday_date;
	std::cout << "\n";
	std::cout << "Favorite Meal: ";
	std::cout << contacts[i_to_lookup - 1].favorite_meal;
	std::cout << "\n";
	std::cout << "Underwear Color: ";
	std::cout << contacts[i_to_lookup - 1].underwear_color;
	std::cout << "\n";
	std::cout << "Darkest Secret: ";
	std::cout << contacts[i_to_lookup - 1].darkest_secret;			
	std::cout << "\n";
	std::cout << "---STATUS: Search Complete---\n\n";
}

int main()
{
	std::string command;
	Contact contacts[MAX_CONTACTS];
	int num_contacts = 0;

	while(1)
	{
		std::cout << "Enter Command (ADD, SEARCH or EXIT): ";
		std::cin >> command;

		if (command == "ADD")
		{
			if (num_contacts < MAX_CONTACTS)
			{
				add_contact(num_contacts, contacts);
				num_contacts++;
			}
			else
				std::cout << "\n---ERROR: Reached Storage Limit of " << MAX_CONTACTS << " Contacts---\n\n";
		}
		else if (command == "SEARCH")
		{
			search_contact(num_contacts, contacts);
		}
		else if (command == "EXIT")
		{
			std::cout << "\n";
			std::cout << "---So Long and Thanks for all the Fish!---\n\n";
			return (0);
		}
		else
			std::cout << "---ERROR: Command Not Found---\n\n";
	}
}