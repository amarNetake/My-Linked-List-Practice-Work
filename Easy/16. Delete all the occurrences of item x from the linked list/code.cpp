/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) // If linked list is empty
        {
            return head;
        }
        while(head!=NULL&&head->val==val)  //For truncating all the occurrences of 'val' at the beginning
        {
            ListNode* temp=head;
            head=head->next;
            delete(temp);
        }
        
        if(head==NULL)  //After removing all occurrences of val from beginning if list becomes empty
        {
            return head;
        }
        ListNode* itr=head->next; //Since now head->val cannot be the 'val' so start with head->next
        ListNode* temp=head;
        
        while(itr!=NULL)
        {
            if(itr->val==val)
            {
                temp->next=itr->next;
                delete(itr);
                itr=temp->next;
                continue;
            }
            itr=itr->next;
            temp=temp->next;
        }
        
        return head;
    }
};