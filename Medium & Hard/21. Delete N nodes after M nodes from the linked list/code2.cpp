Node* deleteNodes(Node* head,int N)
{
    int count=0;
    Node* temp;
    while(head!=NULL&&count!=N)
    {
        temp=head;
        head=head->next;
        count++;
        delete(temp);
    }
    return head;
}

void linkdelete(struct Node  *head, int M, int N)  //main() calls this function
{
    //Add code here  
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    
    Node* itr=head;
    Node* temp;
    int count=1;
    while(itr!=NULL)
    {
        while(itr!=NULL&&count!=M)
        {
            itr=itr->next;
            count++;
        }
        if(itr!=NULL)
        {
            itr->next=deleteNodes(itr->next,N);
            itr=itr->next;
            count=1;
        }
    }
}