// Delete every N nodes after M nodes of linked list.
void linkdelete(struct Node  *head, int M, int N)
{
    //Add code here   
    if(head==NULL)
    {
        return;
    }
    Node* itr1=head;
    Node* itr2;
    Node* temp;
    int m=1,n=1;
    while(itr1!=NULL)
    {
        if(m==M)
        {
            itr2=itr1->next;
            while(itr2!=NULL && n<=N)
            {
                temp=itr2;
                itr2=itr2->next;
                delete(temp);
                n++;
            }
            itr1->next=itr2;
            itr1=itr1->next;
            m=1;
            n=1;
        }
        else
        {
            itr1=itr1->next;
            m++;
        }
    }
}