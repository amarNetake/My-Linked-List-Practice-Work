/* 
Both iterative and recursive approach.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int x)
		{
			data=x;
			next=NULL;
		}
};

int iterative_Apporach_Count_Nodes(Node* head)
{
	int count=0;
	Node* itr=head;
	while(itr!=NULL)
	{
		count++;
		itr=itr->next;
	}
	return count;
}

int recursive_Apporach_Count_Nodes(Node* head)
{
	if(head==NULL)
	{
		return 0;
	}
	Node* itr=head;
	return 1 + recursive_Apporach_Count_Nodes(itr->next);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Node * head=NULL;
	head=new Node(5);
	head->next=new Node(10);
	head->next->next=new Node(15);
	head->next->next->next=new Node(20);
	head->next->next->next->next=new Node(25);
	head->next->next->next->next->next=new Node(30);
	head->next->next->next->next->next->next=new Node(35);

	int count1=iterative_Apporach_Count_Nodes(head);
	int count2=recursive_Apporach_Count_Nodes(head);
	cout<<"Iterative approach count= "<<count1<<endl;
	cout<<"Recursive approach count= "<<count2<<endl;
}