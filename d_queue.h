#include <bits/stdc++.h>
using namespace std;

class d_node
{
	public:
	int time;				//time remaining for completion of process
	int time_t;				//burst time of process
	int a_time;				//arrival time of process
	int w_time;				//wait time of the process
	int time_tat;				//turn around time of the process
	string name;				//name of process
	d_node* next;
	d_node* prev;
	d_node()
	{
		time=0;
		time_t=0;
		w_time=0;
		a_time=0;
		time_tat=0;
		name="\0";
		next=prev=NULL;
	}
};

class d_queue
{  
	public:
        d_node* front;
        d_node* rear;
        int count;
    	d_queue()
    	{
        	front = NULL;
        	rear = NULL;
        	count = 0;
    	}      
    	
    	void add(int ,int ,string );
	void d_pop_front();
	int size();
	bool is_empty();
	void d_display();
};
