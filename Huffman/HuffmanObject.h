#ifndef HUFFMANOBJECT_H
#define HUFFMANOBJECT_H

#include <iostream>
#include "Dictionary.h"

using namespace std;

template<typename T>
class HuffmanObject{

public:

	HuffmanObject(int occurence);
	virtual ~HuffmanObject();
	virtual void add_to_dictionary(string step_value, Dictionary<T>& d) const = 0;
	int get_occurrence();

protected:

	int m_occurence;

private:

};

template<typename T>
HuffmanObject<T>::HuffmanObject(int occurence):m_occurence(occurence){}

template<typename T>
HuffmanObject<T>::~HuffmanObject(){}

template<typename T>
int HuffmanObject<T>::get_occurrence(){

	return m_occurence;

}

// comparateur
template<typename T>
bool compare (HuffmanObject<T>* h1, HuffmanObject<T>* h2){

	return h1->get_occurrence() > h2->get_occurrence();
	
}

#endif // HUFFMANOBJECT_H
