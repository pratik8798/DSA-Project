#include <bits/stdc++.h>
#include "d_queue.h"
#include "p_queue.h"
using namespace std;


class core
{
	friend class processor;
	int time_t;			//time remaining
	int time_active;		//total time active
	int wait_t;			//total wait time
	int tat_t;			//total turn around time
	d_queue que;			//queue 
	public:
	core()
	{
		time_t=0;
		time_active=0;
		wait_t=0;
		tat_t=0;
	}
};


class processor
{
	core c[4];			//core
	p_queue q;			//p_queue
	int total_process;		//total processess
	public :
	int time_active;		//total time processor is active
	processor()
	{
		time_active=0;
		total_process=0;
	}
	void read_file();		//read processess from file
	void assign_process();		//assign processess to core
	void display_processes();	//display processess
	void wait_time();		//wait time increment
	void execute_processes();	//start execution
	float avg_wait_time();		//calculate average wait time
	float avg_turnaround_time();	//calculate average turn around time
};




void processor :: read_file()
{
	ifstream in;
	in.open("processes.txt",ios::in);
	if(in.is_open())
	{
		string s;
		getline(in,s);
		getline(in,s);
		while(getline(in,s))
		{
			string t[3];
			int i=0,j=0;
			while(i<s.length())
			{
				if(isalnum(s[i]))
				{
					t[j]+=s[i];
					i++;
				}
				else
				{
					i++;
					j++;
				}
			}
			int ti=std::stoi(t[1]);
			int td=std::stoi(t[2]);
			q.p_q_push(td,ti,t[0]);		//priorty queue
		}
	}
	q.p_q_display();
	in.close();
	total_process=q.p_size();			//total processess
}


void processor :: assign_process()
{
	int i=0,min_index,min_time;
	//cout<<"###\n";
	if(!q.p_empty())
	{
		while(!q.p_empty())
		{
			//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			if(q.head->a_time==time_active)
			{	
				//cout<<"###\n";
				i=1;
				min_time=c[0].time_t;
				min_index=0;
				while(i<4)
				{
					if(c[i].time_t<min_time)
					{
						min_index=i;
						min_time=c[i].time_t;
					}
					i++;
					//cout<<"^^^\n";
				}
				//cout<<"$$$\n";
				c[min_index].que.add(q.head->p,q.head->a_time,q.head->name);
				cout<<"~~~\n";
				c[min_index].time_t+=q.head->p;
				q.p_q_pop();
				//cout<<"%%%\n";
			}
			else
			{
				break;
			}
	
			for(i=0;i<4;i++)
			{
				c[i].time_active=c[i].time_t;
			}
		}
	}
	//cout<<"###\n";
}


void processor :: wait_time()
{
	d_node *t=NULL;
	for(int i=0;i<4;i++)
	{
		if(c[i].que.front!=NULL)
		{
			if(c[i].que.front->next!=NULL)
			{
				t=c[i].que.front->next;
				while(t!=NULL)
				{
					t->w_time+=1;
					t=t->next;
				}
			}
		}
	}
}


void processor :: display_processes()
{
	system("clear");
	cout<<"\n\n"<<endl;
	cout<<"Total Time :"<<time_active<<" Seconds\n\n"<<endl;
	cout<<"Queue :"<<endl;
	q.p_q_display();
	cout<<"\n"<<endl;
	for(int i=0;i<4;i++)
	{
		
		cout<<"\n\n\nFor Core  : "<<i+1<<"\n"<<endl;
		cout<<c[i].time_t<<"\n"<<endl;
		c[i].que.d_display();
	}
}


void processor :: execute_processes()
{
	int i=0;
	ofstream outf;
	outf.open("process_info.txt",ios :: trunc);
	outf<<setw(10)<<"   Name   " << setw(14) << " arrival time " << setw(11) << " Burst Time " << setw(11) << " Wait Time " << setw(19) << " Completition time " <<setw(18) << " Turn Around Time " << endl;
	while((!c[0].que.is_empty()||!c[1].que.is_empty()||!c[2].que.is_empty()||!c[3].que.is_empty())||!q.p_empty())
	{
		//cout<<"**********************\n";
		assign_process();
		//cout<<"######################\n";
		display_processes();
		for(i=0;i<4;i++)
		{
			if(c[i].que.front!=NULL)
			{
				c[i].time_t-=1;
				c[i].que.front->time-=1;
			}
		}
		wait_time();
		for(i=0;i<4;i++)
		{
			if(c[i].que.front!=NULL)
			{
				if(c[i].que.front->time==0)
				{
					c[i].que.front->time_tat = time_active + 1 - c[i].que.front->a_time;
					c[i].tat_t+=c[i].que.front->time_tat;
					c[i].wait_t+=c[i].que.front->w_time;
					outf << setw(5) << c[i].que.front->name << setw(14) << c[i].que.front->a_time << setw(11) << c[i].que.front->time_t << setw(11) << c[i].que.front->w_time << setw(19) << time_active+1 << setw(18) << c[i].que.front->time_tat << endl;
					c[i].que.d_pop_front();
				}
			}
		}
		time_active+=1;
		this_thread::sleep_for(chrono::seconds(1));
	}
	display_processes();
	outf.close();
}


float processor :: avg_wait_time()
{
	float t=0;
	for(int i=0;i<4;i++)
	{
		t+=(float)c[i].wait_t;
	}
	//cout<<t<<"\t"<<total_process<<endl;
	return t/(float)total_process;
}


float processor :: avg_turnaround_time()
{
	float t=0;
	for(int i=0;i<4;i++)
	{
		t+=(float)c[i].tat_t;
	}
	return t/(float)total_process;
}



int main()
{
	processor z;
	
	char x;

	while(true)
	{
		system("gedit processes.txt");
		cout<<"Do You Want to Start Execution"<<endl;
		cin>>x;
		if(x=='Y'||x=='y')
		{
			break;
		}
	}
	
	ofstream outf;
	outf.open("process_info.txt",ios::app);
	outf<<"\n\n"<<endl;
	z.read_file();
	z.display_processes();
	z.execute_processes();
	cout<<"\n\n\n\n";
	cout<<setw(40)<<"Total time to execute all processess      :"<<setw(10)<<z.time_active<<" Seconds"<<endl;
	outf<<setw(40)<<"Total time to execute all processess      :"<<setw(10)<<z.time_active<<" Seconds"<<endl;
	cout<<setw(40)<<"Average Wait time is                      :"<<setw(10)<<z.avg_wait_time()<<" Seconds"<<endl;
	outf<<setw(40)<<"Average Wait time is                      :"<<setw(10)<<z.avg_wait_time()<<" Seconds"<<endl;
	cout<<setw(40)<<"Average Turn around time is               :"<<setw(10)<<z.avg_turnaround_time()<<" Seconds"<<endl;
	outf<<setw(40)<<"Average Turn around time is               :"<<setw(10)<<z.avg_turnaround_time()<<" Seconds"<<endl;
	cout<<"Execution Completed"<<endl;
	outf.close();
	return 0;
}
