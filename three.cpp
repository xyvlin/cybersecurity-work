#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
string passs1, passs2, passs3;
bool one, two, three;
int iter;

bool combinations(string p, int i, string c){
    if(p.size()==4) iter++;
    if(p==passs1) {
        one = true;
        cout<<"\t"<<p<<": "<<iter<<"\n";
    }
    if(p==passs2) {
        two = true;
        cout<<"\t"<<p<<": "<<iter<<"\n";
    }
    if(p==passs3) {
        three = true;
        cout<<"\t"<<p<<": "<<iter<<"\n";
    }
    if(one&&two&&three) return true;
    if(p.size()!=i){
        for(int j=0;j<c.size();j++){
            if(combinations(p+c[j],i,c)) return true;
        }
    }
    return false;
}

void password(string characters){
    cout<<"password 1: "<<endl;
    cin>>passs1;
    cout<<"password 2: "<<endl;
    cin>>passs2;
    cout<<"password 3: "<<endl;
    cin>>passs3;
    cout<<"cracked passwords:\n";
    auto start = high_resolution_clock::now();
    string p;
    combinations(p,4,characters);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double sec = duration.count()/1e6;
    cout << endl << sec << " seconds"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string letters="";
    for(int i=32;i<127;i++){
        letters+=(char)i;
    }
    password(letters);
}