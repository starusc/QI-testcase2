#include<bits/stdc++.h>
using namespace std;

typedef vector<double> point;
typedef vector<point> point_set;
const double inf=1e16;

int k,m,n;
double ans=0, d;
point qwq,a,b;
point_set A,B;
int main(){
    scanf("%d%d%d",&k,&m,&n);
    qwq.resize(k); a.resize(m); b.resize(n);
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++) scanf("%lf", &qwq[j]);
        A.push_back(qwq);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) scanf("%lf", &qwq[j]);
        B.push_back(qwq);
    }

    for(int i=0; i<m; i++) a[i]=inf;
    for(int i=0; i<n; i++) b[i]=inf;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            d=0;
            for(int r=0; r<k; r++) d+=(A[i][r]-B[j][r])*(A[i][r]-B[j][r]);
            d=sqrt(d);
            a[i]=min(a[i],d);
            b[j]=min(b[j],d);
        }
    for(int i=0; i<m; i++) ans=max(ans,a[i]);
    for(int i=0; i<n; i++) ans=max(ans,b[i]);
    printf("%.6lf\n", ans);
    return (0-0);
}