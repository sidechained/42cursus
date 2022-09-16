// TODO: handle entering empty
// ADD ERROR IF NOT INTEGER OR IF CONTACT DOESN'T EXIST

// http://www.cplusplus.com/reference/string/string/
// http://www.cplusplus.com/reference/iomanip/

// display a list of the available non-empty contacts in 4 columns: index, first name, last name and nickname.
// Each column must be 10 chars wide, right aligned and separated by a ’|’ character.
// Any output longer than the columns’ width is truncated and last displayable character is replaced by a ’.’.

#include <string> // string type
#include <iostream> // cout

class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		// std::string postal_address;
		// std::string email_address;
		// std::string phone_number;
		// std::string bithday_date;
		// std::string favorite_meal;
		// std::string underwear_color;
		// std::string darkest_secret;
};

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
	std::cin >> contacts[num_contacts] -> first_name;
	std::cout << "Enter Last Name: ";
	std::cin >> contacts[num_contacts] -> last_name;
	std::cout << "Enter Nickname: ";
	std::cin >> contacts[num_contacts] -> nickname;
	std::cout << "Enter Login: ";
	std::cin >> contacts[num_contacts] -> login;
	// std::cout << "Enter Postal Address: ";
	// std::cin >> contacts[num_contacts].postal_address;
	// std::cout << "Enter Email Address: ";
	// std::cin >> contacts[num_contacts].email_address;
	// std::cout << "Enter Phone Number: ";
	// std::cin >> contacts[num_contacts].phone_number;
	// std::cout << "Enter Birthday Date: ";
	// std::cin >> contacts[num_contacts].bithday_date;
	// std::cout << "Enter Favorite Meal: ";
	// std::cin >> contacts[num_contacts].favorite_meal;
	// std::cout << "Enter Underwear Color: ";
	// std::cin >> contacts[num_contacts].underwear_color;
	// std::cout << "Enter Darkest Secret: ";
	// std::cin >> contacts[num_contacts].darkest_secret;
	std::cout << "---STATUS: Entry Complete---\n\n";
	num_contacts++;
}

int main()
{
	std::string command;
	Contact contacts[8];
	int num_contacts = 0;

	while(1)
	{
		std::cout << "Enter Command (ADD, SEARCH or EXIT): ";
		std::cin >> command;

		if (command == "ADD")
		{
			if (num_contacts <= 7)
				add_contact(num_contacts, &contacts);
			else
				std::cout << "\n---ERROR: Reached Storage Limit of 8 Contacts---\n\n";
		}
		else if (command == "SEARCH")
		{
			int i;
			int i_to_lookup;

			if (num_contacts == 0)
				std::cout << "\n---ERROR: Phone Book Empty (No Contacts Entered)---\n\n";
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
			std::cin >> i_to_lookup;
			i_to_lookup--;
			// ADD ERROR IF NOT INTEGER OR IF CONTACT DOESN'T EXIST
			std::cout << "\n";				
			std::cout << "---STATUS: Displaying Contact No.";
			std::cout << i_to_lookup;
			std::cout << "---\n";
			std::cout << "First Name: ";
			std::cout << contacts[i_to_lookup].first_name;
			std::cout << "\n";
			std::cout << "Last Name: ";
			std::cout << contacts[i_to_lookup].last_name;
			std::cout << "\n";
			std::cout << "Nickname: ";
			std::cout << contacts[i_to_lookup].nickname;
			std::cout << "\n";
			std::cout << "Login: ";
			std::cout << contacts[i_to_lookup].login;
			std::cout << "\n";
			// std::cout << "Postal Address: ";
			// std::cout << contacts[i_to_lookup].postal_address;
			// std::cout << "\n";
			// std::cout << "Email Address: ";
			// std::cout << contacts[i_to_lookup].email_address;
			// std::cout << "\n";
			// std::cout << "Phone Number: ";
			// std::cout << contacts[i_to_lookup].phone_number;
			// std::cout << "\n";
			// std::cout << "Birthday Date: ";
			// std::cout << contacts[i_to_lookup].bithday_date;
			// std::cout << "\n";
			// std::cout << "Favorite Meal: ";
			// std::cout << contacts[i_to_lookup].favorite_meal;
			// std::cout << "\n";
			// std::cout << "Underwear Color: ";
			// std::cout << contacts[i_to_lookup].underwear_color;
			// std::cout << "\n";
			// std::cout << "Darkest Secret: ";
			// std::cout << contacts[i_to_lookup].darkest_secret;			
			// std::cout << "\n";
			std::cout << "---STATUS: Search Complete---\n\n";
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