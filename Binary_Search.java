import java.uti.*;
public class BinarySearch {

    public static void main(String[] args) {
        int[] arr = {-58,-36,0;5,9,85};
        int target = 35;
        int ans = binarySearch(arr, target);
        System.out.println(ans);
    }

    // return the index
    static int binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while(start <= end) {
            // find the middle element
            int mid = start + (end - start) / 2;
              if (target < arr[mid]) {
                end = mid - 1;
            }
          else if (target > arr[mid]) {
                start = mid + 1;
            } 
          else {
                // ans found
                return mid;
            }
        }
      //if element not found return -1
        return -1;
    }
}
