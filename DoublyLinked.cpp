#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *prev,*next;
};
Node *head,*tail;
int cnt;
Node* createNode(int ele)
{
	Node *temp = new Node();
	temp->data = ele;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertBegin(int ele)
{
	Node *temp = createNode(ele);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	cnt++;
}

void insertEnd(int ele)
{
	Node *temp = createNode(ele);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	cnt++;
}


void insertPos(int pos,int ele)
{
	if(pos==1)
		insertBegin(ele);
	else if(pos==cnt+1)
		insertEnd(ele);
	else
	{
		Node *temp = createNode(ele);
		Node *cp=head,*pp;
		for(int i=1;i<pos;cp=cp->next,i++);
		
		pp = cp->prev;
		pp->next = temp;
		temp->prev = pp;
		temp->next = cp;
		cp->prev = temp;
		cnt++;
	}
	
}
void deleteBegin()
{
	if(head == NULL)
		cout<<"\n List empty \n";
	else
	{
		cout<<"\n Deleting = "<<head->data<<endl;
		Node *temp = head;
		head= head->next;
		if(head!=NULL)
			head->prev = NULL;
		else
			tail = NULL;		
		temp->data = 0;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
		cnt--;
	}
}

void deleteEnd()
{
	if(head == NULL)
		cout<<"\n List empty \n";
	else
	{
		cout<<"\n Deleting = "<<tail->data<<endl;
		tail = tail->prev;
		if (tail!=NULL)
		{
			tail->next->data = 0;
			tail->next->next = NULL;
			tail->next->prev = NULL;
			delete tail->next;
			tail->next = NULL;
		}	
		else
		{
			head->data = 0;
			head->next = NULL;
			head->prev = NULL;
			delete head;
			head = NULL;
		}		
		cnt--;
	}
}
void deletePos(int pos)
{
	if(pos==1)
		deleteBegin();
	else if(pos == cnt)
		deleteEnd();
	else
	{
		Node *cp=head;
		for(int i=1;i<pos;cp=cp->next,i++);
		
		cout<<"\n Deleting  = "<<cp->data<<endl;
		
		cp->prev->next = cp->next;
		cp->next->prev = cp->prev;
		cp->data =0;
		cp->next = NULL;
		cp->prev = NULL;
		delete cp;
		cnt--;
	}
}

void display()
{
	if(head == NULL)
		cout<<"\n List is empty\n";
	else
	{
		Node *trav=head;
		while(trav!=NULL)
		{
			cout<<trav->data<<"-->";
			trav = trav->next;
		}
	}
}

void reverse()
{
	if(head == NULL)
		cout<<"\n List is empty\n";
	else
	{
		Node *trav=tail;
		while(trav!=NULL)
		{
			cout<<trav->data<<"-->";
			trav = trav->prev;
		}
	}
}
int main()
{
	head = NULL;
	tail = NULL;
	cnt =0;
	int ch,ele,pos,start,end;
	Node *temp;
	do
	{
		cout<<"\n1 InsertBegin";
		cout<<"\n2 InsertEnd";
		cout<<"\n3 InsertPos";
		cout<<"\n4 DeleteBegin";
		cout<<"\n5 DeleteEnd";
		cout<<"\n6 DeletePos";
		cout<<"\n7 Display";
		cout<<"\n8 At";
		cout<<"\n9 Max";
		cout<<"\n10 Min";
		cout<<"\n11 Sort (Conditional)";
		cout<<"\n12 Reverse";
		cout<<"\n13 Exit";
		cout<<"\n Enter choice = ";
		cin>>ch;
		if(ch>=1 && ch<=3)
		{
			cout<<"\n Enter the ele = ";
			cin>>ele;
		}
		switch(ch)
		{
			case 1:insertBegin(ele);
			       break;
			case 2:insertEnd(ele);
			       break;
			case 3: cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt+1)
						insertPos(pos,ele);
					else
						cout<<"\n Invalid position \n";
			       break;
			case 4:deleteBegin();
			       break;
			case 5:deleteEnd();
			       break;
			case 6: cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt)
						deletePos(pos);
					else
						cout<<"\n Invalid position \n";
			       break;
			       
			case 7:display();break;
		/*	case 8:cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt)
						cout<<at(pos)->toString();
					else
						cout<<"\n Invalid position \n";
			       break;
			case 9:temp = max();
					if(temp)
						cout<<"MAX = "<<temp->toString()<<endl;
					else
						cout<<"\n list is empty \n";
					break;
			case 10:temp = min();
					if(temp)
						cout<<"MIN = "<<temp->toString()<<endl;
					else
						cout<<"\n list is empty \n";
					break;
			case 11:cout<<"\n Enter the start pos = ";
				    cin>>start;
				    cout<<"\n Enter the end pos = ";
				    cin>>end;
				    if(start<1 || end>cnt)
				    	cout<<"\n Invalid start and end\n";
				    else
				    	sort(start,end);
				    break;*/
			case 12:reverse();break;
			case 13:break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=13);
	
}




