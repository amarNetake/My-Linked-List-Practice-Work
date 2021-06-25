ListNode* reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL)  return head;
    ListNode* curr=head;
    ListNode* rest=reverse(head->next);
    curr->next->next=curr;
    curr->next=NULL;
    return rest;
}
ListNode* mergeTwoLists(ListNode* first,ListNode* second,int count)
{
    if(first==NULL) return second;
    else if(second==NULL)  return first;
    ListNode* result=NULL;
    if(count%2==1)
    {
        result=first;
        result->next=mergeTwoLists(first->next,second,count+1);
    }
    else
    {
        result=second;
        result->next=mergeTwoLists(first,second->next,count+1);
    }
    return result;
}
 
ListNode* Solution::reorderList(ListNode* head)   // main() invokes this
{
    if(head==NULL || head->next==NULL)  return head;
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* first=head;
    ListNode* second;
    second=reverse(slow->next);
    slow->next=NULL;
    head=mergeTwoLists(first,second,1);
    return head;
}