#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <cstdlib>

template <class Type>
class Element {
	private:
		Type *info;
		Element<Type> *next;
	public:
		Element() {
			this->info = NULL;
			this->next = NULL;
		}

		Element(Type *info) {
			this->info = info;
			this->next = NULL;
		}

		Type* getInfo() {
			return this->info;
		}

		Element<Type>* getNext() {
			return this->next;
		}

		void setInfo(Type *info) {
			this->info = info;
		}

		void setNext(Element<Type> *next) {
			this->next = next;
		}
};

#endif