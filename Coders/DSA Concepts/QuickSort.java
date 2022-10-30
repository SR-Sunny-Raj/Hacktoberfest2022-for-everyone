public class QuickSort {
	public static void main(String[] args) {
	    int arr[] = {1, 0};
	    quickSort(arr, 0, arr.length);
	    for(int i = 0; i< arr.length; i++){
	    	    System.out.println(arr[i]);
	    	
	    	}
	}
	public static void quickSort(int input [], int start, int end){
		    if(end - start < 2) {
		    	return;
		    	
		    }
		    int pivotIndex = partition(input, start, end);
		    quickSort(input, start, pivotIndex);
		    quickSort(input, pivotIndex + 1, end);
		
		
	}
	public static int partition(int input[], int start, int end){
		    int i = start;
		    int j = end;
		    int pivot = input[start];
		    
		    while(i<j){
		        while(i<j && pivot <= input[--j]);
		        if (i<j){
		            input[i] = input[j];		
		        }
		        while(i<j && pivot >= input[++i]);
		        if(i<j){
		            input[j] = input[i];	
		        }		
		    }
		    
		    input[j] = pivot;
		    return j;
	}
}
