#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
string passs;

bool combinations(string p, int i, string c){
    if(p==passs) return true;
    if(p.size()!=i){
        for(int j=0;j<c.size();j++){
            if(combinations(p+c[j],i,c)) return true;
        }
    }
    return false;
}

void password(string characters){
    cin>>passs;
    auto start = high_resolution_clock::now();
    string p;
    combinations(p,4,characters);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cout<<"numbers only: "<<endl;
    password("0123456789");

    cout<<"lowercase: "<<endl;
    string letters = "";
    for(int i='a';i<='z';i++){
        letters+=(char)i;
    }
    password(letters);

    cout<<"lower+uppercase: "<<endl;
    for(int i='A';i<='Z';i++){
        letters+=(char)i;
    }
    password(letters);

    cout<<"letters+numbers: "<<endl;
    letters="0123456789"+letters;
    password(letters);

    cout<<"all symbols: "<<endl;
    letters="";
    for(int i=32;i<127;i++){
        letters+=(char)i;
    }
    password(letters);
}