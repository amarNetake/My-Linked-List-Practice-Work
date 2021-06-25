Node* reverseDLL(Node * head)
{
    //Your code here
    Node* temp=head;
    Node* itr;
    while(temp!=NULL)
    {
        itr=temp;
        temp=temp->next;
        swap(itr->prev,itr->next);
    }
    return itr;
}