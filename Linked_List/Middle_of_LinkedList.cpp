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
//Finding middle of node
void findMiddle(Node *head){
    if(head==NULL){
        return;
    }
    Node* curr= head;
    while(curr != NULL && curr->next != NULL){
        head=head->next;
        curr=curr->next->next;
        
    }
    cout<<"The middle elem is "<<head->data<<endl;
}

int nthFromEnd(Node* head, int n){
    Node* temp = head;
    if (n==1){
        while(temp->next!=NULL){
        }
        return temp->data;
    }
    else{
        while(--n){
            temp=temp->next;       
        }
        while(temp->next!=NULL){
            head= head->next;
            temp= temp->next;
        }
    return head->data;
    }
}
int main(){

    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);
    Node* temp4 = new Node(70);

    head->next= temp1;
    temp1->next= temp2;
    temp2->next= temp3;
    temp3->next= temp4;
    temp4->next= NULL;

    //findMiddle(head);
    int elem = nthFromEnd(head, 2);
    cout<<"Nth elem is "<<elem<<endl;
    traverseList(head);
}