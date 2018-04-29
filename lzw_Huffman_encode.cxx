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
    // generation fichier compresse (nomme : <nom>+_ENCODE) par LZW 
    vector<int> vectorEncode = lzw->encode(argv[1]);

    HuffmanAlgorithm<int> ha(vectorEncode);
    ha.compute_tree();

    cout << "Creation du dictionnaire HUFFMAN..." << endl;
    Dictionary<int> d = ha.create_dictionary();
    string str(argv[1]);
    ofstream dicoOut(str + ".dico");
    d.print_dictionary(dicoOut);
    cout << "Dictionnaire HUFFMAN cree." << endl;

    cout << "****** Compression HUFFMAN debut ******" << endl;
    string s = d.encode(vectorEncode);
    cout << "****** Compression HUFFMAN fin ******" << endl;

    // generation fichier compresse (nomme : <nom>+_LZWHUFFMAN_ENCODED) par LZW puis Huffman 
    ofstream outputEncoded(str + "_LZWHUFFMAN_ENCODED");
    outputEncoded << s;

    dicoOut.close();
    outputEncoded.close();
    return 0;
}
