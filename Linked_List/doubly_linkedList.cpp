#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* previous;
    Node* next;

    Node(int d){
        data = d;
        previous =  NULL;
        next = NULL;
    }
};

void traverseList(Node *head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertAtBegin(Node* head2, int x){
    Node* temp= new Node(x);
    if(head2==NULL){
        return temp;
    }
    else{
        temp->next=head2;
        temp->previous=NULL;
        head2->previous=temp;
        return temp;
    }
}
 
Node* reverseDoubly(Node* head2){
    if(head2==NULL || head2->next==NULL){
        return head2;
    }
    Node* temp=head2;
    Node* prev=NULL;
    while(temp!=NULL){
        prev=temp->previous;
        temp->previous=temp->next;
        temp->next=prev;
        temp=temp->previous;
    }
    return prev;
}

int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);

    head->next=temp1;
    temp1->next=temp2;
    temp1->previous=head;
    temp2->previous=temp1;
    temp2->next=temp3;
    temp3->previous=temp2;
    
    //To insert at the beginning of doubly linkedlist
   // head= insertAtBegin(head,50);

    //To reverse Doubly linkedlist
    head = reverseDoubly(head);
     // To traverse the linkedlist
    traverseList(head);

}