/*
ID: yhong52
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n,a[3], b[3],i,j,k,s;
    fin>>n;
    fin>>a[0]>>a[1]>>a[2];
    fin>>b[0]>>b[1]>>b[2];
    s=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                if ((abs(i-a[0])<=2 || abs(i-a[0])>=n-2)
                    && (abs(j-a[1])<=2 || abs(j-a[1])>=n-2)
                    && (abs(k-a[2])<=2 || abs(k-a[2])>=n-2)){
                    s=s+1;
                }else if ((abs(i-b[0])<=2 || abs(i-b[0])>=n-2)
                    && (abs(j-b[1])<=2 || abs(j-b[1])>=n-2)
                    && (abs(k-b[2])<=2 || abs(k-b[2])>=n-2)){
                    s=s+1;
                }
    fout<<s<<endl;
    return 0;
}
