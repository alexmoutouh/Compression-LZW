#include <iostream>
#include <fstream>
#include <map>

#define SIZE_CODE 5

using namespace std;

class LZW {
    private : 
        map<string, int> dictionary;
        string buffer;

        void debugDictionary() {
            if(!dictionary.empty()) {
                for(map<string, int>::iterator i = dictionary.begin(); i != dictionary.end(); ++i) {
                    cout << i->first << " : " << i->second << endl;
                }
            } else {
                cout << "empty" << endl;
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

    public : 
        LZW() {
        }

        ~LZW() {
            cout << "LZW detruit." << endl;
        }

        void decode(string path) {
            ifstream inputFile(path, ifstream::in);
            ofstream output(path + "_DECODE");
            map<string, int>::iterator iter;
            int codeDic = 256;

            int step = 0;
            char codeRead[SIZE_CODE];
            int code;
            string charRead;
            buffer = ""; // prev

            do {
                inputFile.getline(codeRead, SIZE_CODE, ' ');

                if(!inputFile.fail()) {
                    // caractere lu
                    code = stoi(codeRead);
                    if(0 <= code && code < 256) {
                        charRead = (char)code; 
                    } else {
                        charRead = this->findByValue(code);
                    }

                    cout << "lu : " << charRead << endl;
                    output << charRead;
                    buffer += charRead;
                    cout << "buffer : " << buffer << endl;

                    if(step > 0) {
                        int i = 1;
                        bool found = true;
                        string word(buffer, 0, 1);
                        // analyse du buffer a partir de ses 2 1eres lettres
                        while(found && i < buffer.size()) {
                            word += buffer[i++];
                            cout << "word : " << word << endl;
                            // nouvelle entree dans le dico
                            if((iter = dictionary.find(word)) == dictionary.end()) {
                                dictionary[word] = codeDic++;
                                found = false;
                            }
                        }
                    }

                    cout << "-----" << endl;
                    this->debugDictionary();
                    cout << "-----" << endl;
                    cout << endl;

                    buffer = charRead;
                    ++step;
                } else {
                    cerr << "code trop important lu (> 10^SIZE_CODE)" << endl; 
                }
            } while(!inputFile.eof() && !inputFile.fail());

            inputFile.close();
            output.close();
        } 
};

int main() {
    LZW * lzw = new LZW();
    lzw->decode("./text.lzw");
}
