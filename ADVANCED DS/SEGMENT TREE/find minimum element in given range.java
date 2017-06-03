// PROBLEM :: SEGEMENT TREE CREATION AND FINDING THE MINIMUM ELEMENT

import java.util.*;
public class TugOfWar 
{
	int min(int a,int b)
	{
		return a>b?b:a;
	}
	void createSegTreeUtil(int input[],int SegTree[],int low,int high,int pos)
	{
		if(low == high)
		{
			SegTree[pos] = input[low];
			return;
		}
		
		int mid = (low + high)/2;
		
		createSegTreeUtil(input,SegTree,low,mid,2*pos+1);
		createSegTreeUtil(input,SegTree,mid+1,high,2*pos+2);
		
		SegTree[pos] = min(SegTree[2*pos+1],SegTree[2*pos+2]);
	}
	void createSegTree(int[] input,int[] SegTree)
	{
		int low,high,pos;
		low = 0;
		high = input.length-1;
		pos = 0;
		createSegTreeUtil(input,SegTree,low,high,pos);
	}
	
	int minQueryUtil(int SegTree[],int qlow,int qhigh,int low,int high,int pos)
	{
		if(low>=qlow && high<=qhigh)
			return SegTree[pos];
		
		if(qlow>high || qhigh<low)
			return Integer.MAX_VALUE;
		
		int mid = (low+high)/2;
		
		return min(minQueryUtil(SegTree,qlow,qhigh,low,mid,2*pos+1),
				minQueryUtil(SegTree,qlow,qhigh,mid+1,high,2*pos+2));
	}
	
	int minQuery(int[] SegTree,int a,int b,int len)
	{
		return minQueryUtil(SegTree,a,b,0,len,0);
	}
	
	public static void main(String[] args)
	{
		int arr[] = {-1,3,4,0,2,1};
		int SegTree[] = new int[20];
		
		for(int i= 0;i<20;i++)
			SegTree[i]=Integer.MAX_VALUE;
		
		TugOfWar obj = new TugOfWar();
		obj.createSegTree(arr,SegTree);
		
		int a,b;

		for(int i=0;i<arr.length;i++)
			System.out.print(i+"\t");
		System.out.println();
		
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+"\t");
		
		System.out.println("\n");
		
		System.out.println("enter the range");
		
		Scanner s = new Scanner(System.in);
		a = s.nextInt();
		b = s.nextInt();
		
		System.out.println("the minimum element is :: "+ obj.minQuery(SegTree,a,b,arr.length));
		s.close();
	}
}