// CodeChef Question Link : https://www.codechef.com/problems/CONFCAT




import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.StringTokenizer;

import java.util.Collections;




public class ConfusingConcatenations {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }


    static long power(long x,long n)
    {
        long value=(long)(1e9+7);
        long res=1;
        while(n>0)
        {
            if(n%2!=0)
                res=(res*x)%value;
            x=(x*x)%value;
            n=n/2;
        }
        return res;
    }

    static boolean isPrime(long n)
    {
        if(n==1)
            return false;
        if(n==2 || n==3)
            return true;
        if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i+=6)
        {
            if((n%i==0 || n%(i+2)==0))
                return false;
        }
        return true;
    }

    static void sort(long[] a)
    {
        ArrayList<Long> l=new ArrayList<>();
        for (long i:a)
            l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++)
            a[i]=l.get(i);
    }

    static void sortDescending(long[] a)
    {
        ArrayList<Long> l=new ArrayList<>();
        for (long i:a)
            l.add(i);
        l.sort(Collections.reverseOrder());
        for (int i=0; i<a.length; i++)
            a[i]=l.get(i);
    }

    public static boolean Equals(ArrayList<Long> a, ArrayList<Long> b, long n)
    {
        for(int i=0;i<n;i++)
        {
            if(!b.contains(a.get(i)))
                return false;
        }
        for(int i=0;i<n;i++)
        {
            if(!a.contains(b.get(i)))
                return false;
        }
        return true;
    }

    static int[] SetBit(long n,int []arr)
    {
        int res=0;
        int k=0;
        while(n>0)
        {
            if(n%2!=0)
                arr[k]++;
            k++;
            n=n/2;
        }
        return arr;
    }

    static long josephus(long n, long k)
    {
        if(n == 1)
            return 0;
        else
            return (josephus(n - 1, k) + k) % n;
    }

    static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    // method to return LCM of two numbers
    static long lcm(long a, long b)
    {
        return (a / gcd(a, b)) * b;
    }

    static long Sum(long n)
    {
        long sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    static boolean isSubsequence(String s, String a)
    {
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==a.charAt(j))
                j++;
            if(j==a.length())
                return true;
        }
        if(j!=a.length())
            return false;
        return true;
    }

    static boolean chechPalind(long n)
    {
        String s=String.valueOf(n);
        int low=0,high=s.length()-1;
        while(low<high)
        {
            if(s.charAt(low)!=s.charAt(high))
                return false;
            low++;
            high--;
        }
        return true;
    }

    static int seacrhJustGreater(long[] arr, long n)
    {
        int low=0, high=arr.length-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]<n)
                low=mid+1;
            else
            {
                if(mid!=0 && arr[mid-1]>=n)
                    high=mid-1;
                else
                    return mid;
            }
        }
        return -1;
    }

    static void sieve(ArrayList<Boolean> al, long n)
    {
        for(int i=0;i<=n;i++)
            al.add(true);
        for(int i=2;i<=n;i++)
        {
            if(al.get(i))
            {
                for(int j=2*i;j<=n;j+=i)
                    al.set(j,false);
            }
        }
    }

    public static void main (String[] args) throws Exception {
        FastReader sc = new FastReader();
        FastWriter out = new FastWriter();
        long T=sc.nextLong();
        int tc=1;
        while(T-- >0)
        {
            long N=sc.nextLong();
            long[] arr=new long[(int)N];
            for(int i=0;i<N;i++)
                arr[i]= sc.nextLong();
            if(N==1)
            {
                System.out.println(-1);
                continue;
            }
            int index=0;
            for(int i=1;i<N;i++)
            {
                if(arr[i]>arr[index])
                    index=i;
            }
            StringBuilder s=new StringBuilder();
            StringBuilder t=new StringBuilder();
            if(index==0)
            {
                System.out.println(-1);
            }
            else
            {
                for(int i=0;i<index;i++)
                {
                    s.append(arr[i]);
                    s.append(" ");
                }
                for(int i=index;i<N;i++)
                {
                    t.append(arr[i]);
                    t.append(" ");
                }
                System.out.println(index);
                System.out.println(s.toString());
                System.out.println(N-index);
                System.out.println(t.toString());
            }
        }
        out.close();
    }
}





