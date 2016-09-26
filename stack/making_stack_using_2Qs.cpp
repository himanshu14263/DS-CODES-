#include<bits/stdc++.h>
using namespace std;

/*   PUSH AND POP FOR SECOND METHOD (BY MAKING PUSH OPERATION COSTLY)
 *
 *
 * void push(int item){
	q2.push(item);

	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}

	t = q1;
	q1 = q2;
	q2 = t;

}

int pop(){
	if(q1.empty()){
		cout << "Stack empty !" ;
		return -1;
	}
	int item = q1.front();
	q1.pop();
	return item;
}
 */

// FOLLOWING IS THE FIRST METHOD OF IMPLEMENTATION (BY MAKING POP OPERATION COSTLY)
int main()
{
	queue<int>q1,q2;

	while(1)
	{
		cout<<"what do you want to perform \n";
		cout<<"1) push\n"<<"2) pop\n";
		int x;
		cin>>x;
		switch(x)
		{
		case 1:
			cout<<"enter the data to push\n";
			int y;
			cin>>y;
			q1.push(y);
			break;
		case 2:
			if(!q1.empty())
			{
				while(q1.size()!=1)
				{
					int x=q1.front();
					q1.pop();
					q2.push(x);
				}
				cout<<q1.front()<<" ";
				q1.pop();
				queue<int>tmp;
				tmp=q1;
				q1=q2;
				q2=tmp;
			}
			else
			{
				cout<<"underflow\n";
			}
			break;
		}

		bool ch;
		cout<<"do you want to continue\n";
		cin>>ch;
		if(!ch)
			break;
	}

}
