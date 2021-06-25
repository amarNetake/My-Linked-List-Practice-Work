struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    Node* itr=head1;
    map<int,int> ma;  //Since we want sorted keys (Note: map STL is BST implementation)
    while(itr!=NULL)
    {
        ma[itr->data]++;  //Search takes O(logn) time in map STL
        itr=itr->next;
    }
    itr=head2;
    while(itr!=NULL)
    {
        ma[itr->data]++;
        itr=itr->next;
    }
    Node* h=NULL;
    Node* temp;
    for(auto x: ma)
    {
        Node* new_node=new Node(x.first);
        if(h==NULL)
        {
            h=new_node;
            temp=h;
        }
        else
        {
            temp->next=new_node;
            temp=temp->next;
        }
    }
    return h;
}