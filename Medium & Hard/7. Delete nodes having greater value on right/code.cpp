/*
Method 2 (Use Reverse):-
1. Reverse the list.
2. Traverse the reversed list. Keep max till now. 
3. If next node is less than max, then delete the next node, otherwise max = next node.
4. Reverse the list again to retain the original order.

Time Complexity: O(n)
*/

/*
	NOTE:- (V.V.Imp)
	1. Delete a node if there is any value greater in its 
	right(right means right side no need to be immediate right)
	2. This also can be said like this delete all the nodes lesser than the current node in its left.
	3. So after reversing the list we can say that delete all the nodes which are lesser than it in its right.
	4. Once doing step 3 then reverse back the list to get the desired list.
*/
Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* first=head;
    Node* rest=reverseList(head->next);
    first->next->next=first;
    first->next=NULL;
    return rest;
}

Node *compute(Node *head)
{
    // your code goes here
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    head=reverseList(head);
    
    Node* max=head;
    Node* itr=head->next;
    while(itr!=NULL)
    {
        if(itr->data > max->data)
        {
            max=itr;
            itr=itr->next;
        }
        else if(itr->data < max->data)
        {
            Node* temp=itr;
            itr=itr->next;
            max->next=itr;
            delete(temp);
        }
    }
    
    head=reverseList(head);
    
    return head;
}