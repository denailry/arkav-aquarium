#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <cstddef>

template <class Type>
class Element {
	public:
		Element(Type X)
		{
			info = X;
			next = NULL;
		}
		Element* getNext() const
		{
			return next;
		}
		Type getInfo() const
		{
			return info;
		}
		void setNext(Element* t_next)
		{
			next = t_next;
		}
		void setInfo(Type t_info)
		{
			info = t_info;
		}
	private:
		Type info;
		Element *next;
};

#endif
