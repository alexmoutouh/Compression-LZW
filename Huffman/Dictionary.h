#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

template<typename T>
class Dictionary{

public:

	void add_value(T value, string c);
	map<string, T>& getDictionary();
	
	vector<T> decode(string s);
	string encode(vector<T> v);

	// fichiers
	void print_dictionary(ofstream& dest);
	void load_dictionary(ifstream& src); 

private:
	
	map<string, T> m_table;
	map<T, string> m_reverse_table;

};

template<typename T>
void Dictionary<T>::add_value(T value, string c){

	m_table[c] = value;
	m_reverse_table[value] = c;
	cout << "ajout de " << value << ", code : " << c << endl;

}

template<typename T>
map<string, T>& Dictionary<T>::getDictionary(){

	return m_table;

}

template<typename T>
vector<T> Dictionary<T>::decode(string s){

	int i = 0;
	string tmp = "";
	vector<T> res;
	
	while(i < s.size()){
	
		tmp = tmp + s[i]; 
		if(m_table.find(tmp) != m_table.end()){
		
			res.push_back(m_table[tmp]);
			tmp = "";
		
		}
		
		i++;
		
	}
	
	return res;

}

template<typename T>
string Dictionary<T>::encode(vector<T> v){

	int i = 0;
	string res = "";
	
	while(i < v.size()){
	
		res = res + m_reverse_table[v[i]];
		i++;
		
	}
	
	return res;

}

template<typename T>
void Dictionary<T>::print_dictionary(ofstream& dest){

	typename map<string, T>::iterator it;
	for(it = m_table.begin(); it != m_table.end(); it ++){

		dest << it->first << ":" << it->second << endl;

	}

}

template<>
void Dictionary<int>::load_dictionary(ifstream& src){

	// reinitialiser le dictionaire
	m_table.clear();
	m_reverse_table.clear();

	string line, s1, s2;

	int pos;

	// tant qu'il reste des trucs a lire
	while(src >> line){

		// on coupe la ligne en deux sur le caractere ':'
		pos = line.find(":");
		s1 = line.substr(0,pos);
		s2 = line.substr(pos + 1);
		
		// transformer s2 en int
		int sum = 0;
		for(int i = 0; i < s2.size(); i++){

			int v = s2[i] - '0';
			sum += v*pow(10,s2.size()-i-1);

		}

		add_value(sum,s1);

	}

}

#endif // DICTIONARY_H
