#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#define SIZE_CODE 10000

using namespace std;

class LZW {
    private : 
        map<string, int> dictionary;
        string buffer;

        void debugDictionary() {
            if(!dictionary.empty()) {
                cout << "****** Dictionnaire ******" << endl;
                for(map<string, int>::iterator i = dictionary.begin(); i != dictionary.end(); ++i) {
                    cout << i->first << " : " << i->second << endl;
                }
            } else {
                cout << "Dictionnaire vide" << endl;
            }
        }

        string findByValue(int val) {
            if(!dictionary.empty()) {
                for(map<string, int>::iterator i = dictionary.begin(); i != dictionary.end(); ++i) {
                    if(i->second == val) {
                        return i->first;
                    }
                }
            }

            return "";
        }

        void init (){
            this->dictionary.clear();
            for(int i = 0; i < 256; ++i){
                string str = string(1, (char)i);
                dictionary[str] = i;
            }
        }		

    public : 
        LZW() {
            init (); 
        }

        ~LZW() {
            this->dictionary.clear();
            cout << "LZW detruit." << endl;
        }

        vector<int> encode(string path) {
            cout << "****** Compression LZW debut ******" << endl << endl;
            init();
            ifstream inputFile(path, ifstream::in);
            ofstream output(path + "_ENCODE");
            map<string, int>::iterator iter;
            vector<int> vectorReturn;

            int codeDic = 255;
            string tmp;
            string strRead;
            string tampon; 
            this->buffer = "";

            while(getline(inputFile, tmp)) {
                strRead += tmp;
            }

            this->buffer = strRead[0];
            tampon = strRead[0];
            for(int i = 1; i < strRead.size(); ++i) {
                this->buffer += strRead[i];
                if((iter = dictionary.find(this->buffer)) == dictionary.end()) {
                    dictionary[this->buffer] = ++codeDic;
                    output << (dictionary.find(tampon))->second << " ";
                    vectorReturn.push_back((dictionary.find(tampon))->second);
                    char lastItem = this->buffer[this->buffer.size()-1];
                    this->buffer = "";
                    this->buffer = lastItem;
                    tampon = this->buffer;
                } else {
                    tampon = this->buffer;
                }
            }

            output << (dictionary.find(tampon))->second;
            vectorReturn.push_back((dictionary.find(tampon))->second);
            this->debugDictionary();
            cout << endl;

            cout << "****** Compression LZW fin ******" << endl << endl;

            return vectorReturn;
        }

        void decode(string path) {
            cout << "****** Decompression LZW debut ******" << endl << endl;
            this->dictionary.clear();
            ifstream inputFile(path, ifstream::in);
            ofstream output(path + "_DECODE");
            map<string, int>::iterator iter;
            int codeDic = 256;

            int step = 0;
            char codeRead[SIZE_CODE];
            int code;
            string charRead;
            this->buffer = ""; // prev

            do {
                inputFile.getline(codeRead, SIZE_CODE, ' ');

                if(!inputFile.fail()) {
                    // caractere lu
                    code = stoi(codeRead);
                    cout << "code lu : " << code;
                    if(0 <= code && code < 256) {
                        charRead = (char)code; 
                    } else {
                        charRead = this->findByValue(code);
                    }

                    cout << "item lu : " << charRead << endl;
                    output << charRead;
                    this->buffer += charRead;

                    // theoriquement les premiers codes sont juste des codes
                    // ascii si l'encodage a bien ete realise...
                    if(step > 0) {
                        int i = 1;
                        bool found = true;
                        string word(this->buffer, 0, 1);
                        // analyse du buffer a partir de ses 2 1eres lettres
                        while(found && i < this->buffer.size()) {
                            word += this->buffer[i++];
                            // nouvelle entree dans le dico
                            if((iter = dictionary.find(word)) == dictionary.end()) {
                                dictionary[word] = codeDic++;
                                found = false;
                            }
                        }
                    }

                    //this->debugDictionary();

                    this->buffer = charRead;
                    ++step;
                } else {
                    cerr << "code trop important lu (> 10^SIZE_CODE)" << endl; 
                }
            } while(!inputFile.eof() && !inputFile.fail());

            inputFile.close();
            output.close();

            cout << "****** Decompression LZW fin ******" << endl << endl;
        } 
};

/*int main() {
    LZW * lzw = new LZW();
    vector<int> test = lzw->encode("./loremIpsum.txt");
    lzw->decode("./loremIpsum.txt_ENCODE");

    cout << "test : " << endl;
    for(int i : test) {
        cout << i << " ";
    }
}*/