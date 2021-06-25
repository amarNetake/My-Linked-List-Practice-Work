ListNode* reverse(ListNode* head)
 {
     if(head->next==NULL) return head;
     ListNode* curr=head;
     ListNode* rest=reverse(head->next);
     curr->next->next=curr;
     curr->next=NULL;
     return rest;
 }
 
 ListNode* mergeTwoLists(ListNode* oddH,ListNode* evenH,int count)
 {
     if(oddH==NULL)  return evenH;
     else if(evenH==NULL)  return oddH;
     ListNode* result=NULL;
     if(count%2==1)
     {
         result=oddH;
         result->next=mergeTwoLists(oddH->next,evenH,count+1);
     }
     else
     {
         result=evenH;
         result->next=mergeTwoLists(oddH,evenH->next,count+1);
     }
     return result;
 }
 
ListNode* Solution::solve(ListNode* head)   // main() invokes this
{
    if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
    ListNode* evenH=NULL;
    ListNode* even;
    ListNode* oddH=NULL;
    ListNode* odd;
    int count=1;
    ListNode* itr=head;
    while(itr!=NULL)
    {
        if(count%2==1)
        {
            if(oddH==NULL)
            {
                oddH=itr;
                odd=oddH;
            }
            else
            {
                odd->next=itr;
                odd=odd->next;
            }
        }
        else if(count%2==0)
        {
            if(evenH==NULL)
            {
                evenH=itr;
                even=evenH;
            }
            else
            {
                even->next=itr;
                even=even->next;
            }
        }
        count++;
        itr=itr->next;
    }
    evenH=reverse(evenH);
    head=mergeTwoLists(oddH,evenH,1);
    return head;
}