ListNode* Solution::partition(ListNode* head, int key) {
    if(head==NULL) return NULL;
    ListNode* greaterH=NULL;
    ListNode* greater=NULL;
    ListNode* lesserH=NULL;
    ListNode* lesser=NULL;
    ListNode* itr=head;
    while(itr!=NULL)
    {
        if(itr->val < key)
        {
            if(lesserH==NULL)  
            {
                lesserH=itr;
                lesser=lesserH;
            }
            else
            {
                lesser->next=itr;
                lesser=lesser->next;
            }
        }
        else
        {
            if(greaterH==NULL)
            {
                greaterH=itr;
                greater=greaterH;
            }
            else
            {
                greater->next=itr;
                greater=greater->next;
            }
        }
        itr=itr->next;
    }
    if(greaterH==NULL && lesserH!=NULL)
    {
        lesser->next=NULL;
        return lesserH;
    }
    else if(lesserH==NULL && greaterH!=NULL)
    {
        greater->next=NULL;
        return greaterH;
    }
    lesser->next=greaterH;
    greater->next=NULL;
    return lesserH;
    
}