#include<iostream>
#include<set>
using namespace std;

struct Node{
    int data;
    Node* next;
    bool visited;

    Node(int d){
        data = d;
        next = NULL;
        visited=false;
    }
};
bool detectLoop(Node *head){
    if(head==NULL){
        return false;
    }
    Node* curr = head;
    while(curr!=NULL){
        if (curr->visited==true){
            return true;
        }
        else{
            curr->visited=true;
            curr=curr->next;
        }   
    }
    return false;
}

//Using hash method to find loop
bool isLoop(Node* head){
    set<Node*> s;
    for(Node* curr=head; curr!=NULL; curr=curr->next){
        if(s.find(curr)!=s.end()){
            return true;
        }
        else{
            s.insert(curr);
        }
    }
    return false;
}
int main(){
    Node *head= new Node(10);
    Node* temp1= new Node(20);
    Node* temp2= new Node(20);
    Node* temp3= new Node(20);
    Node* temp4= new Node(20);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=NULL;

    bool ans = detectLoop(head);
    bool res = detectLoop(head);
    cout<<res<<endl<<ans;
}
