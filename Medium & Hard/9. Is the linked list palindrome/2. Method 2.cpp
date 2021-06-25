// Using the reversing the second half of linked list method.

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

Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    //Your code here
    if(head==NULL||head->next==NULL)
    {
        return true;
    }
    Node* fast=head->next;
    Node* slow=head;
    bool result=true;  //Initialized with true and if in future turns out to be false we will make it false
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverseList(slow->next);
    Node* itr1=head;
    Node* itr2=slow->next;
    while(itr2!=NULL)
    {
        if(itr1->data!=itr2->data)
        {
            result=false;
            break;
        }
        itr1=itr1->next;
        itr2=itr2->next;
    }
    slow->next=reverseList(slow->next); //Making the list back to as it was 
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
        int n;
        cin>>n;
        Node* head=NULL;
        while(n--)
        {
            int data;
            cin>>data;
            insertEnd(&head,data);
        }
        bool palindrome=isPalindrome(head);
        palindrome?cout<<"True"<<"\n":cout<<"False"<<"\n";
    }
}


