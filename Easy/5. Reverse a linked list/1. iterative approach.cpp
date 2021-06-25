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
    Node* last=*head_ref;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
}

Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* prev=NULL;
    Node* current=head;
    while(current!=NULL)
    {
        Node* forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;
    }
    head=prev;
    return head;
}

void printList(Node* head)
{
    Node* itr=head;
    while(itr!=NULL)
    {
        cout<<itr->data<<" ";
        itr=itr->next;
    }
    cout<<"\n";
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
        
        //Insert n elements to the list
        while(n--)
        {
            int data;
            cin>>data;
            insertEnd(&head,data);
        }
        //Reverse the list
        head= reverseList(head);
        
        //Print the reversed list
        printList(head);
    }
}


