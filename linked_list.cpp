#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data=x;
        next=NULL;
    }    
};

void traverseList(Node *head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* InsertAtBegin(Node* head2, int x){
    Node* temp= new Node(x);
    if (head2==NULL){
        return temp;
    }
    else{
        temp->next= head2;
        return temp;
    }
}
int main(){
    
    Node *head = new Node(40);
    Node *temp1 = new Node(50);
    Node *temp2 = new Node(60);

    head->next = temp2;
    temp2->next = temp1;

    head = InsertAtBegin(head, 80);
    traverseList(head);

}

