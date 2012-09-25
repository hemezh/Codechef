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
void print(int arr[][10]){
	int i,j;
	FOR(i,0,4){
		FOR(j,0,10)
			cout<<arr[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl;
}
int arr[4][10];
int t,i,j,k,l,d,sum;
long long int x;
int main(){
	char str[10010];
	cin>>t;
	char c=getchar_unlocked();
	while(t--){
		int arr[3][10]={0};
		long long int sum=0;
		c=getchar_unlocked();
		while(c!=EOF && c!='\n'){
				d=c-'0';
				sum+=arr[2][9-d];
				if(d==9)
					sum+=arr[2][9];
				if(sum>=MOD)
					sum-=MOD;
				for(k=1;k>=0;k--) {
					for(j=0;j<=9;j++){
						if(arr[k][j]){
							l=(j+d>9)?(j+d-9):(j+d);
							x=((LL)arr[k][j]+arr[k+1][l]);
							if(x>=MOD)
								x-=MOD;
							arr[k+1][l]=x;
						}
					}					
				}
				arr[0][d]++;
				c=getchar_unlocked();
		}
		printf("%lld\n",((LL)arr[0][9]+arr[1][9]+arr[2][9]+sum)%MOD);
	}
}

