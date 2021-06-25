/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

Node* addPolynomial(Node *p1, Node *p2)  //A similar algorithm to merge 2 sorted lists can be applied
{
    //Your code here
    if(p1==NULL)
    {
        return p2;
    }
    else if(p2==NULL)
    {
        return p1;
    }
    Node* result;
    if(p1->pow==p2->pow)
    {
        p1->coeff=p1->coeff + p2->coeff;
        result=p1;
        result->next=addPolynomial(p1->next,p2->next);
    }
    else if(p1->pow > p2->pow)
    {
        result=p1;
        result->next=addPolynomial(p1->next,p2);
    }
    else if(p1->pow < p2->pow)
    {
        result=p2;
        result->next=addPolynomial(p1,p2->next);
    }
    return result;
}