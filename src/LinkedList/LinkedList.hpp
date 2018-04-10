#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "../Element/Element.hpp"

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
		void add(Type &X)
		{
			Element<Type> *P = new Element<Type>(X);
			Element<Type> *last = first;
		    if (isEmpty())
		    {
				P->setNext(last);
				last = P;
		    }
			else
			{
				while (last->getNext() != NULL)
				{
					last = last->getNext();
				}
				// last di elemen terakhir
				P->setNext(last->getNext());
				last->setNext(P);
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
