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
Node* InsertAtBegin(Node* head2, int x){
    Node* temp= new Node(x);
    if (head2==NULL){
        return temp;
    }
    else{
        temp->next= head2;
        return temp;
    }
}
Node* InsertAtEnd(Node* head2, int x){
    Node* temp = new Node(x);
    Node* temp2 = head2;

    if(head2==NULL){
        return temp;
    }
    while(head2->next != NULL){
        head2 = head2->next;
    }
    head2->next = temp;
    return temp2;
}

Node* deleteAtBegin(Node* head2){
    
    if (head2==NULL){
        return NULL;
    }
    else{
        Node* temp= head2->next;
        delete head2;
        return temp;
    }
}
Node* deleteAtEnd(Node* head2){
    if(head2==NULL){
        return NULL;
    }
    if(head2->next==NULL){
        delete head2;
        return NULL;
    }
    Node* temp= head2;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head2;
}
    
Node* insertAtPosition(Node* head2, int pos, int x){
    int count=0;
    Node* temp = head2;
    Node* node = new Node(x);
    if (pos==1){
        node->next=head2;
        return node;
    }
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if (pos>=count+1){
        return head2;
    }
    temp = head2;
    pos=pos-2;
    while(pos--){
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;

    return head2;
}
int searchForElement(Node* head2, int x){
    int pos=1;
    while(head2!=NULL){
        if (head2->data==x){
            return pos;
        }
        else{
            pos++;
            head2=head2->next;
        }    
    }
    return -1;
}


int main(){
    
    Node *head = new Node(40);
    Node *temp1 = new Node(50);
    Node *temp2 = new Node(60);
    Node *temp3 = new Node(30);
    
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    // To insert at beginning
    // head = InsertAtBegin(head, 80);

    // To insert at the end
    // head= InsertAtEnd(head,20);

    // To delete at begin
    // head= deleteAtBegin(head);

    // To delete at end
    // head= deleteAtEnd(head);

    //To insert at a postion
    //insertAtPosition(head,1,20);

    //To search for an element in LinkedList
    int pos = searchForElement(head, 40);
    cout<<"Position of element is: "<<pos<<endl;
    // To traverse the linkedlist
    traverseList(head);
}