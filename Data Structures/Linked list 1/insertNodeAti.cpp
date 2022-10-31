#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* prev =NULL;
    while(data != -1){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            prev =n;
        }
        prev->next = n;
        prev = prev->next;
        

        cin>>data;
    }
    return head;
}

Node* insert(Node* head,int data,int pos){
    if(pos == 0){
        Node* n = new Node(data);
        n->next = head;
        return n;
    }
    
    int count =0;
    Node*  temp = head;
    while(temp != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }
    Node* n = new Node(data);
    n->next = temp->next;
    temp->next = n;
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
int main(){
    Node* head= takeInput();
    int data,pos;
    cin>>pos>>data;
    print(head);
    cout<<endl;
    head= insert(head,data,pos);
    print(head);
    return 0;
}