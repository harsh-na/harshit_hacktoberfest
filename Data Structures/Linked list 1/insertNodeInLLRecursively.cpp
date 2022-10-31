/*Problem Statement: Insert in LL recursively
Problem Level: EASY
Problem Description:
Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Line 3 : Integer n (Node to be inserted)

Output format :
Updated LL elements (separated by space)

Sample Input 1 :
3 4 5 2 6 1 9 -1
3
100

Sample Output 1 :
3 4 5 100 2 6 1 9

Sample Input 2 :
3 4 5 2 6 1 9 -1
0
20

Sample Output 2 :
20 3 4 5 2 6 1 9*/

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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
Node* insert(Node* head,int pos,int data){
    if(pos == 0){
        Node* n = new Node(data);
        n->next = head;
        return n;
    }
    if(pos == 1){
        Node* n = new Node(data);
        Node* x= head->next;
        n->next = x;
        head->next = n;
    }
    insert(head->next,pos-1,data);
    return head;
}

int main(){
    Node* head= takeInput();
    int pos,data;
    cin>>pos>>data;
    print(head);
    cout<<endl;
    head =insert(head,pos,data);
    print(head);
    return 0;
}