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
    
    unsigned int power(unsigned long long int a,int b)
    {
        if(b==0)
            return 1;
        unsigned int result=1;
        while(b>0)
        {
            if(b%2==1) 
            {
                result=result*a;
            }
            a=a*a;
            b=b/2;
        }
        return result;
    }

    int getDecimalValue(ListNode* head) {
        if(head==NULL)
        {
            return 0;
        }
        else if(head->next==NULL)
        {
            return head->val;
        }
        
        unsigned long long int result=0;
        ListNode* itr=head;
        int len=0;
        
        while(itr!=NULL)
        {
            itr=itr->next;
            len++;
        }
        
        itr=head;
        
        while(itr!=NULL)
        {
            result=result+ itr->val * power(2,--len);
            itr=itr->next;
        }
        return result;
    }
};