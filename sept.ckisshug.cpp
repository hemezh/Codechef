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
#define SIZE 4
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
int fun(int m){
	int i=1;
	LL n=2,a=1;
	while(i <= m) {
	        if(i & m)
			a=(n*a)%MOD;
		n=(n*n)%MOD;
	        i <<= 1;
	}
	return a%MOD;
}
int main(){
	int n,t=1;
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1){
			n=n/2+1;
			cout<<((LL)fun(n+1)-2)%MOD<<endl;
		}
		else{
			n=n/2;
			cout<<((LL)3*(fun(n))-2)%MOD<<endl;
		}
		
	}
}

