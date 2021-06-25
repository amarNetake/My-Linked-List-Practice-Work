//Merge 2 SORTED list in O(1) space and O(n+m) time.
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

void insertEnd(Node** head_ref,int new_data)
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

void printList(Node* head)
{
    Node *itr=head;
    while(itr!=NULL)
    {
        cout<<itr->data<<" ";
        itr=itr->next;
    }
    cout<<"\n";
}

Node* mergeSortedLists(Node* head_A,Node* head_B)
{
   if(head_A==NULL)
   {
    return head_B;
   }
   else if(head_B==NULL)
   {
    return head_A;
   }
   Node* result;
   if(head_A->data <= head_B->data)
   {
        result=head_A;
        result->next=mergeSortedLists(head_A->next,head_B);
   }
   else if(head_A->data > head_B->data)
   {
        result=head_B;
        result->next=mergeSortedLists(head_A,head_B->next);
   }
   return result;
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
        int n,m;
        cin>>n>>m;
        Node* head_A=NULL;
        Node* head_B=NULL;
        Node* head=NULL;
        while(n--)
        {
            int data;
            cin>>data;
            insertEnd(&head_A,data);
        }
        while(m--)
        {
            int data;
            cin>>data;
            insertEnd(&head_B,data);   
        }
        head=mergeSortedLists(head_A,head_B);
        printList(head);
    }
    return 0;
}


















