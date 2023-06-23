#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rd_int(n) uniform_int_distribution<int>(1,n)(rnd)
#define rd_real(n) uniform_real_distribution<double>(-n,n)(rnd)
const int N=500,K=10,V=100000;
int main(){
    int k=rd_int(K),m=rd_int(N),n=rd_int(N);
    // k=10; m=n=1000000;
    printf("%d %d %d\n",k,m,n);
    for(int i=0; i<m+n; i++){
        for(int j=0; j<k; j++) printf("%.8lf ", rd_real(V));
        puts("");
    }
    return (0-0);
}