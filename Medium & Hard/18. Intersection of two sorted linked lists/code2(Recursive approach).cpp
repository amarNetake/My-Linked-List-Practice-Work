Node* findIntersection(Node* head1, Node* head2)  //Similar algo as merge 2 sorted linked lists
{
    // Your Code Here
    if(head1==NULL||head2==NULL)
    {
        return NULL;
    }
    Node* result;
    if(head1->data==head2->data)
    {
        Node* new_node=new Node(head1->data);
        result=new_node;
        result->next=findIntersection(head1->next,head2->next);
    }
    else if(head1->data < head2->data)
    {
        result=findIntersection(head1->next,head2);
    }
    else if(head1->data > head2->data)
    {
        result=findIntersection(head1,head2->next);
    }
    return result;
}