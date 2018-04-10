#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <cstddef>
#include <iostream>

template <class Type>
class Element {
	public:
		Element(Type *X)
		{
			std::cout << "Creating new Element" << std::endl;
			*info = *X;
			next = NULL;
			std::cout << "Create new Element" << std::endl;
		}
		Element<Type>* getNext()
		{
			return next;
		}
		Type& getInfo()
		{
			return *info;
		}
		void setNext(Element<Type>* t_next)
		{
			std::cout << "Setting new Element" << std::endl;
			next = t_next;
			std::cout << "Next Element Set" << std::endl;
		}
		void setInfo(Type &t_info)
		{
			info = t_info;
		}
		Element<Type>& operator=(const Element<Type>& elmt) {
			this->info = elmt.info;
			this->next = elmt.next;
			return *this;
		} 
		bool hasNext() {
			return next != NULL;
		}
	private:
		Type *info;
		Element<Type> *next;
};

#endif
