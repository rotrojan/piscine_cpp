/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.f>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:02:34 by bigo              #+#    #+#             */
/*   Updated: 2022/01/22 02:45:37 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_TPP
# define ARRAY_CLASS_TPP
# include <exception>
# include <ostream>

template <typename T>
class Array {
	public:
		//constructor
		Array(unsigned int n = 0): _data(new T[n]), _size(n) {
			for (unsigned int i = 0; i < n; i++)
				this->_data[i] = 0;
		};
		// copy constructor
		Array(Array const &array): _data(new T[array._size]), _size(array._size){
			*this = array;
		};
		//operator overloads (= and [])
		Array &operator=(Array const &rhs) {
			if (rhs._size > this->_size)
				throw ArrayTooLarge();
			if (this != &rhs) {
				for (unsigned int i = 0; i < rhs._size; i++)
					this->_data[i] = rhs._data[i];
			}
			return (*this);
		};
		T &operator[](unsigned int i) {
			if (i >= this->_size)
				throw OutOfBounds();
			return (this->_data[i]);
		};
		//exception when accessing an out of bounds index
		class OutOfBounds: public std::exception {
			const char * what() const throw() {
				return ("out of bounds");
			};
		};
		//exception when copy impossible
		class ArrayTooLarge: public std::exception {
			const char * what() const throw() {
				return ("array too large");
			};
		};
		// destructor
		virtual ~Array(void) {
			delete [] this->_data;
		};
		// getters
		unsigned int size(void) const {
			return (this->_size);
		};
		T const	*get_data(void) const {
			return (this->_data);
		};

	private:
		T				*_data;
		unsigned int	_size;
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, Array<T> const &rhs) {
	unsigned int size = rhs.size();
	unsigned int i;
	for (i = 0; i < size - 1; i++) {
		ostream << rhs.get_data()[i] << " ";
	}
	ostream << rhs.get_data()[i];
	return (ostream);
}
template <>
std::ostream &operator<<(std::ostream &ostream, Array<char> const &rhs) {
	unsigned int size = rhs.size();
	unsigned int i;
	for (i = 0; i < size; i++)
		ostream << rhs.get_data()[i];
	return (ostream);
}

#endif
