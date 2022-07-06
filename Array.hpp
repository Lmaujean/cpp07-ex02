#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>

class Array
{
    private:
            unsigned int _i;
            T            *_array;
    public:
        Array<T>()
        {
            std::cout << "Default Constructor";
            this->_array = NULL;
            _i = 0;
        }

        Array(unsigned int i)
        {
            _array = new T[i]();
            _i = i;
        }

        Array (Array<T> const & rhs)
        {
             std::cout << "constructor copy";
             *this = rhs;
        }

        ~Array<T>()
        {
            delete [] _array;
        }

        unsigned int	size() const {
				return (_i);
			}

			class Outoflimite : public std::exception
			{
				public:
					virtual const char* what() const throw() 
                    { 
                        return ("Exception: Out of the Limits"); 
                    }
			};

			T&			operator[]( int i )
			{
				if (i >= 0 && i < (int)_i )
					return (_array[i]);
				throw Outoflimite();
			}

			Array<T>&	operator=( Array<T> const & rhs )
			{
				this->_i = rhs._i;
				this->_array = new T[_i];
				for (int i = 0 ; i < (int)_i ; i++)
					this->_array[i] = rhs._array[i];
				return (*this);
			}
};

#endif