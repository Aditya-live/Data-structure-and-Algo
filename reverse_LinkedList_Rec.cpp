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

Node* reverseListRec(Node*head){
    if (head==NULL || head->next==NULL)
    return head;
    Node* rest_head = reverseList(head->next);
    Node* rest_tail = head->next;
    rest_tail->next=head;
    head->next=NULL;

    return rest_head;
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

    traverseList(head);
    head= reverseListRec(head);
    traverseList(head);
}