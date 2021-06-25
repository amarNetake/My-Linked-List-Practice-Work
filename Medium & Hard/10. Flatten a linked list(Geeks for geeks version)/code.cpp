Node* mergeTwoSortedLists(Node* first,Node* second)
{
    if(first==NULL)
    {
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
    Node* result;
    if(first->data <= second->data)
    {
        result=first;
        result->bottom=mergeTwoSortedLists(first->bottom,second);
    }
    else if(second->data < first->data)
    {
        result=second;
        result->bottom=mergeTwoSortedLists(first,second->bottom);
    }
    return result;
}

Node *flatten(Node *root)
{
   // Your code here

	//We will go on merging the lists from right most to left.
   if(root==NULL||root->next==NULL)
   {
       return root;
   }
   Node* first=root;
   Node* second=flatten(root->next);
   Node* h=mergeTwoSortedLists(first,second);
   return h;
}
