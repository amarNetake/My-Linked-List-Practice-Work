Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(head==NULL||head->next==NULL||K<=0||K>num)
    {
        return head;
    }
    
    if(K==1||K==num)
    {
        Node* itr=head;
        Node* temp;
        while(itr->next!=NULL)
        {
            temp=itr;
            itr=itr->next;;
        }
        itr->next=head->next;
        temp->next=head;
        head->next=NULL;
        head=itr;
        return head;
    }
    
    int n1=1;
    Node* itr1=head;
    Node* temp1;
    while(n1!=K)
    {
        temp1=itr1;
        itr1=itr1->next;
        n1++;
    }
    int n2=1;
    Node* itr2=head;
    Node* temp2;
    while(n2!=num-K+1)
    {
        temp2=itr2;
        itr2=itr2->next;
        n2++;
    }
    
    temp1->next=itr2;
    temp2->next=itr1;
    Node* temp;
    temp=itr1->next;
    itr1->next=itr2->next;
    itr2->next=temp;

    /*   OR   */
    /*
    	Simply use:-
    	
    	swap(prev1->next,prev2->next);
    	swap(itr1->next,itr2->next);
    */
    return head;
}