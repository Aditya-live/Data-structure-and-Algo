#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void traverseList(Node *head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* reverseKSizedElem(Node *head, int k){
    
    
    Node *prev= NULL, *curr = head, *next=NULL;
    int count=0;
   

    while(curr!=NULL && count<k)
    {   
        next = curr->next;
        curr->next= prev;
        prev= curr;
        curr= next;
        count++;
    }
    if (next!=NULL)
    {
        Node* rest_head = reverseKSizedElem(next, k);
        head->next = rest_head;
    }    
    return prev;


}
int main(){
    Node *head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(40);
    head->next->next->next->next= new Node(50);
    head->next->next->next->next->next= new Node(60);
    head->next->next->next->next->next->next= NULL;
    
    //k is the lot size to be reversed.
    int k=3; 
    head= reverseKSizedElem(head, k);
    traverseList(head);
}