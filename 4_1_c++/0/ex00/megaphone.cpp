#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;
	char *input_string;

	if (argc >= 2)
	{
		i = 1;
		while(argv[i])
		{
			input_string = argv[i];
			j = 0;
			while(input_string[j])
			{
				if (input_string[j] >= 'a' && input_string[j] <= 'z')
					input_string[j] = input_string[j] - 32;
				std::cout << input_string[j];
				j++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';

	return (0);
}