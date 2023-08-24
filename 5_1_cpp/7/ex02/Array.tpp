template<typename T>
Array<T>::Array()
{
	_data = new T();
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_data = new T[n];
	_size = n;
	for (unsigned int i = 0; i < n; ++i)
	{
		_data[i] = T(); // call default constructor for each element
	}
}

template<typename T>
Array<T>::Array(const Array& obj)
{
	_data = new T[obj.size()];
	_size = obj.size();
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = obj._data[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T>& obj)
{
	if (this != &obj) // check for self-assignment
	{
		delete[] _data; // [] to indicate we are deleting a dynamic array
		_data = new T[obj.size()];
		_size = obj.size();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = obj._data[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[]( unsigned int i ) const
{
	if ( i >= _size )
		throw OutOfBoundsException();
	return _data[i];
}