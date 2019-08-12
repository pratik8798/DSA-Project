#include <bits/stdc++.h>

using namespace std;

class q_node
{
	public:
	int p;
	int a_time;
	string name;
	q_node *next;
	q_node()
	{
		name="\0";
		a_time=0;
		p=0;
		next=NULL;
	}
};

class p_queue
{
	public:
	q_node *head,*tail;
	int n;
	p_queue()
	{
		head=NULL;
		tail=NULL;
		n=0;
	}
	p_queue(const p_queue &z)
	{
		head=z.head;
		tail=z.tail;
		n=z.n;
	}
	void p_q_push(int ,int ,string );
	void p_q_pop();
	bool p_empty();
	void p_q_display();
	int p_size();
};
