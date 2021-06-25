/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                //It can only happen that they meet at head if linked list is entirely cycle
                //But note that if they do not meet at head does not mean that head could not be the first node in cycle
                if(fast==head)  
                    return head;
                ListNode* temp=head; 
                while(slow!=temp)
                {
                    slow=slow->next;
                    temp=temp->next;
                }
                return temp;
            }
        }
        return NULL;
     }
};