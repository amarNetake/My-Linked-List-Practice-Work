/*
    Reverse the second half of linked list. 
    Application:- Used to check if string is palindrome or not.
    Time complexity= O(n) Space complexity= O(1)

    For odd Nodes:- Reverse nodes next to the middle node.
    For even Nodes:- Reverse entire 2nd half of the list.
*/

#include <iostream>
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
Node* insertEnd(Node* head,int new_data)
{
    Node* new_node=new Node(new_data);
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    Node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return head;
}

Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* first=head;
    Node* rest=first->next;
    rest=reverseList(rest);
    first->next->next=first;
    first->next=NULL;
    return rest;
}

Node* halfReverse(Node* head)
{
	/*
		Initialize fast=head->next if you want to stop the slow pointer 
		at first node among two middle nodes when 
		length of list is even. This will stop at slow pointer at 
		middle node if length of list is odd 
		and at first among two middle nodes if length of list is even.
	*/
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
    Node* fast=head->next; 
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL) //Check if fast is NULL first before checking fast->next and ensure using &&
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverseList(slow->next);
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
int main() {
	
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
	    head=halfReverse(head);
	    printList(head);
	}
	return 0;
}
