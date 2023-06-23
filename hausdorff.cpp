#include<bits/stdc++.h>
using namespace std;

namespace hausdorff{
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rd(l,r) uniform_int_distribution<int>(l,r)(rnd)

typedef vector<double> point;
typedef vector<point> point_set;
const int lambda=100;
const double inf=1e16, eps=1e-8;
int k;
double cmax;

bool chkmin(double &x, const double &v){
    if(v<x) {x=v; return true;}
    return false;
}
bool chkmax(double &x, const double &v){
    if(v>x) {x=v; return true;}
    return false;
}
double distan(const point &x, const point &y){
    double ret=0;
    for(int i=0; i<k; i++) ret+=(x[i]-y[i])*(x[i]-y[i]);
    return ret;
}

point_set rulingout(const point_set &A, const point &U){
    point_set A0;
    for(int len=A.size(), i=0; i<len; i++)
        if(U[i]>cmax) A0.push_back(A[i]);
    return A0;
}

void hd(const point_set &A, const point_set &B, const point &U, point &V){
    double cmin, d1, d2;
    point_set A0=rulingout(A,U);
    for(int ilen=A0.size(), jlen=B.size(), isp=jlen/2, i=0; i<ilen; i++){
        cmin=d1=d2=inf;
        for(int y=isp-1, z=isp; y>=0 || z<jlen; y--, z++){
            if(y>=0){
                d1=distan(A0[i], B[y]);
                chkmin(V[y], d1);
            }
            if(z<jlen){
                d2=distan(A0[i], B[z]);
                chkmin(V[z],d2);
            }
            chkmin(cmin, min(d1,d2));
            if(cmin<cmax){
                isp=(d1<d2?y:z);
                break;
            }
        }
        chkmax(cmax, cmin);
    }
}

void tmdc(const point_set &A, const point_set &B, point &U, point &V){
    double cmin, d1, d2;
    int ilen=B.size(), delta=(ilen+lambda-1)/lambda, st=rd(0,delta-1),
        jlen=A.size(), isp=jlen/2;
    for(int i=st; i<ilen; i+=delta){
        cmin=d1=d2=inf;
        for(int y=isp-1, z=isp; y>=0 || z<jlen; y--, z++){
            if(y>=0){
                d1=distan(B[i], A[y]);
                chkmin(U[y], d1);
            }
            if(z<jlen){
                d2=distan(B[i], A[z]);
                chkmin(U[z], d2);
            }
            chkmin(cmin, min(d1,d2));
            chkmin(V[i], min(d1,d2));
            if(cmin<cmax){
                isp=(d1<d2?y:z);
                break;
            }
        }
        chkmax(cmax,cmin);
    }
}

double HD(int _k, const point_set &A, const point_set &B){
    // init
    k=_k; cmax=0; 
    point U,V;
    U.resize(A.size()); for(int len=A.size(), i=0; i<len; i++) U[i]=inf; 
    V.resize(B.size()); for(int len=B.size(), i=0; i<len; i++) V[i]=inf; 
    
    tmdc(A,B,U,V);
    hd(A,B,U,V);
    hd(B,A,V,U);
    return sqrt(cmax);
}
}

int k,n,m;
hausdorff::point_set A,B;
int main(){
    scanf("%d%d%d", &k, &m, &n); // dim |A| |B|
    vector<double> qwq; qwq.resize(k);
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++) scanf("%lf", &qwq[j]);
        A.push_back(qwq);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++)scanf("%lf", &qwq[j]);
        B.push_back(qwq);
    }
    printf("%.6lf\n", hausdorff::HD(k,A,B));
    return (0-0);
}