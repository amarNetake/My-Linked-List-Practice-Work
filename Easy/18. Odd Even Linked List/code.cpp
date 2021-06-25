
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return head;
        }
        ListNode* oddPosH=NULL;
        ListNode* oddPos;
        ListNode* evenPosH=NULL;
        ListNode* evenPos;
        ListNode* itr=head;
        int count=1;
        while(itr!=NULL)
        {
            if(count%2==1)
            {
                if(oddPosH==NULL)
                {
                    oddPosH=itr;
                    oddPos=oddPosH;
                }
                else
                {
                    oddPos->next=itr;
                    oddPos=oddPos->next;
                }
            }
            else if(count%2==0)
            {
                if(evenPosH==NULL)
                {
                    evenPosH=itr;
                    evenPos=evenPosH;
                }
                else
                {
                    evenPos->next=itr;
                    evenPos=evenPos->next;
                }
            }
            itr=itr->next;
            count++;
        }
        oddPos->next=evenPosH;
        evenPos->next=NULL;
        return oddPosH;
    }
};