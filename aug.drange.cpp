#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

//#define S(n)             scanf("%d",&n)
#define SL(n)            scanf("%lld",&n)
#define SD(n)            scanf("%f",&n)
#define SS(a)            scanf("%s",a)
#define DB(x)            cout<<#x<<" : "<<x<<endl;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;
int gcd( int a, int b ) {  if( !b ) return a;  return gcd( b, a % b ); }
#define getcx(ch)	(ch=getchar_unlocked())

/*======================================IO OPTIMISED FUNCTIONS===================================*/
int __sign;
int __ch;
inline void S( int &x )
{
			x=0;
			while((__ch<'0' || __ch>'9') && __ch!='-' && __ch!=EOF)	__ch=getchar_unlocked();
			if (__ch=='-')
				__sign=-1 , __ch=getchar_unlocked();
			else
				__sign=1;
			
			do
				x=(x<<3)+(x<<1)+__ch-'0';
			while((__ch=getchar_unlocked())>='0' && __ch<='9');
			x*=__sign;
}
/*===============================================================================================*/

#define MAX 3000007
long long T[MAX];

int m,n,c;

void update1 ( int node , int b , int e , int i , int j , int k)
{
    int n2 =  node<<1;
    if( b > j || e < i || b > e )		return;

    if( i<=b && e<=j )
    {
    	T[node] += k;
    	return;
	}

	update1( n2 , b , (b+e)/2 , i , j , k);
	update1( n2+1 , (b+e)/2 +1 , e , i , j , k);
}

void update2 ( int node , int b , int e , int i , int j , int k)
{
    int n2 =  node<<1;
    if( b > j || e < i || b > e )		return;

    if( i<=b && e<=j )
    {
    	T[node] -= k;
    	return;
	}

	update2( n2 , b , (b+e)/2 , i , j , k);
	update2( n2+1 , (b+e)/2 +1 , e , i , j , k);
}

long long query ( int node , int b , int e , int i )
{
	if (b>i || e<i || b>e)	return 0;

    if( b >= i && e <= i  )
        return T[node];

    return T[node] + query( node*2 , b , (b+e)/2 , i ) + query( node*2 +1 , (b+e)/2 +1  , e , i );
}


int main()
{
	int t;
	S(t);
	while(t--) {
		S(n), S(m);
		int q;
		n++;
		memset(T,0,sizeof T);
		for (int i = 1; i < n; i += 1)
		{
			update1(1,1,n,i,i,i);
		}
		/*
		for (int i = 1; i <n; i += 1)
		{		
			printf("%lld ",query(1,1,n,i));
		}
		cout<<endl;
		//*/
		for (int i = 0; i < m; i += 1)
		{
			int a,b,k;
			S(q), S(a), S(b) , S(k);
				
			if (q==2)
				update2(1,1,n,a,b,k);
			else
				update1(1,1,n,a,b,k);
		
		/*
		for (int i = 1; i <n; i += 1)
		{		
			printf("%lld ",query(1,1,n,i));
		}
		cout<<endl;
		//*/
		}
		int temp,mn=1e9,mx=-1e9;
		for (int i = 1; i < n; i += 1)
		{		
			temp=query(1,1,n,i);
			mn=min(mn,temp);
			mx=max( mx,temp );
		}
		cout<<mx-mn<<endl;

	}
	return 0;
}






