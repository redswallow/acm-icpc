/*
ID: yhong52
PROG: milktemp
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long n,i,j,k,x,y,z;
long maxs=0,s=0,ans=0,a[20000],b[20000],overlap[40000];
long lr[40000];

void qsort(long left,long right){
    long i=left,j=right,pivot,temp;
    pivot=overlap[(left+right)/2];
    while (i<=j){
        while (overlap[i]<pivot) i++;
        while (overlap[j]>pivot) j--;
        if (i<=j){
            temp=overlap[i];overlap[i]=overlap[j];overlap[j]=temp;
            temp=lr[i];lr[i]=lr[j];lr[j]=temp;
        }
        i++;j--;
    }
    if (left<j) qsort(left,j);
    if (right>i) qsort(i,right);
}

int main() {
    ofstream fout ("milktemp.out");
    ifstream fin ("milktemp.in");

    fin>>n>>x>>y>>z;
    for(i=0;i<n;i++){
        fin>>a[i]>>b[i];
        overlap[i]=a[i];overlap[n+i]=b[i];
        lr[i]=1;lr[n+i]=-1;
    }
    qsort(0,2*n-1);

    if (lr[0]>0) maxs=lr[0];else maxs=0;
    ans=0;
    for (i=1;i<2*n;i++){
        lr[i]=lr[i]+lr[i-1];
        if(lr[i]>maxs) maxs=lr[i];
        cout<<lr[i]<<" "<<overlap[i]<<endl;
    }

    for (i=0;i<2*n;i++)
    if (lr[i]==maxs){
        k=overlap[i];
        s=0;
        for (j=0;j<n;j++)
            if (a[j]>k) s+=x;
            else if(k>=a[j] && k<=b[j]) s+=y;
            else s+=z;
        if (s>ans) ans=s;
    }

    fout<<ans<<endl;
    return 0;
}
