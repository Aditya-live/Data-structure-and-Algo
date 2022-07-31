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
//Loop detection using Floyd Cycle detection
bool isLoop(Node * head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    else{
        Node* slow_p= head;
        Node* fast_p= head;
        while(fast_p != NULL && fast_p->next != NULL){
            fast_p = fast_p->next->next;
            slow_p = slow_p->next;
            if (fast_p==slow_p){
                return true;
            }
        }
    }
    return false;
}
int main(){
    Node *head= new Node(10);
    Node* temp1= new Node(20);
    Node* temp2= new Node(20);
    Node* temp3= new Node(20);
    Node* temp4= new Node(20);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp2;

    bool res= isLoop(head);
    cout<<res<<endl;


}