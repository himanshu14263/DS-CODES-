// PROBLEM :: MERGE OVERLAPPING INTERVALS

// time complexity :: O(n log n)

#include <bits/stdc++.h>
using namespace std;

struct interval
{
	int strt;
	int end;
};

bool myCompare(interval a,interval b)
{
	return a.strt<b.strt;
}
void findOverlapInter(interval arr[],int n)
{
	stack<interval>s;
	sort(arr,arr+n,myCompare);			// here sorting contributes to the maximum time complexity of the algorithm.
	
	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		interval top = s.top();
		if(top.end<arr[i].strt)
			s.push(arr[i]);
		else
		{
			if(top.end<arr[i].end){
				top.end=arr[i].end;
				s.pop();
				s.push(top);
			}
		}
	}

	cout<<"the merged intevals are :: \n\n";
	while(s.empty()==false)
	{
		cout<<"["<<s.top().strt<<" "<<s.top().end<<"] ";
		s.pop();
	}

}

int main()
{
	interval arr[]={{1,3}, {2,4}, {5,7}, {6,8}};

	int n=(sizeof(arr)/sizeof(arr[0]));

	findOverlapInter(arr,n);
}
