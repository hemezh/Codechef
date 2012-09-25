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
#define LL (long long int)
int main(){
	int i,n,map[1010],t,j,k,p;
	long long int a[1010],x;
	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,0,n)
			cin>>a[i];
		/*sort(a,a+n);
		memset(map,0,sizeof map);
		k=1;
		FOR(i,0,n){
			FOR(j,i+1,n){
				if(map[i] || map[j])
					continue;
				x=a[i]^a[j];
				if(binary_search(a,a+n,x)){
					p=int(lower_bound(a,a+n,x)-a);
					if(map[p])
						continue;
						map[i]=map[j]=map[p]=k;
					k++;
				}
					
			}
		}
		FOR(i,0,n){
			if(!map[i])
				map[i]=k;
		}
		*/
		FOR(i,0,n){
			cout<<1<<" ";
		}
		cout<<endl;
		
	}    
}

