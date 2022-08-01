#include<iostream>

using  namespace std;

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

Node* pairWiseSwap(Node* head){
    Node* curr= head->next->next;
    Node* prev= head;
    head= head->next;
    head->next= prev;
    while(curr!=NULL && curr->next!=NULL){
        prev->next= curr->next;
        prev = curr;
        Node* next = curr->next->next;
        curr->next->next = curr;
        curr= next;
    }
    prev->next=curr;
    return head;
}

int main(){
    Node *head= new Node(1);
    Node* temp1= new Node(2);
    Node* temp2= new Node(3);
    Node* temp3= new Node(4);
    Node* temp4= new Node(5);
    Node* temp5= new Node(6);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    temp5->next=NULL;

    traverseList(head);
    head = pairWiseSwap(head);
    traverseList(head);
}