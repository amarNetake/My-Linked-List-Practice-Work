// Time complexity = O(n) ; Space Complexity = O(1)
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

Node* segregate(Node *head) {
    
    Node* zeroHead=NULL; //Will hold head of zeros list(Note:- it will not create explicit list)
    Node* oneHead=NULL;  //Will hold head of ones list(Note:- it will not create explicit list)
    Node* twoHead=NULL;  //Will hold head of twos list(Note:- it will not create explicit list)
    Node* zero;   //It is the iterator of zero's list
    Node* one;	  //It is the iterator of one's list
    Node* two; 	  //It is the iterator of two's list
    Node*itr=head;
    while(itr!=NULL)
    {
        if(itr->data==0)
        {
            if(zeroHead==NULL)
            {
                zeroHead=itr;
                zero=zeroHead;
            }
            else
            {
                zero->next=itr;
                zero=zero->next;
            }
        }
        else if(itr->data==1)
        {
            if(oneHead==NULL)
            {
                oneHead=itr;
                one=oneHead;
            }
            else
            {
                one->next=itr;
                one=one->next;
            }
        }
        else if(itr->data==2)
        {
            if(twoHead==NULL)
            {
                twoHead=itr;
                two=twoHead;
            }
            else
            {
                two->next=itr;
                two=two->next;
            }
        }
        itr=itr->next;
    }
    
    if(zeroHead!=NULL)
    {
        zero->next=NULL;
    }
    if(oneHead!=NULL)
    {
        one->next=NULL;
    }
    if(twoHead!=NULL)
    {
        two->next=NULL;
    }
    
    if(zeroHead!=NULL&&oneHead!=NULL)
    {
        zero->next=oneHead;
        one->next=twoHead;
        return zeroHead;
    }
    else if(zeroHead==NULL&&oneHead!=NULL)
    {
        one->next=twoHead;
        return oneHead;
    }
    else if(zeroHead!=NULL&&oneHead==NULL)
    {
        zero->next=twoHead;
        return zeroHead;
    }
    else
    {
        return twoHead;
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
        head= segregate(head);
        
        //Print the reversed list
        printList(head);
    }
}


