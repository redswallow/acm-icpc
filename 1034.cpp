#include <iostream>
using namespace std;
int n,m,p,i,pi,pj,set[5001];

int find(int i){
    if(set[i]==i) return i;
    return set[i]=find(set[i]);
}

void make_set(int i){
    set[i]=i;
}

void union_set(int i,int j){
    set[find(i)]=find(j);
}

int main(){
    cin>>n>>m>>p;
    for(i=0;i<n;i++) make_set(i);
    for(i=0;i<m;i++){
        cin>>pi>>pj;
        union_set(pi,pj);
    }
    for(i=0;i<p;i++){
        cin>>pi>>pj;
        if(find(pi)==find(pj))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
