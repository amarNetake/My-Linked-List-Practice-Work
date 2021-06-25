//Reverse the given linked list between the given positions in one single pass.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void insertEnd(Node** head_ref, int new_data)
{
    Node* new_node=new Node(new_data);
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    Node* last=*head_ref;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
}

Node* reverseStartToEnd(Node* head,int start,int end)
{
    if(head==NULL||head->next==NULL||start>=end||end==1)
    {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    while(start>1)
    {
        prev=curr;
        curr=curr->next;
        start--;
        end--;
    }
    Node* previous=prev;
    Node* current=curr;
    Node* after;
    while(end>0&&curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
        end--;
    }
    
    if(previous!=NULL)
    {
        previous->next=prev;
    }
    current->next=curr;
    if(previous==NULL)
    {
        return prev;
    }
    else 
    {
        return head;
    }
}


void printList(Node* head)
{
    Node* itr=head;
    while(itr!=NULL)
    {
        cout<<itr->data<<" ";
        itr=itr->next;
    }
    cout<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Node* head=NULL;
        while(n--)
        {
            int data;
            cin>>data;
            insertEnd(&head,data);
        }
        int start,end;
        cin>>start>>end;
        head=reverseStartToEnd(head,start,end);
        printList(head);
    }
}

















