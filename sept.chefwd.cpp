#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define bitcount __builtin_popcount
#define gcd __gcd
#define VVII vector< vector < pair<int,int> > > 
#define VVI vector< vector < int > > 
#define VII vector < pair<int,int> >
#define MSI map< string , int >
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ii pair< int, int >
#define LL long long int
#define MOD 1000000007
#define MUL(a,b) ((int)((((int64)(a))*((int64)(b)))%MOD))
#define SIZE 4
#define MAX 100000
int size=4;
struct matrix {
        LL mat[SIZE][SIZE];
        void fillZero() {
                memset(mat, 0, sizeof mat);
        }
        void makeUnit() {
                fillZero();
                for(int i = 0; i < size; i++)
                        mat[i][i] = 1;
        }
        void operator*=(struct matrix& mat1) {
                struct matrix res;
                res.fillZero();
                for(int i = 0; i < size; i++)
                        for(int j = 0; j < size; j++)
                                for(int k = 0; k < size; k++) {
                                        res.mat[i][j] += ((LL)mat[i][k] * mat1.mat[k][j]) % MOD;
                                        if(res.mat[i][j] >= MOD)
                                                res.mat[i][j] -= MOD;
                                }
                for(int i = 0; i < size; i++)
                        for(int j = 0; j < size; j++)
                                mat[i][j] = res.mat[i][j];
        }
};
struct matrix mat1,res;
int pow(LL m){
	LL i=1;
	LL n=2,a=1;
	while(i <= m) {
	        if(i & m)
			a=(n*a)%MOD;
		n=(n*n)%MOD;
	        i <<= 1;
	}
	return a%MOD;
}
int F[MAX+20],G[MAX+20];
int fun(LL n){
	if(n==2)
		return 5;
	if(n==1)
		return 0;
	n-=MAX;
	LL i=1,x;
	mat1.fillZero();
	res.makeUnit();
	mat1.mat[0][0]=1;
	mat1.mat[0][1]=1;
	mat1.mat[0][2]=1;
	mat1.mat[1][0]=1;
	mat1.mat[2][2]=1;
	mat1.mat[2][3]=1;
	mat1.mat[3][2]=1;
	while(i <= n) {
	        if(i & n)
	                res *= mat1;
	        mat1 *= mat1;
	        i <<= 1;
	}
	x=((LL)res.mat[0][0]*G[MAX]+res.mat[0][1]*G[MAX-1]+res.mat[0][2]*F[MAX]+res.mat[0][3]*F[MAX-1])%MOD;
	if(x<0)
		x+=MOD;
	return x;
}
int main(){
	int i;
	LL n,t=1,x;
	G[2]=5;G[3]=18;F[3]=21;F[2]=13;
	FOR(i,4,MAX+10){
		G[i]=((LL)G[i-1]+G[i-2]+F[i-1])%MOD;
		F[i]=((LL)F[i-1]+F[i-2])%MOD;
	}
	//cout<<"dome"<<store[10];
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=MAX)
			cout<<G[n]<<endl;
		else
			cout<<fun(n)<<endl;		
	}
}
