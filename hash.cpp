#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll p = 11111;
ll m = 1e9+9;

ll HASH(string s){
    ll hash = 0;
    ll power = 1;
    ll n = s.size();
    for(ll i=0;i<n;i++){
        hash^=((int)s[i]*power)%m;
        power = (power*p)%m;
        hash = (hash*33)^(hash>>5);
    }
    hash ^= hash<<2;
    return hash;
}

int main()
{
    string txt;
    for(int i=0;i<5;i++){
        cout<<"input: ";
        getline(cin,txt);
        cout<<"hash value: "<<HASH(txt)<<endl;
    }
}
