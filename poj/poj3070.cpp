#include <iostream>
using namespace std;

const int p=10000;
struct matrix{
    int m[2][2];
};
matrix multi(const matrix &a, const matrix &b){
    int i,j,k;
    matrix result;
    for (i=0;i<2;i++)
        for (j=0;j<2;j++){
            result.m[i][j]=0;
            for(k=0;k<2;k++){
                result.m[i][j]+=a.m[i][k]*b.m[k][j];
                result.m[i][j]%=p;
            }
        }
    return result;
}
matrix quick_power(matrix a,int n){
    matrix result;
    result.m[0][0]=result.m[1][1]=1;
    result.m[0][1]=result.m[1][0]=0;
    while(n){
        if(n&1) result=multi(result,a);
        n>>=1;
        a=multi(a,a);
    }
    return result;
}

int main(){
    int n;
    matrix a,result;
    a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
    a.m[1][1] = 0;
    while(cin>>n){
        if(n==-1) break;
        if(n==0){
            cout<<0<<endl;
        }else{
            result=quick_power(a,n);
            cout<<result.m[0][1]<<endl;
        }
    }
    return 0;
}
