#include<bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
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
void insertAtEnding(Node** head_ref,int new_data)
{
    Node* new_node=new Node(new_data);
    Node* last= *head_ref;
    
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
Node* deleteNode(Node* head,int k)
{
    Node* itr=head;
    Node* temp;
    int loc=1;
    while(itr!=NULL)
    {
        if(loc==k)  //If the node to be deleted is the position at which itr is present
        {
        	if(itr==head)  //This will happen if k is 1 OR first node is asked to delete
        	{
        		temp=head;
        		head=head->next;
        		delete(temp);
        		return head;
        	}
        	else  
        	{
        		temp->next=itr->next;
        		delete(itr);
        		return head;
        	}
        }
        temp=itr;	//temp is actually pointing to the previous node and itr to the node to be deleted
        itr=itr->next;
        loc++;
    }
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
        //This is important to initialize the head with NULL to avoid discrepency
        Node* head=NULL;  
        int n;
        cin>>n;
        loop(n)
        {
            int item;
            cin>>item;
            insertAtEnding(&head,item);
        }
        
        int k; //Element at position k is to be deleted
        cin>>k;
        head=deleteNode(head,k);
        //Print the list
        printList(head);
    }
}