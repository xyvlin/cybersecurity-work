#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<int> keys;
vector<string> words;

void split(string str, char del){
    string temp = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            words.push_back(temp);
            temp = "";
        }
    }  
}

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
    string message, decrypted;
    cout<<"message: "<<endl;
    getline(cin,message);
    split(message,' ');

    auto start = high_resolution_clock::now();
    for(int i=0;i<words.size();i++){
        if(words[i].size()==1){
            keys.push_back('i'-words[i][0]);
            keys.push_back('a'-words[i][0]);
        }
    }
    if(!keys.empty()){
        for(int i=0;i<keys.size();i++){
            cout<<"key "<<keys[i]<<": ";
            decrypted=shift(message,keys[i]);
            cout<<decrypted<<endl;
        }
    }else{
        cout<<"I don't know what to do";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "time taken: "<<duration.count() << " ms" << endl;
}