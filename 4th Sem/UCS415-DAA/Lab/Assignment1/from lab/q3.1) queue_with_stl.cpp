#include<iostream>
#include<queue>
using namespace std;

void showq(queue<int> q)
{
	while(!q.empty())
	{
		cout<<"\t"<<q.front();
		q.pop();
	}
}

struct str
{
	int a;
	int b;
};

void scan_mtrx(int mtrx[3][3],struct str temp,queue<str> q)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if (mtrx[i][j]==2)
			{
				temp.a=i;
				temp.b=j;
			}
			q.push(temp);
		}
	}
}

int main()
{
	//queue<int> r;
//	r.push(1);
	//r.push(4);
//	r.push(6);
//	r.push(12);
//	r.pop();
//	r.pop();
//	r.pop();
//	r.pop();
//	cout<<r.empty()<<endl;
	//cout<<r.size()<<endl;
//	cout<<"This is the front of the queue: "<<r.front()<<endl;
	//showq(r);
	int m=3,n=3;
	int rto[m][n]={2,1,1,0,1,1,0,2,1};
	
	
	queue<str> r;
struct str temp;
scan_mtrx(rto,temp,r);
cout<<r.front()<<endl;
	
}
