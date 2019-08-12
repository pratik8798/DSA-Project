#include <bits/stdc++.h>
#include <p_queue.h>

using namespace std;


void p_queue :: p_q_display()
{
	if(head!=NULL)
    	{
    		q_node *t=head;
    		cout<<setw(16)<<"Process Name   :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->name;
    			t=t->next;
    		}
    		cout<<endl;
    		t=head;
    		cout<<setw(16)<<"Burst Time     :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->p;
    			t=t->next;
    		}
    		cout<<endl;
    		t=head;
    		cout<<setw(16)<<"Arrival Time   :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->a_time;
    			t=t->next;
    		}
    		cout<<endl;
    	}
	else
	{
		cout<<"p_queue is empty"<<endl;
	}
}


void p_queue :: p_q_push(int l,int m,string n)
{
	q_node *temp=new q_node;
	temp->name=n;
	temp->p=m;
	temp->a_time=l;
	n+=1;
	//cout<<"***\n";
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		//cout<<"###\n";
		bool fl=true;
		q_node *t=head,*pass=head;
		while(pass!=NULL)
		{
			
			if(pass->a_time<temp->a_time)
			{
				t=pass;
				fl=false;
			}
			else if(pass->a_time==temp->a_time)
			{
				if(pass->p<temp->p)
				{
					t=pass;
					fl=false;
				}
			}
			pass=pass->next;
			//cout<<"^^^\n";
		}
		//cout<<"%%%\n";
		if(fl==false&&t==tail)
		{
			tail->next=temp;
			tail=temp;
		}
		else if(fl==true)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			temp->next=t->next;
			t->next=temp;
		}
	}
	//cout<<"@@@\n";
}


void p_queue :: p_q_pop()
{
if(head!=NULL)
{
	n-=1;
	if(head->next!=NULL)
	{
		q_node *temp;
		temp=head;
		head=head->next;
		delete temp;
	}
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}
}
	else
	{
		cout<<"p_queue is empty"<<endl;
	}
}


bool p_queue :: p_empty()
{
	if(head==NULL&&tail==NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


int p_queue :: p_size()
{
	int count=0;
	q_node *t=head;
	while(t!=NULL)
	{
		count+=1;
		t=t->next;
	}
	return count;
}
