#include <bits/stdc++.h>
#include <d_queue.h>
using namespace std;
   
    
void d_queue :: add(int l,int m,string n)				//burst time , arrival time , name
{

	d_node *temp=new d_node;
	temp->time = l;
	temp->name = n;
	temp->time_t = l;
	temp->a_time = m;
	count++;
	//cout<<"***\n";
	if(rear==NULL&&front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		//cout<<"***\n";
		bool fl=false;
		d_node *pass=front,*t=front;
		//cout<<"***\n";
		while(pass!=NULL)
		{
			
			if(pass->time<temp->time)
			{
				//cout<<"$$$\n";
				
				t=pass;
				fl=true;
			}
			pass=pass->next;
			//cout<<"~~~\n";
		}
		//cout<<"!!!\n";
		
		if(fl==true&&t==rear)
		{
			//cout<<"end\n";
			rear->next=temp;
			temp->prev=rear;
			rear=temp;
		}
		else if(fl==false)
		{
			//cout<<"start\n";
			t->prev=temp;
			temp->next=t;
			front=temp;
			cout<<"start\n";
		}
		else
		{
			//cout<<"mid\n";
			//pass=pass->prev;
			temp->next=t->next;
			temp->prev=t;
			t->next=temp;
			temp=temp->next;
			temp->prev=t->next;
		}
	}
	//cout<<"@@@\n";
}
    

void d_queue :: d_pop_front()
{
        if(front != NULL)
        {
        	d_node* tmp = front;
        	if ( front->next != NULL )
        	{
        		front = front->next;
        		front->prev = NULL;
            		count-=1;
        	}
        	else
        	{
            		front = NULL;
            		rear = NULL;
            		count = 0;
        	}
        	delete tmp;
        }
        else
        {
        	cout<<"Dqueue is empty";
        }
}
  
  
int d_queue :: size()
{
	return count;
}


bool d_queue :: is_empty()
{
        return count == 0 ? true : false;
}
    
    
void d_queue :: d_display()
{
    	if(front != NULL)
    	{
    		d_node *t=front;
    		cout<<setw(16)<<"Process Name   :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->name;
    			t=t->next;
    		}
    		cout<<endl;
    		t=front;
    		cout<<setw(16)<<"Burst Time     :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->time_t;
    			t=t->next;
    		}
    		cout<<endl;
    		t=front;
    		cout<<setw(16)<<"Time Remaining :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->time;
    			t=t->next;
    		}
    		cout<<endl;
    		t=front;
    		cout<<setw(16)<<"wait time      :";
    		while(t!= NULL)
    		{
    			cout<<setw(5)<<t->w_time;
    			t=t->next;
    		}
    		cout<<endl;
    	}
    	else
    	{
    		cout<<"Idle State"<<endl;
    	}
}
