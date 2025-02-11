#include <bits/stdc++.h>
using namespace std;
vector<int> keystream;
string message;

void PSRG(int seed, int length){
    for(int i=0;i<length;i++){
        int key = ((seed+i)*(seed+i)*7+3)%94;
        keystream.push_back(key);
    }
}

string encrypt(string plaintext){
    string ciphertext = "";
    for(int i=0;i<plaintext.size();i++){
        ciphertext += (char)(((int)plaintext[i]-32+keystream[i])%94+32);
    }
    return ciphertext;
}

string decrypt(string ciphertext){
    string plaintext="";
    for(int i=0;i<ciphertext.size();i++){
        plaintext += (char)(((int)ciphertext[i]-32-keystream[i]+94)%94+32);
    }
    return plaintext;
}

int main()
{
    int seed;
    cout << "Seed: ";
    cin >> seed;
    cin.ignore();
    cout << "Message: ";
    getline(cin, message);

    PSRG(seed, message.size());

    // cout << "Keystream: ";
    // for (int key : keystream) {
    //     cout << key << " ";
    // }
    // cout << endl;
    
    string c = encrypt(message);
    cout << "Ciphertext: " << c << endl;

    cout << "Decrypted Message: " << decrypt(c) << endl;

    keystream.clear(); 
    return 0;
}
