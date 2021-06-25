ListNode* reverseUtil(ListNode* first,ListNode* second,ListNode** temp_ref)
{
    if(first==second) 
    {
        *temp_ref=first->next;
        return first;
    }
    ListNode* curr=first;
    ListNode* rest=reverseUtil(first->next,second,temp_ref);
    curr->next->next=curr;
    curr->next=*temp_ref;
    return rest;
}
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) // main() invokes this
{
    if(head==NULL ||head->next==NULL)  return head;
    int count=1;
    ListNode* first=head;
    ListNode* prevf=NULL;
    ListNode* second=head;
    while(count!=m && first!=NULL)
    {
        prevf=first;
        first=first->next;
        count++;
    }
    count=1;
    while(count!=n && second!=NULL)
    {
        second=second->next;
        count++;
    }
    ListNode* temp=NULL;
    if(prevf==NULL) head=reverseUtil(first,second,&temp);  //if m==1
    else prevf->next=reverseUtil(first,second,&temp);
    return head;
}