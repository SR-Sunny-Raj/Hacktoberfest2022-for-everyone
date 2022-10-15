//https://www.codechef.com/START60D/problems/ARRPAL
import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		try{
		    Scanner sc = new Scanner(System.in);
		    int testCases = sc.nextInt();
		    while(testCases>0){
		        int n = sc.nextInt();
		        int mid = 0;
		        int count = 0;
		        if(n%2 == 0){
		            mid = (n/2)-1;
		        }else{
		            mid = (n-1)/2;
		        }
		        boolean check = true, palinCheck = true;
		        long arr[] = new long[n];
		        for(int i = 0 ; i<n ; i++){
		            arr[i] = sc.nextLong();
		            if(i>mid && arr[i]<arr[n-i-1]){
		                check = false;
		            }
		            if(i>mid && arr[i]!=arr[n-i-1]){
		                palinCheck = false;
		            }
		        }
		        boolean check1 = true;
		        if(check){
		            if(palinCheck){
		                System.out.println(0);
		            }else{
		                //count = 0;
		                for(int i = mid; i>=0 ; i--){
		                    long diff = arr[n-i-1] - arr[i] - count;
		                    if(diff<0){
		                        System.out.println(-1);
		                        check1 = false;
		                        break;
		                    }
		                    count+=diff;
		                }
		                if(check1){
		                    System.out.println(count);
		                }
		            }
		        }else{
		            System.out.println(-1);
		        }
		        testCases--;
		    }
		    
		}catch(Exception e){
		    return;
		}
	}
}
