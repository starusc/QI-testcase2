#include<bits/stdc++.h>
using namespace std;
void cmd(char *s, int fl){
    if(system(s)){
        cerr<<"Wrong on case "<<fl<<" !!!\n";
        exit(0);
    }
}
int main(){
    for(int T=1; T<=1000; T++){
        if((T-1)%10==0) cerr<<"Running on testcase #"<<T<<" ...";
        cmd("./gen > in.txt", 1);
        cmd("./hausdorff < in.txt > out_mine.txt", 2);
        cmd("./bf < in.txt > out_bf.txt", 3);
        cmd("diff -s out_mine.txt out_bf.txt", 4);
    }
    return (0-0);
}