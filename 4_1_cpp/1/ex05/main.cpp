#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::cout << "---TEST 1: harl.complain(\"DEBUG\");" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "---TEST 2: harl.complain(\"INFO\");" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "---TEST 3: harl.complain(\"WARNING\");" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "---TEST 4: harl.complain(\"ERROR\");" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "---TEST 5: harl.complain(\"NOIDEA\");" << std::endl;
	harl.complain("NOIDEA");
	std::cout << std::endl;
	std::cout << "---TEST 6: harl.complain(\"\");" << std::endl;
	harl.complain("");
	std::cout << std::endl;
}