void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        Node* temp;
        if(fast==slow)
        {
            if(fast==head)  //If both fast and slow met at head
            {
                temp=fast->next;
                while(temp->next!=fast)
                {
                    temp=temp->next;
                }
                temp->next=NULL;
                return;
            }
            else
            {
                Node* itr=head;
                while(slow!=itr)
                {
                    itr=itr->next;
                    temp=slow;
                    slow=slow->next;
                }
                temp->next=NULL;
                return;
            }
        }
    }
}