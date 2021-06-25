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

Node* reverse(Node* head,int k)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* current=head;
    Node* prev=NULL;
    Node* after;
    int count=0;
    while(current!=NULL&&count<k)
    {
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
        count++;
    }
    if(current!=NULL)
    {
        head->next=reverse(current,k);
    }
    return prev;
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
        while(n--)
        {
            int data;
            cin>>data;
            insertNode(&head,data);
        }
        int k;  //Group size to reverse the list in size of k elements in groups
        cin>>k;
        head=reverse(head,k);
        printList(head);
    }
}