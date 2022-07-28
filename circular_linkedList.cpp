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
//Solution with O(1) time complexity
Node* deleteAtBegin(Node* head){
    if(head==NULL){
        return NULL;
    }
    if (head->next==head){
        delete head;
        return NULL; 
    }
    head->data= head->next->data;
    Node* temp= head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    if(k==1){
       Node* head2=  deleteAtBegin(head);
       return head2;
    }
    else{
        Node* curr= head->next;
        for(int i=0; i<k-2; i++){
            curr = curr->next;
        }
        curr->next=curr->next->next;
        delete(curr->next);
        return head;
    }
}

int main(){
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    //head = deleteAtBegin(head);
    //head = deleteKthNode(head, 2);
    traverseList(head);
}