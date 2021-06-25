// Similar algorithm as that of segregate 0s 1s and 2s in linked list OR Move all zeros to front of linked list
Node* segregateOddEven(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* oddH=NULL;
    Node* evenH=NULL;
    Node* odd;
    Node* even;
    Node* itr=head;
    while(itr!=NULL)
    {
        if((itr->data)%2==0)
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
        else 
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
        itr=itr->next;
    }
    if(evenH!=NULL && oddH!=NULL)
    {
        even->next=oddH;
        odd->next=NULL;
        return evenH;
    }
    else if(evenH==NULL&&oddH!=NULL)
    {
        odd->next=NULL;
        return oddH;
    }
    else if(evenH!=NULL&&oddH==NULL)
    {
        even->next=NULL;
        return evenH;
    }
}





