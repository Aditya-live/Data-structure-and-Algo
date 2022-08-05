#include<iostream>
#include<unordered_set>

using  namespace std;

void traverseSet(unordered_set<int> s){
    for(auto it =s.begin(); it !=s.end(); it++){
        cout << *it << " ";    
    }
    cout<<endl;
}
int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(45);
    traverseSet(s);
    s.erase(30);
    traverseSet(s);
    cout<<s.size()<<endl;

    if (s.find(20)==s.end())
        cout<<"No such element"<<endl;
    else
        cout<<"Element is present"<<endl;
}