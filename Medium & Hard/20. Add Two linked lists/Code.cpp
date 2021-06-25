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

void insertNode(Node** head_ref,int new_data)
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

Node* reverseList(Node* head)
{
    Node* current=head;
    Node* prev=NULL;
    Node* after;
    while(current!=NULL)
    {
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
    }
    return prev;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first=reverseList(first);
    second=reverseList(second);
    int carry=0;
    Node* head=NULL;
    while(first!=NULL||second!=NULL)
    {
        int data;
        if(first!=NULL&&second!=NULL)
        {
            data=first->data+second->data+carry;
            first=first->next;
            second=second->next;
        }
        else if(first!=NULL&&second==NULL)
        {
            data=first->data+carry;
            first=first->next;
        }
        else if(second!=NULL&&first==NULL)
        {
            data=second->data+carry;
            second=second->next;
        }
        Node* new_node=new Node(data%10);
        carry=data/10;
        if(head==NULL)
        {
            head=new_node;
        }
        else
        {
            new_node->next=head;
            head=new_node;
        }
    }
    if(carry>0)
    {
        Node* new_node=new Node(carry);
        if(head==NULL)
        {
            head=new_node;
        }
        else
        {
            new_node->next=head;
            head=new_node;
        }
    }
    first=reverseList(first);
    second=reverseList(second);
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
        int n,m;
        cin>>n;
        Node* head=NULL;
        Node* first=NULL;
        Node* second=NULL;
        while(n--)
        {
            int data;
            cin>>data;
            insertNode(&first,data);
        }
        cin>>m;
        while(m--)
        {
            int data;
            cin>>data;
            insertNode(&second,data);
        }
        head=addTwoLists(first,second);
        printList(head);
    }
}