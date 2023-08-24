#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;	
	public:
		Array()
		{
			_data = new T();
			_size = 0;
		}
		Array(unsigned int n)
		{
			_data = new T[n];
			_size = n;
			
			for (unsigned int i = 0; i < n; ++i)
			{
				_data[i] = T(); // call default constructor for each element
			}
		}
		Array(const Array& obj) // const to indicate that the obj parameter won't be modified within the function
		{
			_data = new T[obj.size()];
			_size = obj.size();
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = obj._data[i];
		};
		Array& operator=(const Array& obj) // const to indicate that the obj parameter won't be modified within the function
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
		~Array()
		{
			delete [] _data;
		}
		unsigned int size() const
		{
			return _size;
		}
		T& operator[]( unsigned int i ) const
		{
			if ( i >= _size )
				throw OutOfBoundsException();
			return _data[i];
		}
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index is out of bounds";
				}
		};
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr )
{
	for ( unsigned int i( 0 ); i < arr.size(); i++ )
		out << arr[i] << " ";
	return out;
}

#endif