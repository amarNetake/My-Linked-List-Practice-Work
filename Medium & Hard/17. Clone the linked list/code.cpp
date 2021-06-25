Node *copyList(Node *head) {
    // Your code here
    if(head==NULL)
    {
        return head;
    }
    Node* itr=head;
    Node* forward;
    while(itr!=NULL)
    {
        Node* new_node=new Node(itr->data);
        new_node->next=itr->next;
        itr->next=new_node;
        itr=itr->next->next;
    }

    Node* h=head->next;   //To store the head of cloned linked list.
    Node* first;         //Will iterate over the cloned linked list.
    Node* second=head;  //Will point to or iterate over original linked list.
    /*
        First take care of all the random pointers to avoid errors of disconnectivity 
        as we need linear access in the meantime to set all the node's random pointer
    */
    while(second!=NULL)  
    {
        first=second->next;
        /*
         Check if arb pointer of the 'second' node is NULL or not NULL.
         if so then second->arb->next may cause segmentation fault.
         NOTE that not all arb pointers are set. Some nodes have arb pointer value NULL.
        */
        if(second->arb!=NULL) 
        {
            first->arb=second->arb->next;
        }
        second=first->next;
    }

    first=head->next;
    second=head;

    //Now detach the original and cloned linked list by taking care of 'next' pointer values of each node
    while(second!=NULL)  
    {
        second->next=second->next->next;
        if(second->next!=NULL)
        {
            first->next=first->next->next;
        }
        second=second->next;
        first=first->next;
    }
    return h;
}