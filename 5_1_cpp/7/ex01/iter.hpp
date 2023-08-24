struct Person {
    std::string name;
    int age;
};

template <typename T>
void iter(T* array, int length, void (*f)(T&))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

void iter(int* array, int length, void (*f)(int))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

void iter(Person* array, int length, void (*f)(Person))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}