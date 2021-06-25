//Merge sort on the linked list
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
    Node* itr=head;
    while(itr!=NULL)
    {
        cout<<itr->data<<" ";
        itr=itr->next;
    }
    cout<<"\n";
}

void splitList(Node* head,Node** first_ref,Node** second_ref)
{
    /*
    Similar to algo of finding middle element of linked list the
    only difference here is in case of even number of nodes slow will stop
    at the last node of first half and not at the first node of second half
    */
    Node* fast=head->next; //Start with fast=head->next to stop at first of 2 middle nodes when total nodes are even
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* temp=slow;
    slow=slow->next;
    temp->next=NULL;   // Make the split or break the list in 2 halfs by putting NULL in the last node of first half.
    *first_ref=head;   //Make the 'first' to point to first half of the list. 
    *second_ref=slow;  //Make the 'second' to point to first node of second half. 
}

Node* mergeTwoSortedLists(Node* first,Node* second)
{
    if(first==NULL)
    {
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
    Node* result;
    if(first->data <= second->data)
    {
        result=first;
        result->next=mergeTwoSortedLists(first->next,second);
    }
    else if(first->data > second->data)
    {
        result=second;
        result->next=mergeTwoSortedLists(first,second->next);
    }
    return result;
}

Node* mergeSort(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    
    Node* first;    //Will hold the first half of the input list
    Node* second;   //Will hold the second half of the input list
    
    /*
    Break the list in 2 halfs and put NULL in the last node of first
    half and alter the first and second pointers to point to the respective lists
    */
    splitList(head,&first,&second);  
    
    first=mergeSort(first);  //Sort the first half of the linked list obtained
    second=mergeSort(second); //Sort the second half of list obtained 
    
    head=mergeTwoSortedLists(first,second);
    return head;
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
        head=mergeSort(head);
        printList(head);
    }
}

























