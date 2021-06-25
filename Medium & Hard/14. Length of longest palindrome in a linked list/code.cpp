// function for counting the common elements
int countCommon(Node* first, Node* second)
{
    int count=0;
    
    // loop to count coomon in the list starting from node a and b
    while(first!=NULL&&second!=NULL)
    {
        // increment the count for same values
        if(first->data==second->data)
        {
            count++;
        }
        else
        {
            break;
        }
        first=first->next;
        second=second->next;
    }
    return count;
}

int maxPalindrome(Node *head)   //  main() function will invoke maxPalindrome(head)
{
    //Your code here
    int result=0;
    Node* curr=head;
    Node* prev=NULL;
    Node* forward;
    
    // loop till the end of the linked list 
    while(curr!=NULL)
    {
        // The sublist from head to curr reversed
        forward=curr->next;
        curr->next=prev;

        /*
         	check for odd length palindrome 
         	by finding longest common list elements 
         	beginning from prev and from next (We 
         	exclude curr)
        */
        result=max(result,2*countCommon(prev,forward)+1);

        /*
         	check for even length palindrome 
         	by finding longest common list elements 
         	beginning from curr and from next 
        */
        result=max(result,2*countCommon(curr,forward));

        // update prev and curr for next iteration
        prev=curr;
        curr=forward;
    }
    return result;
}