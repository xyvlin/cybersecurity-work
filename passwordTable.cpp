#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void combinations(string p, int i, string c){
    if(p.size()!=i){
        for(int j=0;j<c.size();j++){
            combinations(p+c[j],i,c);
        }
    }
}

void password(string characters, int maxx){
    for(int i=4;i<=maxx;i++){
        auto start = high_resolution_clock::now();
        string p;
        combinations(p,i,characters);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << i<<" digits: "<< duration.count() << " ms" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen ("results.out","w",stdout);

    cout<<"numbers"<<endl;
    password("0123456789",9);

    cout<<"lowercase"<<endl;
    string letters = "";
    for(int i='a';i<='z';i++){
        letters+=(char)i;
    }
    password(letters,6);

    cout<<"+uppercase"<<endl;
    for(int i='A';i<='Z';i++){
        letters+=(char)i;
    }
    password(letters,5);

    cout<<"+numbers"<<endl;
    letters+="0123456789";
    password(letters,5);

    cout<<"+symbols"<<endl;
    letters="";
    for(int i=32;i<127;i++){
        letters+=(char)i;
    }
    password(letters,5);
}