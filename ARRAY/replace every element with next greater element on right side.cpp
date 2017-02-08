// PROBLEM :: REPLACE EVERY ELEMENT WITH THE NEXT GREATER ELEMENT ON THE RIGHT SIDE.

// 


#include<bits/stdc++.h>
using namespace std;

void nge(int arr[],int n)
{
	stack<int>s;
	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		int next=arr[i];

		if(s.empty()==false)
		{
			int x=s.top();s.pop();
			while(x<next)
			{
				cout<<x<<" "<<next<<"\n";
				if(s.empty()==true)
					break;

				x=s.top();s.pop();
			}

			if(x>next)
				s.push(x);
		}

		s.push(next);
	}

	while(s.empty()==false)
	{
		cout<<s.top()<<" "<<-1<<"\n";
		s.pop();
	}	

}
int main()
{
	int arr[]={1,2,3,4,5};
	int n=(sizeof(arr)/sizeof(arr[0]));

	nge(arr,n);
}