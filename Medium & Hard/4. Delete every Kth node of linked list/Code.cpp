Node* deleteK(Node *head,int K)
{
  //Your code here
  if(head==NULL||K==1)
  {
      return NULL;
  }
  else if(K==0)
  {
      return head;
  }
  Node* itr=head;
  Node* prev;
  int count=1;
  while(itr!=NULL)
  {
      if(count==K)  // => itr is pointing to the node that has to be deleted.
      {
        prev->next=itr->next;
        delete(itr);
        itr=prev->next;
        count=1;
      }
      else
      {
        prev=itr;
        itr=itr->next;
        count++;
      }
  }
  return head;
}