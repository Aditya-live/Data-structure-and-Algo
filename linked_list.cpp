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
Node* InsertAtEnd(Node* head2, int x){
    Node* temp = new Node(x);
    Node* temp2 = head2;

    if(head2==NULL){
        return temp;
    }
    while(head2->next != NULL){
        head2 = head2->next;
    }
    head2->next = temp;
    return temp2;
}

Node* deleteAtBegin(Node* head2){
    
    if (head2==NULL){
        return NULL;
    }
    else{
        Node* temp= head2->next;
        delete head2;
        return temp;
    }
}

int main(){
    
    Node *head = new Node(40);
    Node *temp1 = new Node(50);
    Node *temp2 = new Node(60);
    Node *temp3 = new Node(30);
    
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    // To insert at beginning
    head = InsertAtBegin(head, 80);

    // To insert at the end
    head= InsertAtEnd(head,20);

    // To delete at begin
    head= deleteAtBegin(head);

    // To traverse the linkedlist
    traverseList(head);

}

