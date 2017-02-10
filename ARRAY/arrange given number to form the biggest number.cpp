// PROBLEM :: ARRANGE THE GIVEN NUMBERS TO FORM THE BIGGEST NUMBER.

#include <bits/stdc++.h>
using namespace std;

bool myCompare(string a,string b)
{
	string ab = a.append(b);
	string ba = b.append(a);

	return ab.compare(ba)>0?1:0;
}

void findMax(vector<string> arr,int n)
{
	sort(arr.begin(),arr.end(),myCompare);

	vector<string>::iterator it=arr.begin();

	for(; it!=arr.end();++it)
		cout<<*it;
	cout<<"\n";

}
int main()
{
	string arr[]={"7","776","7","7"};

	vector<string>input(arr,arr+4);

	int n=input.size();

	findMax(input,n);

}
