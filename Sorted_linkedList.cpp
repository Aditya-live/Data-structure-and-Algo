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
}

Node* insert(Node* head, int val){
    Node* temp= new Node(val);
    if (head==NULL){
        return temp;
    }
    if (head->data > temp->data){
        temp->next= head;
        return temp;
    }
    else{
        Node* curr= head;
        while(curr->next!=NULL && curr->next->data < val){
            curr = curr->next;
        }
        temp->next= curr->next;
        curr->next= temp;
        return head;
        }
        
    }
int main(){

    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);

    head->next= temp1;
    temp1->next= temp2;
    temp2->next= temp3;
    temp3->next= NULL;

    head= insert(head, 45);
    traverseList(head);
}