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
    cout<<head->data<<" ";

    Node* temp= head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    traverseList(head);
}