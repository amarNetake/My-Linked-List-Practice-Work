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

void insertEnd(Node** head_ref, int new_data)
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

int LengthOfList(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int total=1;
    total=total+LengthOfList(head->next);
    return total;
}

Node* rotateList(Node* head,int k)
{
    
    int length=LengthOfList(head);
    k=k%length;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    int count=0;
    Node* h=head;
    Node* temp;
    while(count!=k)
    {
        temp=h;
        h=h->next;
        count++;
    }
    temp->next=NULL;
    Node* itr=h;
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }
    itr->next=head;
    return h;
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
	        insertEnd(&head,data);
	    }
	    int k;  //Rotation count
	    cin>>k;
	    head=rotateList(head,k);
	    printList(head);
	}
	return 0;
}
