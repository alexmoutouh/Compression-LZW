#include <iostream>
#include <fstream>
#include "./Huffman/HuffmanAlgorithm.h"
#include "./LZW.cxx"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3) {
        cerr << "USAGE : " << argv[0] << " <nom_fichier_a_decompresser> <dictionnaire_Huffman>" << endl;
        return -1;
    }

    cout << "Chargement du dictionnaire HUFFMAN..." << endl;
    Dictionary<int> d;
    ifstream inputDico(argv[2]);
    d.load_dictionary(inputDico);
    cout << "Dictionnaire HUFFMAN charge." << endl;

    ifstream inputFile(argv[1]);
    string s;
    string tmp;
    while(getline(inputFile, tmp)) {
        s += tmp;
    }

    cout << "****** Decompression HUFFMAN debut ******" << endl;
    vector<int> decoded = d.decode(s);
    cout << "****** Decompression HUFFMAN fin ********" << endl;

    // generation fichier decompresse (nomme : <nom>+_LZWHUFFMAN_DECODED) par Huffman 
    string str(argv[1]);
    str += "_HUFFMAN_DECODED";
    ofstream decodedHuffOut(str);
    for(int code : decoded) {
        decodedHuffOut << code << " ";
    }
/*    for(int i = 0; i < decoded.size() - 1; ++i) {
    }
    decodedHuffOut << decoded[decoded.size() - 1];*/
    decodedHuffOut.close();

    LZW * lzw = new LZW();
    cout << "decompression de : " << str << "check" << endl;
    lzw->decode(str);

    inputDico.close();
    inputFile.close();

    return 0;
}
