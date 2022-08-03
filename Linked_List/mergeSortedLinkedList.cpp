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

Node* mergeSortedList(Node *head1, Node *head2){
    if (head1==NULL)
        return head2;
    if (head2==NULL)
        return head1;

    Node* temp=NULL;
    Node* curr1=head1, *curr2=head2;
    Node* head = curr1->data<curr2->data ? curr1 : curr2;
    while(curr1!=NULL && curr2!=NULL){
       if (curr1->data<=curr2->data){
        temp = curr1->next;
        curr1->next = curr2;
        curr1=temp;
       }
       else{
        temp = curr2->next;
        curr2->next = curr1;
        curr2=temp;
       }
    }
    return head;
}
int main(){
    Node *head1= new Node(10);
    Node* temp1= new Node(20);
    Node* temp2= new Node(30);
    Node* temp3= new Node(40);

    Node* head2= new Node(15);
    Node* temp4= new Node(25);
    Node* temp5= new Node(35);


    head1->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=NULL;
    head2->next=temp4;
    temp4->next=temp5;
    temp5->next=NULL;

    traverseList(head1);
    traverseList(head2);
    Node* merged_list = mergeSortedList(head1,head2);
    traverseList(merged_list);
}