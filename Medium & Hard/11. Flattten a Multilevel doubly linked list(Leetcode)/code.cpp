/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
        {
            return head;
        }
        Node* first=head->next;
        Node* second=head;
        while(first!=NULL)
        {
            if(second->child!=NULL)
            {
                second->next=flatten(second->child);  //flatten() will return the head of (i+1)th level linked list
                second->child=NULL;
                second->next->prev=second;
                while(second->next!=NULL)
                {
                    second=second->next;
                }
                second->next=first;
                first->prev=second;
            }
            second=first;
            first=first->next;
        }
        
        if(second->child!=NULL) //One more time for the last Node when 'second' points to last node and 'first' goes null
        {
            second->next=flatten(second->child);
            second->child=NULL;
            second->next->prev=second;
            while(second->next!=NULL)
            {
                second=second->next;
            }
            second->next=first;
        }
        return head;
    }
};