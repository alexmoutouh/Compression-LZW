#ifndef HUFFMANLEAF_H
#define HUFFMANLEAF_H

#include <iostream>
#include <string>
#include "Dictionary.h"
#include "HuffmanObject.h"

using namespace std;

template<typename T>
class HuffmanLeaf : public HuffmanObject<T>{

public:

	HuffmanLeaf(const T& value, int occurence);
	virtual ~HuffmanLeaf();
	void add_to_dictionary(string step_value, Dictionary<T>& d) const;

private:

	T m_value;

};

template<typename T>
HuffmanLeaf<T>::HuffmanLeaf(const T& value, int occurence):HuffmanObject<T>(occurence),m_value(value){}

template<typename T>
HuffmanLeaf<T>::~HuffmanLeaf(){}

template<typename T>
void HuffmanLeaf<T>::add_to_dictionary(string step_value, Dictionary<T>& d) const{

	d.add_value(m_value,step_value);

}

#endif // HUFFMANLEAF_H
