/*Problem Statement: Swap two Nodes of LL
Problem Level: MEDIUM
Problem Description:
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th'  and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70*/

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
        }else{
        prev->next = n;
        prev = prev->next;
        }

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
 Node* swap(Node*head,int i,int j){
     int x =0;
     Node* temp =head,*prev = NULL;
       Node* node1 = NULL,*node2 =NULL,*node1_prev=NULL,*node2_prev=NULL;
       while(temp != NULL){
           if(x == i){
               node1_prev = prev;
               node1 = temp;
           }else if(x == j){
               node2_prev = prev;
               node2 = temp;
           }
           prev = temp;
           temp = temp->next;
           x++;
       }
       if(node1_prev != NULL){
           node1_prev->next = node2;
       }else{
           head = node2;
       }
       if(node2_prev != NULL){
           node2_prev->next = node1;
       }else{
           head = node1;
       }
       Node* temp1 = node2->next;
       node2->next = node1->next;
       node1->next = temp1;
       return head;
 }

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();
        int i,j,x=0;
        cin>>i>>j;
       swap(head,i,j);
       print(head);

    }
    return 0;
}