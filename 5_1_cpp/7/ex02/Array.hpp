#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& obj); // const to indicate that the obj parameter won't be modified within the function
		Array& operator=(const Array& obj); // const to indicate that the obj parameter won't be modified within the function
		~Array();
		unsigned int size() const;
		T& operator[]( unsigned int i ) const;
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

# include "Array.tpp"

#endif