#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX 1000
template<class t>
class msort
{
public:
t a[MAX];
int count, n;
void input();
void output();
t mergesort(t a[] ,int p,int r);
void merge(t a[],int p,int q,int r);
msort()
{
count=0;
}
};
template<class t>
void msort<t>::input()
{
t ele;
for(int i=1;i<=n;i++)
{
ele= rand();
a[i]=ele;
}
}
template<class t>
void msort<t>::output()
{
cout<<"\nSorted array: ";
for(int i=1;i<=n;i++)
cout<<a[i]<<"\t";
}

template<class t>
t msort<t>::mergesort(t a[],int p, int r)
{
if(p<r)
{
int q=(p+r)/2;
mergesort(a,p,q);
mergesort(a,q+1,r);
merge(a,p,q,r);
}
}
template<class t>
void msort<t>::merge(t a[],int p,int q, int r)
{
int i,j,k;
int n1=q-p+1;
int n2=r-q;
t L[500],R[500];
for(i=1;i<=n1;i++)
L[i]=a[p+i-1];
for(j=1;j<=n2;j++)
R[j]=a[q+j];
L[n1+1]=INT_MAX;
R[n2+1]=INT_MAX;
i=j=1;
for(int k=1;k<=r;k++)
{
if(L[i]<=R[j])
{
a[k]=L[i];
i++;
}
else
{
a[k]=R[j];
j++;
}
count++;
}
}
int main()
{
int size, c;
ofstream o;
o.open("msort.csv",ios::app);
msort<int>ms;
cout<<"\nEnter the size: ";
cin>>size;
if(size<30||size>1000)
{
cout<<"Invalid!!";
cin>>size;
}
else
{
for(int k=size;k<=1000;k+=30)
{
ms.n=k;
ms.input();
ms.mergesort(ms.a,1,ms.n);
ms.output();
cout<<"\nNumber of comparisons: "<<ms.count;
o<<k<<","<<k*k<<","<<ms.count<<","<<log2(k)<<","<<k*log2(k)<<endl;
}
}
o.close();
return 0;
}