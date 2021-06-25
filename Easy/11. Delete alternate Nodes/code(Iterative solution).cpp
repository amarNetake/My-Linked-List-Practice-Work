void deleteAlt(struct Node *head){
    // Code here
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    Node* itr=head;
    while(itr!=NULL&&itr->next!=NULL)
    {
        Node* temp=itr->next;
        itr->next=itr->next->next;
        delete(temp);
        itr=itr->next;
    }
}