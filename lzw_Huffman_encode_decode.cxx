#include <iostream>
#include <fstream>
#include "./Huffman/HuffmanAlgorithm.h"
#include "./LZW.cxx"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2) {
        cerr << "USAGE : " << argv[0] << " <nom_fichier_a_compresser>" << endl;
        return -1;
    }

    LZW * lzw = new LZW();
    // fichier compresse (nomme : <nom>+_ENCODE) par LZW genere 
    vector<int> vectorEncode= lzw->encode(argv[1]);

    HuffmanAlgorithm<int> ha(vectorEncode);
    ha.compute_tree();

    cout << "Creation du dictionnaire HUFFMAN..." << endl;
    Dictionary<int> d = ha.create_dictionary();
    ofstream output("dico.txt");
    d.print_dictionary(output);
    cout << "Dictionnaire HUFFMAN cree." << endl;

    cout << "****** Compression HUFFMAN debut ******" << endl;
    string s = d.encode(vectorEncode);
    cout << "****** Compression HUFFMAN fin ******" << endl;

    // fichier compresse (nomme : <nom>+_LZWHUFFMAN_ENCODED) par LZW puis Huffman genere 
    string str(argv[1]);
    ofstream outputEncoded(str + "_LZWHUFFMAN_ENCODED");
    outputEncoded << s;

    vector<int> decoded = d.decode(s);

    if(vectorEncode.size() == decoded.size()){

    cout << "decoded" << endl;
    for(int i=0; i < vectorEncode.size(); i++)
    cout << vectorEncode[i] << " : " << decoded[i] << endl;

    }

    ifstream input("dico.txt");

    d.load_dictionary(input);

    return 0;
}
