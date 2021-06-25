ListNode* deleteDup(ListNode* head,ListNode* target)
{
    ListNode* itr=head;
    while(itr!=target)
    {
        ListNode* temp=itr->next;
        delete(itr);
        itr=temp;
    }
    return target;
}
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL)  return head;
    ListNode* first=head->next;
    ListNode* second=head;
    ListNode* prevS=NULL;
    while(first!=NULL)
    {
        while(first!=NULL && first->val==second->val)
        {
            first=first->next;
        }
        if(first!=second->next)
        {
            if(second==head)
            {
                second=deleteDup(second,first);
                head=second;
                if(first!=NULL) first=first->next;
            }
            else
            {
                second=deleteDup(second,first);
                prevS->next=second;
                if(first!=NULL) first=first->next;
            }
        }
        else
        {
            prevS=second;
            second=first;
            if(first!=NULL) first=first->next;
        }
    }
    return head;
}