#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "../Element/Element.hpp"
#include <cstdlib>

template <class Type>
class LinkedList {
	private:
		Element<Type> *first;
	public:
		LinkedList() {
			this->first = NULL;
		}

		bool isEmpty() {
			return first == NULL;
		}

		void add(Type *info) {
			if (isEmpty()) {
				this->first = new Element<Type>();
				this->first->setInfo(info);
				this->first->setNext(NULL);
			} else {
				Element<Type> *elmt = this->first;
				while (elmt->getNext() != NULL) {
					elmt = elmt->getNext();
				}	
				Element<Type> *newElement = new Element<Type>();
				elmt->setNext(newElement);
				elmt->getNext()->setInfo(info);
				elmt->getNext()->setNext(NULL);
			}
		}

		Element<Type>* getFirst() {
			return this->first;
		}
};

#endif