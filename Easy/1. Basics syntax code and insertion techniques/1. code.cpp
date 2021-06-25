#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x)  //Constructor defined to make intialization and creation of node easy.
        {
            data=x;
            next=NULL;
        }
};

Node* insertAtBeginning(Node* head,int new_data)
{
    //creat and initialize new_node with data as new_data and next as NULL
    Node* new_node=new Node(new_data); 
    
    /* Since it was initialized as NULL by constructor but we 
       need it to hold the address from head here */
    new_node->next=head;
    head=new_node;
    return head;
}
Node* insertAtEnding(Node* head,int new_data)
{
    Node* new_node=new Node(new_data);
    Node* last=head;
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
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
        while(n--)
        {
            int item,position;
            cin>>item>>position;
            if(position==0)
            {
                head=insertAtBeginning(head,item);
            }
            else
            {
                head=insertAtEnding(head,item);
            }
        }
        printList(head);
    }
    return 0;
}




