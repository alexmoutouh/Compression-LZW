#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>

using namespace std;

template<typename T>
class Dictionary{

public:

	void add_value(T value, string c);
	map<string, T>& getDictionary();
	
	vector<T> decode(string s);
	string encode(vector<T> v);

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

#endif // DICTIONARY_H
