Node * removeDuplicates( Node *head) 
{
    // your code goes here
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    unordered_map<int,int> ma;
    Node* itr=head;
    Node* prev;
    while(itr!=NULL)
    {
        if(ma.find(itr->data)==ma.end())  //If the data is current node has not appeared before.
        {
            prev=itr;
            ma[itr->data]=-1;  //Mark as visited once.
            itr=itr->next;
        }
        else
        {
            prev->next=itr->next;
            delete(itr);
            itr=prev->next;
        }
    }
    return head;
}