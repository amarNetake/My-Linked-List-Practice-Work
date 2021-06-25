void deleteAlt(struct Node *head){
    // Code here
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    Node* first=head->next;
    Node* second=head;
    Node* forward=first->next;
    second->next=forward;
    delete(first);
    deleteAlt(forward);
}
