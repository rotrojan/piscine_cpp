#include <string>
#include <iostream>

class AbstractAnimal {
		std::string _type;
	public:
		AbstractAnimal(std::string type = "unknown"): _type(type) {};
		AbstractAnimal& operator=(const AbstractAnimal& other) {
			this->_type = other._type;
			return (*this);
		};
		virtual void growl(void) const = 0; // makes it abstract
};

class ConcreteDog: public AbstractAnimal {
	public:
		ConcreteDog(void): AbstractAnimal("dog") {};
		ConcreteDog& operator=(const ConcreteDog& other) {
			AbstractAnimal::operator=(other); // use AbstractAnimal's copy operator
			return (*this);
		};
		void growl(void) const { std::cout << "GRRRRRRRRRRRRAOUUUU"; };
};

int main()
{
	ConcreteDog dog1;
	ConcreteDog dog2(dog1);

	dog1.growl();
	return (0);
}
