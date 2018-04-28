#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include "HuffmanObject.h"

using namespace std;

template<typename T>
class HuffmanNode : public HuffmanObject<T>{

public:

	HuffmanNode(int occurence, const HuffmanObject<T>* left, const HuffmanObject<T>* right);
	virtual ~HuffmanNode();
	virtual void add_to_dictionary(string step_value, Dictionary<T>& d) const;

private:

	const HuffmanObject<T>* m_left;
	const HuffmanObject<T>* m_right;

};

template<typename T>
HuffmanNode<T>::HuffmanNode(int occurence, const HuffmanObject<T>* left, const HuffmanObject<T>* right):HuffmanObject<T>(occurence), m_left(left), m_right(right){

}

template<typename T>
HuffmanNode<T>::~HuffmanNode(){

	delete m_left;
	delete m_right;
	m_left = NULL;
	m_right = NULL;

}

template<typename T>
void HuffmanNode<T>::add_to_dictionary(string step_value, Dictionary<T>& d) const{

	m_left->add_to_dictionary(step_value + '0', d);
	m_right->add_to_dictionary(step_value + '1', d);

}

#endif // HUFFMANNODE_H
