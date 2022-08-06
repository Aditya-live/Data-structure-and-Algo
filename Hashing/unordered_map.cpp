#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<char, int> m;
    m['g'] = 20;
    m['a'] = 10;
    m.insert({'t',40});
    m.erase()
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    if(m.find('a')!=m.end()){
        cout<<"found";
    }
    else{
        cout<<"Not found";
    }

    auto it = m.find('t'){
        cout<<it->first<<" "<<it->second<<endl;
    }
}