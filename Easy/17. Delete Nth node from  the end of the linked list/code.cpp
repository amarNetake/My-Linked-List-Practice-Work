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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            return head;
        }
        else if(head->next==NULL)
        {
            if(n==1)  //Means there is only one node and we have to delete that node only
            {
                return NULL;
            }
            else
            {
                return head;
            }
        }
    
        ListNode* itr1=head;
        ListNode* itr2;
        ListNode* temp;
        int count=n;
        while(count>0)
        {
            itr1=itr1->next;
            count--;
        }
        
        if(itr1==NULL)  //Means we have to delete the starting node itself
        {
            temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        
        itr2=head;
        while(itr1!=NULL)
        {
            temp=itr2;
            itr1=itr1->next;
            itr2=itr2->next;
        }
        temp->next=itr2->next;
        
        delete(itr2);
        
        return head;
    }
};