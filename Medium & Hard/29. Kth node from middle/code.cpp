int findLen(ListNode* head)
 {
     if(head==NULL)  return 0;
     return 1 + findLen(head->next);
 }
 
 int findMiddle(ListNode* head,int n)
 {
     ListNode* fast=head;
     ListNode* slow=head;
     ListNode* itr=head;
     int count=0;
     while(fast!=NULL && fast->next!=NULL)
     {
         fast=fast->next->next;
         slow=slow->next;
         if(count<n)  count=count+1;
         else   itr=itr->next;
     }
     return itr->val;
 }
 
int Solution::solve(ListNode* head, int n)  //main() calls this
{
    if(head==NULL)  return n==0?0:-1;
    int len=findLen(head);
    if(n>=(len/2) + 1) return -1;
    int data=findMiddle(head,n);
    return data;
}