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

//Loop to print all elems of linked list
void traverseList(Node *head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* segregateList(Node* head){

    Node* curr= head;
    Node* even_head=NULL, *even_tail=NULL, *odd_head=NULL, *odd_tail=NULL;
    
    for(Node* curr=head; curr!=NULL; curr= curr->next){
        int x= curr->data;
        if(x % 2==0){
           if(even_head= NULL){
                 even_head=curr;
                even_tail=even_head;
           }
           else{
                even_tail->next=curr;
                even_tail=even_tail->next;
           }
        }
        else{
            if(odd_head= NULL){
                odd_head=curr;
                odd_tail= odd_head;    
            }
            else{
               odd_tail->next=curr;
               odd_tail= odd_tail->next;
            }
        }   
    }
    if (odd_head ==NULL || even_head ==NULL){
        return head;
    }
    even_tail->next = odd_head;
    odd_tail->next=NULL;
    return even_head;
}

int main(){
    Node *head= new Node(1);
    Node* temp1= new Node(2);
    Node* temp2= new Node(3);
    Node* temp3= new Node(4);
    Node* temp4= new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=NULL;

    traverseList(head);
    //head= segregateList(head);
    traverseList(head);
}