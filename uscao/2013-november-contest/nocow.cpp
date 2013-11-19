/*
ID: yhong52
PROG: nocow
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
 
using namespace std;
 
const int N = 110;
 
int n,m,k;
int cnt[N];
string cow[N][N],x[N],ans;
map<string, int> col[N];
 
int main () {
  freopen ("nocow.in", "rb", stdin);
  freopen ("nocow.out", "w", stdout);
 
  scanf ("%d %d", &n, &k);
  k --;
 
  for (int i = 0;i < n;i ++) {
    m = 0;
    string trash;
    cin >> trash >> trash >> trash >> trash;
    while (cin >> trash and trash != "cow.") {
      col[m][trash] = 0;
      cow[i][m ++] = trash;
    }
  }
 
  int now = 1;
  for (int i = 0;i < m;i ++) {
    cnt[i] = 0;
    // printf ("===== %d =====\n", i);
    for (map<string, int>::iterator it = col[i].begin ();it != col[i].end ();it ++) {
      it->second = cnt[i] ++;
      // printf ("%s %d\n", it->first.c_str (), it->second);
    }
    now *= cnt[i];
  }
 
  for (int i = 0;i < n;i ++) {
    for (int j = 0;j < m;j ++) {
      int a = col[j][cow[i][j]],b = a%10;
      a /= 10;
 
      x[i] += char (a+'0');
      x[i] += char (b+'0');
    }
  }
 
  sort (x, x+n);
 
  // for (int i = 0;i < n;i ++) {
  //   cout << x[i] << endl;
  // }
 
  int _ = 0;
  for (int i = 0;i < m;i ++) {
    int nub = 0,a,b,last = 0;
    now /= cnt[i];
    int hnow = 0;
    // printf ("k : %d\n", k);
    for (int j = 0;j < cnt[i];j ++) {
      if (hnow-nub > k) {
        // printf ("j : %d\n", j);
        k -= hnow-now-last;
        a = (j-1)/10;
        b = (j-1)%10;
        ans += char (a+'0');
        ans += char (b+'0');
        goto f;
      }
 
      string dum = ans;
      a = j/10;
      b = j%10;
      dum += char (a+'0');
      dum += char (b+'0');
     
      last = nub;
      for (nub = 0;nub < n;nub ++) {
        for (int z = 0;z < dum.size ();z ++) {
          if (x[_+nub][z] > dum[z]) {
            goto ff;
          } else if (x[_+nub][z] < dum[z]) {
            break;
          }
        }
      }
    ff:;
 
      hnow += now;
 
      // printf ("hnow : %d nub : %d\n", hnow, nub);
    }
    k -= hnow-now-last;
    _ += last;
    a = (cnt[i]-1)/10;
    b = (cnt[i]-1)%10;
    ans += char (a+'0');
    ans += char (b+'0');
  f:;
 
    // cout << ans << endl;
  }
 
  // cout << ans << endl;
 
  for (int i = 1;i < ans.size ();i += 2) {
    int a = ans[i-1]-'0',b = ans[i]-'0';
    int c = a*10+b;
 
    if (i > 1) {
      printf (" ");
    }
 
    for (map<string, int>::iterator it = col[i/2].begin ();it != col[i/2].end ();it ++) {
      if (it->second == c) {
        cout << it->first;
        break;
      }
    }
  }
  printf ("\n");
}
