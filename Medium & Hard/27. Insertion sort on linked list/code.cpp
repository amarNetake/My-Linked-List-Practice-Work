/*
	Here we keep    [unsorted...|....sorted] format and will sort from right to left as it will be easier for linked list. 
*/

ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)  return head;
        ListNode* curr=head;
        ListNode* itr=insertionSortList(head->next);
        while(itr!=NULL && itr->val < curr->val)
        {
            swap(itr->val,curr->val);
            curr=itr;
            itr=itr->next;
        }
        return head;
    }