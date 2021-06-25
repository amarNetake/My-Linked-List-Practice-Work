int countPairs(struct Node* head1, struct Node* head2, int x) {
    // Code here
    if(head1==NULL||head2==NULL)
    {
        return 0;
    }
    Node* itr=head1;
    unordered_map<int,int> ma;
    while(itr!=NULL)
    {
        ma[itr->data]++;
        itr=itr->next;
    }
    itr=head2;
    int count=0;
    while(itr!=NULL)
    {
        int target=x - itr->data;
        if(ma.find(target)!=ma.end()&&ma[target]!=0)
        {
            count++;
            ma[target]--;
        }
        itr=itr->next;
    }
    return count;
}