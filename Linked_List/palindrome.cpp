#include<iostream>

using  namespace std;

struct Node {
    char data;
    Node* next;
    Node(char x){
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
Node* reverseList(Node *head){
    
    Node* curr = head;
    Node* prev= NULL;
     
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
    }

bool isPalindrome(Node* head){
    if(head==NULL){
        return true;
    }
    Node* fast= head;
    Node* slow= head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        }
    Node* rev = reverseList(slow->next);
    Node* curr=head;
    while(rev!=NULL){
        if(curr->data!=rev->data){
            return false;
        curr=curr->next;
        rev=rev->next;
        }
    }
    return true;
}
int main(){
    Node *head = new Node('r');
    Node *temp1 = new Node('a');
    Node *temp2 = new Node('d');
    Node *temp3 = new Node('a');
    Node *temp4 = new Node('r');
    
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = NULL;
    traverseList(head);
    bool res = isPalindrome(head);
    cout<<res;
}