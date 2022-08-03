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
Node* findIntersection(Node* head1, Node* head2){
    Node* temp= head1;
    int count1=0, count2=0;
    while(temp!=NULL){
        count1++;
    }
    temp=head2;
    while(temp!=NULL){
        count2++;
    }
    int diff = abs(count1-count2);
    cout<<diff;
    if (count1>=count2){
        while(diff--){
            head1=head1->next;
        }
    }
    else{
        while(diff--){
            head2=head2->next;
        }
    }
    while(head1!=NULL || head2!=NULL){
        if (head1==head2){
            return head1;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return temp;
}
int main(){
    Node *head1= new Node(1);
    Node* temp1= new Node(2);
    Node* temp2= new Node(3);
    Node* temp3= new Node(4);
    Node* temp4= new Node(5);
    head1->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=NULL;

    Node* head2 = new Node(7);
    Node* temp5 = new Node(8);
    head2->next= temp5;
    temp5->next= temp3;

    Node* common_node = findIntersection(head1, head2);
    cout<< common_node<<endl;

}