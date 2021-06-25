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

Node* findNode(Node* head,int item)
{
    Node* itr=head;
    while(itr!=NULL)
    {
        if(itr->data==item)
        {
            return itr;
        }
        itr=itr->next;
    }
    return NULL;
}

void deleteNode(Node* node)
{
   Node* prev=node;
   Node* current=node->next;
   while(current->next!=NULL)
   {
       swap(prev->data,current->data);
       prev=prev->next;
       current=current->next;
   }
   swap(prev->data,current->data);
   prev->next=NULL;
   free(current);
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
        int item;
        cin>>item;
        Node* node=findNode(head,item);
        if(node!=NULL)
        {
            deleteNode(node);
        }
        printList(head);
    }
    return 0;
}


















