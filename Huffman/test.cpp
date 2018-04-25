#include <iostream>
#include <fstream>
#include "HuffmanAlgorithm.h"

using namespace std;

int main(int argc, char* argv[]){

	vector<int> values;

	int v;

	for(int i=0; i < 100; i++){

		v = -(i - i*i + i*i*i - i*i*i*i) % 360;
		cout << v << endl;
		values.push_back(v); 

	}

	HuffmanAlgorithm<int> ha(values);

	ha.compute_tree();

	Dictionary<int> d = ha.create_dictionary();

	ofstream output("dico.txt");

	d.print_dictionary(output);

	string s = d.encode(values);

	cout << s << endl;

	vector<int> decoded = d.decode(s);

	if(values.size() == decoded.size()){

		for(int i=0; i < values.size(); i++)
			cout << values[i] << " : " << decoded[i] << endl;

	}
	
	ifstream input("dico.txt");

	d.load_dictionary(input);

	return 0;

}
