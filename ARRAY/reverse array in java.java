package apple;

public class reverseArray {
	
	static void reverseArray(int[] arr,int n)
	{
		int l=0,e=n-1;
		
		while(l<e)
		{		
			int temp=arr[l];
			arr[l]=arr[e];
			arr[e]=temp;
			
			
			l++;
			e--;
		}
	}
	
	public static void main(String args[])
	{
			int[] arr=new int[5];
			for(int i=0;i<5;i++)
				arr[i]=i+1;
			
			int n=arr.length;
			
			for(int i=0;i<n;i++)
				System.out.print(arr[i]+" ");
			System.out.println();
			
			reverseArray(arr,n);
			
			
			for(int i=0;i<n;i++)
				System.out.print(arr[i]+" ");
			
			
	}

}
