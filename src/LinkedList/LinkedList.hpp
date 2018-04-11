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

		Type* get(int index) {
			Element<Type> *P = first;
		    for (int i = 0; i < index; ++i) {
		    	if (P == NULL) {
		    		return NULL;
		    	}
		        P = P->getNext();
		    }
		    return P->getInfo();
		}

		bool remove(int index) {
			if (index < 0 || isEmpty()) {
				return false;
			} else if (index == 0) {
				// Element<Type> *oldFirst = this->first;
				this->first = this->first->getNext();
				// delete oldFirst;
			} else {
				index--;
				Element<Type> *elmt = this->first;
				while (index > 0 && elmt != NULL) {
					elmt = elmt->getNext();
					index--;
				}
				if (elmt == NULL || elmt->getNext() == NULL) {
					return false;
				}
				Element<Type> *oldElmt = elmt->getNext();
				elmt->setNext(oldElmt->getNext());
				// delete oldElmt;
			}
			return true;
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