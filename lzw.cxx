#include <iostream>
#include <fstream>
#include <map>

#define SIZE_CODE 5

using namespace std;

class LZW {
    private : 
        map<string, int> dictionary;
        string buffer;

        string findByValue(int val) {
            cout << "si tu peux m'aider sur ce coup, j'te serai reconnaissant" << endl;
            cout << "ça doit etre une couille de nullptr" << endl;
            cout << dictionary.find("0")->second;
            if(!dictionary.empty()) {
            cout << "LolILOL";
                for(map<string, int>::iterator i = dictionary.begin(); i != dictionary.end(); ++i) {
                    if(i->second == val) {
                        return i->first;
                    }
                }
            }

            return NULL;
        }

    public : 
        LZW() {
            dictionary["0"] = -1;
            buffer = "";
        }

        void decode(string path) {
            ifstream inputFile(path, ifstream::in);
            map<string, int>::iterator iter;

            //char prev = NULL;
            char codeRead[SIZE_CODE];
            int code;
            string charRead;
            buffer = "";

            while(!inputFile.eof() && !inputFile.fail()) {
                inputFile.getline(codeRead, SIZE_CODE, ' ');

                if(!inputFile.fail()) {
                    // caractere lu
                    code = stoi(codeRead);
                    if(0 <= code && code < 256) {
                        charRead = (char)code; 
                    } else {
                        charRead = this->findByValue(code);
                    }
            cout << charRead << endl;
                        // nouvelle entree dans le dico
/*                        if((iter = buffer.find(buffer)) != dictionary.end()) {
                            dictionary[ascii] = codeRead;
                        }
                        cout << buffer << endl;
                        cout << (char)ascii << endl;
                    } else {

                    }*/
                } else {
                    cerr << "code trop important lu (> 10^SIZE_CODE)" << endl; 
                }
            }
            inputFile.close();
        }
};

int main() {
    LZW * lzw = new LZW();
    lzw->decode("./text.lzw");
}
