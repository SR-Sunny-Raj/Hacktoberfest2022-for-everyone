import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class AllDistinctSubsetsOfGivenSet
{
    // Recursive function to print all distinct subsets of `S`.
    // `S`   ——> input set
    // `out` ——> list to store subset
    // `i`   ——> index of next element in set `S` to be processed
    public static void printPowerSet(int[] S, Deque<Integer> out, int i)
    {
        // if all elements are processed, print the current subset
        if (i < 0)
        {
            System.out.println(out);
            return;
        }

        // include the current element in the current subset and recur
        out.addLast(S[i]);
        printPowerSet(S, out, i - 1);

        // backtrack: exclude the current element from the current subset
        out.pollLast();

        // remove adjacent duplicate elements
        while (i > 0 && S[i] == S[i - 1]) {
            i--;
        }

        // exclude the current element from the current subset and recur
        printPowerSet(S, out, i - 1);
    }

    // Wrapper over `printPowerSet()` function
    public static void findPowerSet(int[] S)
    {
        // sort the set
        Arrays.sort(S);

        // create an empty list to store elements of a subset
        Deque<Integer> out = new ArrayDeque<>();
        printPowerSet(S, out, S.length - 1);
    }

    public static void main(String[] args)
    {
        int[] S = { 1, 3, 1 };

        findPowerSet(S);
    }
}


OUTPUT for sample input:
[3, 1, 1]
[3, 1]
[3]
[1, 1]
[1]
[]
