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
int main() {
	int t,n,i;
	string str,strt;
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>str;
		strt=str;
		if(str[0]=='1')
			strt[1]='1';
		FOR(i,1,n-1)
			if(str[i]=='1')
	    			strt[i-1]=strt[i+1]='1';
	    	if(str[n-1]=='1')
	    		strt[n-2]=1;
	    	int cnt=0;
	    	FOR(i,0,n)
	    		cnt+=strt[i]=='0';
	    	cout<<cnt<<endl;
	}	
}

