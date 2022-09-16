#include <iostream>

int main(int argc, char **argv)
{
	int i;
	char *input_string;

	i = 0;
	input_string = argv[1];
	if (argc == 2)
	{
		while(input_string[i])
		{
			if (input_string[i] >= 'a' && input_string[i] <= 'z')
				input_string[i] = input_string[i] - 32;
			std::cout << input_string[i];
			i++;
		}
	}
	return (0);
}