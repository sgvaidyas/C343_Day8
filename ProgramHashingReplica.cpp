#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct MainNode
{
	int data;
	Node *next;
	struct MainNode *down;
};

MainNode *head;
void insertMainNode(int ele)
{
	MainNode *temp = new MainNode();
	temp->data = ele;
	temp->next = NULL;
	temp->down =NULL;
	if(head == NULL)
		head=temp;
	else
	{
		MainNode *p = head;
		for(;p->down!=NULL;p=p->down);
		p->down = temp;
	}	
}
void reset()
{
	for(int i=0;i<4;i++)
		insertMainNode(i);
}

void insertNode(int ele)
{
	int pos = ele%4; //2
	
	MainNode *p = head;
	for(int i=0;i<pos;p=p->down,i++);   //i=1  1<2  3000
	
	Node *temp = new Node();
	temp->data = ele;
	temp->next = NULL;
	
	if(p->next!=NULL)
	{
		Node *trav = p->next; //200
		while(trav->next!=NULL)
		{
			trav  = trav->next;
		}
		trav->next = temp;
	}
	else
		p->next = temp;
}

void display()
{
	cout<<"\n Elements of the lists = \n";
	
	MainNode *p = head;
	Node *trav;
	
	for(;p!=NULL;p=p->down)
	{
		cout<<p->data;
		trav=p->next;
		while(trav)
		{
			cout<<"-->"<<trav->data;
			trav = trav->next;
		}
		cout<<"\n|\n";
	}
}

void deleteNode(int ele)
{
	int pos = ele%4; //2
	
	MainNode *p = head;
	for(int i=0;i<pos;p=p->down,i++);   //i=1  1<2  3000
	
	if(p->next==NULL)
		cout<<"\n The element not found \n";
	else
	{
		Node *trav = p->next; //100
		Node *pp = p->next;   //100
		int check=1;
		while(trav!=NULL)
		{		
			if(trav->data == ele && p->next==trav)
			{
				p->next = trav->next;
				cout<<"\n Delete the instance of ele = ";
				delete trav;
				trav = p->next;
				check =0;
			}	
			else if(trav->data == ele)
			{
				pp->next = trav->next;
				cout<<"\n Delete the instance of ele = ";
				delete trav;
				trav = pp;//100	
				check=0;			
			}
			pp = trav;   //100   
			if(trav!=NULL)  
				trav = trav->next;
		}
		if(check==1)
			cout<<"\n element not found\n";
	}
}
int main()
{	
	head = NULL;
	int ch,ele;
	reset();
	do
	{
		cout<<"\n 1 Insert Node  2 Display  3 Delete  4 Exit \nEnter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\n enter ele = ";
			       cin>>ele;
			       insertNode(ele);
			       break;
			case 2:display();break;
			case 3:cout<<"\n enter ele = ";
			       cin>>ele;
				   deleteNode(ele);break;
			case 4:break;
			default:cout<<"\n Invalid choice  \n ";
		}
	}while(ch!=4);
	
}
