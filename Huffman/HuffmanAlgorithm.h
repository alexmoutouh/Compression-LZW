#ifndef HUFFMANALGORITHM_H
#define HUFFMANALGORITHM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "HuffmanLeaf.h"
#include "HuffmanNode.h"

using namespace std;

template<typename T>
class HuffmanAlgorithm{

public:

	HuffmanAlgorithm();
	virtual ~HuffmanAlgorithm();
	void add_value(const T& value, int occurence);
	void compute_tree();
	Dictionary<T> create_dictionary();
	void clear();

private:
	
	vector<HuffmanObject<T>*> m_values;
	HuffmanObject<T>* m_root;

};

template<typename T>
HuffmanAlgorithm<T>::HuffmanAlgorithm(){ m_root = NULL; }

template<typename T>
HuffmanAlgorithm<T>::~HuffmanAlgorithm(){
	
	if(m_root == NULL){
		delete m_root;
		m_root = NULL;
	}
	else{
		for(int i=0; i < m_values.size(); i++)
			delete m_values[i];
	}
	
}

template<typename T>
void HuffmanAlgorithm<T>::add_value(const T& value, int occurence){

	m_values.push_back(new HuffmanLeaf<T>(value,occurence));

} 

template<typename T>
void HuffmanAlgorithm<T>::compute_tree(){

	// tant qu'il reste des élements à grouper
	while(m_values.size() > 1){

		//on trie la liste pour obtenir les elements les plus legers en fin	
		sort(m_values.begin(), m_values.end(), compare<T>);

		// on enleve les elements les plus legers
		HuffmanObject<T>* h1 = m_values.back();
		m_values.pop_back();
		HuffmanObject<T>* h2 = m_values.back();
		m_values.pop_back();
		
		// on cree un nouveau noeuds avec ces deux elements
		HuffmanNode<T>* hn = new HuffmanNode<T>(h1->get_occurrence() + h2->get_occurrence(),h1,h2);
		
		// on place ce noeuds dans la liste des elements
		m_values.push_back(hn);

	}

	m_root = m_values[0];

}

template<typename T>
Dictionary<T> HuffmanAlgorithm<T>::create_dictionary(){

	Dictionary<T> d;
	
	// appels recursifs
	m_root->add_to_dictionary("",d);
		
	return d;

}

template<typename T>
void HuffmanAlgorithm<T>::clear(){

	if(m_root == NULL){
		delete m_root;
		m_root = NULL;
	}
	else{
		for(int i=0; i < m_values.size(); i++)
			delete m_values[i];
		m_values.clear();
	}

}

#endif // HUFFMANALGORITHM_H
