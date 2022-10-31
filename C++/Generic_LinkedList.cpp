
#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *next;
};

typedef struct node *lptr;

void insert(lptr &head,int num)
{
	lptr temp=new(node);
	temp->data=num;
	temp->next=NULL;
	lptr temp1=head;
	if(head==NULL)
	head=temp;
	else
	{
		while(temp1->next!=NULL)
		temp1=temp1->next;
		temp1->next=temp;
	}
}

void insertAfter(lptr P,int x,int y)
{
   if(P==NULL)
   {
       cout<<"empty"<<endl;
   }
   while(P->data!=x)
   {
       P=P->next;
   }
  lptr T;
  T=new(node);
  T->data=y;
  T->next=P->next;
  P->next=T;
}

void insertBefore(lptr P,int x,int y)
{
   if(P==NULL)
   {
       cout<<"empty"<<endl;
   }
   while(P->next->data!=x)
   {
       P=P->next;
   }
  lptr T;
  T=new(node);
  T->data=y;
  T->next=P->next;
  P->next=T;
}
void addfront(lptr &P,int k)
{
  lptr T;
  T=new(node);
  T->data=k;
  T->next=P;
  P=T;
}



void recprint(lptr P)
{
    if(P==NULL)
        return ;
    else
    {
        cout<<P->data<<" ";
        recprint(P->next);
    }
}


int main()
{
 lptr L=NULL;
 lptr P;
 int n,cnt=0;
 cin>>n;
 while(n!=-1)
 {
    insert(L,n);
    cin>>n;
    cnt++;
 }

 cout<<endl;
}
