#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<int> keys;
vector<string> words;
int cc[26];

//split the sentence into a vector of words
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

//shift cipher
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

//most occuring letter in message
int maxOfcc(){
    int maxx = 0;
    for(int i=0;i<26;i++){
        if(cc[i]>cc[maxx]){
            maxx=i;
        }
    }
    return maxx;
}

//check if all words have vowels or y
bool check(int key){
    for(int j=0;j<words.size();j++){
        string cur = shift(words[j],key);
        bool hasVowel=false;
        for(int k=0;k<cur.size();k++){
            if(cur[k]=='a' || cur[k]=='e' || cur[k]=='i' || cur[k]=='o' || cur[k]=='u' || cur[k]=='y'){
                hasVowel=true;
                break;
            }
        }
        if(!hasVowel) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string message, decrypted;
    cout<<"message: "<<endl;
    getline(cin,message);
    split(message,' ');

    auto start = high_resolution_clock::now();
    for(int i=0;i<message.size();i++){
        if('a'<=message[i]&&message[i]<='z')
            cc[message[i]-'a']++;
    }
    int maxx = maxOfcc()+'a';

    if(check('e'-maxx)){
        cout<<"key "<<'e'-maxx<<":　"<<shift(message,'e'-maxx)<<endl;
    }else if(check('a'-maxx)){
        cout<<"key "<<'a'-maxx<<":　"<<shift(message,'a'-maxx)<<endl;
    }else if(check('o'-maxx)){
        cout<<"key "<<'o'-maxx<<":　"<<shift(message,'o'-maxx)<<endl;
    }else if(check('i'-maxx)){
        cout<<"key "<<'i'-maxx<<":　"<<shift(message,'i'-maxx)<<endl;
    }else if(check('u'-maxx)){
        cout<<"key "<<'u'-maxx<<":　"<<shift(message,'u'-maxx)<<endl;
    }else{
        cout<<"I'm never decripting this message"<<endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "time taken: "<<duration.count() << " ms" << endl;
}

//Ashley's message: rcvo vmz rz cvqdib ajm gpixc ojyvt? rcvo yj tjp rvio oj zvo ajm ydiizm?