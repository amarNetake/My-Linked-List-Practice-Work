void splitList(Node* head,Node** first_ref,Node** second_ref)
{
    if(head==NULL&&head->next==NULL)
    {
        return;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    *first_ref=head;
    *second_ref=slow->next;
    (*second_ref)->prev=NULL;
    slow->next=NULL;
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
        if(result->next!=NULL)
        {
            result->next->prev=result;
        }
    }
    else if(first->data > second->data)
    {
        result=second;
        result->next=mergeTwoSortedLists(first,second->next);
        if(result->next!=NULL)
        {
            result->next->prev=result;
        }
    }
    return result;
}

struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(head==NULL||head->next==NULL)
	{
	    return head;
	}
	Node* first=NULL;
	Node* second=NULL;
	splitList(head,&first,&second);
	
    first=sortDoubly(first);
    second=sortDoubly(second);
    
    head=mergeTwoSortedLists(first,second);
    return head;
}