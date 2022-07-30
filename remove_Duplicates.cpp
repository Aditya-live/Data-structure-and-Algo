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

Node* removeDuplicates(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if (curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
           curr = curr->next;
    }
    return head;
}


int main(){
    Node *head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(20);
    head->next->next->next= new Node(30);
    head->next->next->next->next= new Node(30);
    head->next->next->next->next->next= new Node(30);
    head->next->next->next->next->next->next= NULL;

    traverseList(head);
    head= removeDuplicates(head);
    traverseList(head);
}