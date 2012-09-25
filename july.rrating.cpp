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
int __sign;
int __ch;
inline void S( int &x )
{
        x=0;
        while((__ch<'0' || __ch>'9') && __ch!='-' && __ch!=EOF) __ch=getchar_unlocked();
        if (__ch=='-')
                __sign=-1 , __ch=getchar_unlocked();
        else
                __sign=1;
        
        do
                x=(x<<3)+(x<<1)+__ch-'0';
        while((__ch=getchar_unlocked())>='0' && __ch<='9');
        x*=__sign;
}

int main()
{
	int t,a,b,n=0,x,y;
	priority_queue<int,vector<int>,greater<int> > q;
	priority_queue<int,vector<int>,less<int> > p;
	S(t);
	p.push(0);
	while(t--) {
		S(a);
		if(a==1) {
			n++;
			S(b);
			{
				q.push(b);
				x=p.top();
				y=q.top();
				if(x > y) {
					p.pop();
					p.push(y);
					q.pop();
					q.push(x);
				}
			}
			if(n/3 < q.size()) {
				p.push(q.top());
				q.pop();
			} 
			//cout<<n<<"   "<<q.size()<<"  "<<n/3<<"   "<<q.top()<<endl;
		}
		else if(a==2) {
			if(n/3 == 0)
				printf("No reviews yet\n");
			else 
				printf("%d\n",q.top());
				
		}
	}
}

