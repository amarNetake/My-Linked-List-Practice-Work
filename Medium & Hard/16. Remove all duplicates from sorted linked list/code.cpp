// root: head node
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==NULL||head->next==NULL)
 {
     return head;
 }
 Node* prev=head;
 Node* curr=head->next;
 while(curr!=NULL)
 {
     if(curr->data ==prev->data)
     {
         prev->next=curr->next;
         delete(curr);
         curr=prev->next;
     }
     else
     {
         prev=curr;
         curr=curr->next;
     }
 }
 return head;
}