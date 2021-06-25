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

bool is_palindrome(Node* head)
{
    stack<int> s;
    Node* itr=head;
    while(itr!=NULL)
    {
        s.push(itr->data);
        itr=itr->next;
    }
    itr=head;
    while(itr!=NULL)
    {
        if(s.top()!=itr->data)
        {
            return false;
        }
        s.pop();
        itr=itr->next;
    }
    return true;
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
        bool palindrome=is_palindrome(head);
        palindrome?cout<<"Palindrome"<<"\n":cout<<"Not Palindrome"<<"\n";
    }
}


