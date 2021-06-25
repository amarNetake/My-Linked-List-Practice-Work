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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        ListNode* h=NULL;
        ListNode* itr;
    
        while(l1!=NULL&&l2!=NULL)
        {
            if(h==NULL)
            {
                if(l1->val<=l2->val)
                {
                    h=l1;
                    itr=h;
                    l1=l1->next;
                }
                else if(l2->val<l1->val)
                {
                    h=l2;
                    itr=h;
                    l2=l2->next;
                }
            }
            
            else
            {
                if(l1->val<=l2->val)
                {
                    itr->next=l1;
                    itr=itr->next;
                    l1=l1->next;
                }
                else if(l2->val<l1->val)
                {
                    itr->next=l2;
                    itr=itr->next;
                    l2=l2->next;
                }
            }  
        }
        if(l1!=NULL)
        {
            itr->next=l1;
        }
        else if(l2!=NULL)
        {
            itr->next=l2;
        }
        return h;
    }
};