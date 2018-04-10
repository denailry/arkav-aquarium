#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "../Element/Element.hpp"
#include <iostream>

template <class Type>
class LinkedList {
	public:
		LinkedList() {
			this->first = NULL;
		}

		Type& get(int index)
		{
			Element<Type> *P = first;
		    for (int i = 0; i < index; ++i)
		    {
		        P = P->getNext();
		    }
		    return P->getInfo();
		}
		bool isEmpty()
		{
			return first == NULL;
		}
		void add(Type *X)
		{
		    if (isEmpty()) {
				this->first = new Element<Type>(X);;
				this->first->setNext(NULL);
		    } else {
				Element<Type> *last = first;
				while (last->getNext() != NULL)
				{
					last = last->getNext();
				}
				// last di elemen terakhir
				if (last == NULL) {
					std::cout << "WTF.... NULL???" << std::endl;
					return;
				}
				std::cout << "ADDING" << std::endl;
				last->setNext(new Element<Type>(X));
				std::cout << "NEXT SET" << std::endl;
				last->getNext()->setNext(NULL);
				std::cout << "ADDED" << std::endl;
			}
		}
		void remove(Type &X)
		{
			bool found = false;
			Element<Type> *P = first;
			Element<Type> *Prec = NULL;
			while ((P != NULL) && !found)
			{
				if (P->getInfo() == X) {
					found = true;
				} else {
					Prec = P;
					P = P->getNext();
				}
			}
			if (found) {
				if (P == first)
				{
					first = P->getNext();
				}
				else
				{
					Prec->setNext(P->getNext());
				}
			} else {
				throw "Tidak ada di list";
			}
		}
		int find(Type &X)
		{
			int index = 0;
			bool found = false;
			Element<Type> *P = first;
			while ((P != NULL) && !found)
			{
				if (P->getInfo() == X) {
					found = true;
				} else {
					P = P->getNext();
					index++;
				}
			}
			if (found) {
				return index;
			} else {
				return -9999;
			}
		}
		Element<Type>* getFirst() {
			return this->first;
		}
	private:
		Element<Type> *first;
};

#endif
