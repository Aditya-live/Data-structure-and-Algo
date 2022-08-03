#include<iostream>

using  namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x){
        data = x;
        next = NULL;
        random = NULL;
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
Node* cloneLinkedList(Node *head){
    if (head==NULL) return head;
    Node* curr=head;
    while(curr->next!=NULL){
        Node* nex= curr->next;
        curr->next= new Node(curr->data);
        curr->next->next=nex;
        curr= nex;
    }
    for(Node* curr=head; curr->next!=NULL; curr= curr->next){
        curr->next->random = (curr->random!=NULL) ? curr->random : NULL;
    }
    Node* head2= head->next;

    while(curr->next!=NULL){
        Node* temp=curr->next;
        curr->next=curr->next->next;
        curr=temp;
    }
    curr->next=NULL;
    return head2;
} 
int main(){
    Node *head = new Node(1);
    Node* temp1= new Node(2);
    Node* temp2= new Node(3);
    Node* temp3= new Node(4);
    Node* temp4= new Node(5);

    head->next=temp1;
    head->random= temp2;
    temp1->next=temp2;
    temp1->random= temp3;
    temp2->next=temp3;
    temp2->random=head;
    temp3->next=temp4;
    temp4->random=temp3;
    temp4->next=NULL;
    temp4->random=temp3;

    traverseList(head);
    Node* head2 = cloneLinkedList(head);
    traverseList(head2);
}