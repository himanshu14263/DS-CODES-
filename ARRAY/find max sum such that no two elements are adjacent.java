package apple;

class maxSum{
	
	static int max(int a,int b)
	{
		return (a>b)?a:b;
	}
	
	static int func(int[] arr,int n)
	{
			int incl=arr[0],excl=0,excl_temp;
			for(int i=1;i<n;i++)
			{
				excl_temp=max(incl,excl);
				incl=excl+arr[i];
				excl=excl_temp;
			}
			
		return max(incl,excl);
	}
	
	public static void main(String args[])
	{
			int[] arr={3,2,7,10};
			int n=arr.length;
			
			System.out.println("the max sum is :: "+func(arr,n));
	}
}