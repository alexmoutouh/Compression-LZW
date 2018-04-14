#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

void print_char_as_binary(char ch) {
    // nombre de bits dans un octet
    int i = CHAR_BIT;

    // a chaque parcours de boucle, on fait un & logique entre ch et 
    // 00000001 shift de i (ie 10000000, 01000000, ... , 00000001)
    while(i > 0) {
        --i;
        cout << (ch & (1 << i) ? '1' : '0');
    }
}

char getBigWeight(char c) {
    char toMove = c;
    // & bitbit avec 11110000
    toMove = c & 0xf0;
    return toMove;
}

char getLittleWeight(char c) {
    char toMove = c;
    // & bitbit avec 00001111
    toMove = c & 0x0f;
    return toMove;
}

int main(int argc, char * argv[]) {
    // lecture ecriture
    ifstream input(argv[1], ifstream::in);
    ofstream outputBig("bigBytes.txt");
    ofstream outputLittle("littleBytes.txt");

    // longueur pour les stats
    unsigned length = 0;
    // tableau des occurences, indices = valeur ascii
    vector<unsigned> occurs(255, 0);

    char bigWeight;
    char littleWeight;

    // lecture
    char c = input.get();
    while(input.good()) {
        ++length;
        occurs[c] += 1;

        //affichage
        cout << c;
        print_char_as_binary(c);
        cout << endl;

        bigWeight = getBigWeight(c);
        cout << "lettre : "<< c;
        print_char_as_binary(c); 
        cout << " shifte : " << bigWeight; 
        print_char_as_binary(bigWeight);
        cout << endl;
        outputBig << bigWeight;

        littleWeight = getLittleWeight(c);
        cout << "lettre : "<< c;
        print_char_as_binary(c); 
        cout << " shifte : " << littleWeight; 
        print_char_as_binary(littleWeight); 
        cout << endl;
        outputLittle << littleWeight;

        c = input.get();
    }

    input.clear();
    input.seekg(0, ios::beg);

    string fic(argv[1]);

    c = input.get();
    for(unsigned i = 0; i < occurs.size(); i++) {
        if(occurs[i] > 0) {
            // apparitions
            cout << (char)i << " apparitions : " << occurs[i] << endl;
            // frequences
            cout << (char)i << " frequences : " << occurs[i] / (double)length << endl;
        }
    }

    outputBig.close();
    outputLittle.close();

    return 0;
}

