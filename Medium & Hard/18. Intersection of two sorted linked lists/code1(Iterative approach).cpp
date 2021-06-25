Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==NULL||head2==NULL)
    {
        return NULL;
    }
    Node* head=NULL;
    Node* temp;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head==NULL)
        {
            if(head1->data==head2->data)
            {
                Node* new_node=new Node(head1->data);
                head=new_node;
                temp=head;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1->data < head2->data)
            {
                head1=head1->next;
            }
            else
            {
                head2=head2->next;
            }
        }
        else
        {
            if(head1->data==head2->data)
            {
                Node* new_node=new Node(head1->data);
                temp->next=new_node;
                temp=temp->next;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1->data < head2->data)
            {
                head1=head1->next;
            }
            else
            {
                head2=head2->next;
            }
        }
    }
    return head;
}