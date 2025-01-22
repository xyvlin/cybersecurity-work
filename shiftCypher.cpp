#include <bits/stdc++.h>
using namespace std;
int key = 4;

string shift(string plain, int k){
    string cip="";
    for(int i=0;i<plain.size();i++){
        if(plain[i]<'A'||plain[i]>'z'||(plain[i]>'Z'&&plain[i]<'a')){
            cip+=plain[i];
        }else if(plain[i]<'A'-k || (plain[i]>='a' && plain[i]<'a'-k)){
            cip+=plain[i]+k+26;
        }else if(plain[i]>'z'-k || (plain[i]<='Z' && plain[i]>'Z'-k)){
            cip+=plain[i]+k-26;
        }else{
            cip+=plain[i]+k;
        }
    }
    return cip;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string plaintxt, ciphertxt;
    cout<<"plaintext: "<<endl;
    getline(cin,plaintxt);
    cout<<"ciphertext: ";
    ciphertxt=shift(plaintxt,key);
    cout<<ciphertxt<<endl;
    cout<<"decrypt: "<<shift(ciphertxt,-1*key);
}