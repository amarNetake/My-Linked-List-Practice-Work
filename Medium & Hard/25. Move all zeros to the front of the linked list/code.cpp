/*
    The algorithm is very similar to what we used in segregate 0's 1's and 2's
*/

void moveZeroes(struct Node **head_ref)
{
    //Your code here
    Node* zeroH=NULL;
    Node* itr=*head_ref;
    Node* zero;
    Node* otherH=NULL;
    Node* other;
    while(itr!=NULL)
    {
        if(itr->data==0)
        {
            if(zeroH==NULL)
            {
                zeroH=itr;
                zero=zeroH;
            }
            else
            {
                zero->next=itr;
                zero=zero->next;
            }
        }
        else if(itr->data!=0)
        {
            if(otherH==NULL)
            {
                otherH=itr;
                other=otherH;
            }
            else
            {
                other->next=itr;
                other=other->next;
            }
        }
        itr=itr->next;
    }
    if(zeroH!=NULL&&otherH!=NULL)
    {
        zero->next=otherH;
        other->next=NULL;
        *head_ref=zeroH;
    }
    else if(zeroH==NULL&&otherH!=NULL)
    {
        other->next=NULL;
        *head_ref=otherH;
    }
    else if(zeroH!=NULL&&otherH==NULL)
    {
        zero->next=NULL;
        *head_ref=zeroH;
    }
}