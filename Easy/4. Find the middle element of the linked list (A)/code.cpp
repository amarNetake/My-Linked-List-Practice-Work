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
Node* insertEnd(Node* head, int item)
{
    Node* new_node=new Node(item);
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
int findMiddle(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    /*
      First check if fast!=NULL as if fast is NULL then going for checking fast->next is NULL 
      or not will definately give an error if fast is or becomes NULL at some point. All we 
      are doing is preventing from the scenario of NULL->next as NULl->next is not defined 
      and will throw an error.
    */
    while(fast!=NULL&&fast->next!=NULL) 
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
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
            head=insertEnd(head,data);
        }
        int middle=findMiddle(head);
        cout<<middle<<"\n";
    }
}
