
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<cassert>
#include<map>
#include<set>

using namespace std;
char *ipos, *opos, InpFile[90000000], OutFile[90000], DIP[20];
int n,m,c,x,y,z,t,i,q;
int a[1000004];
inline int input(int flag=0) {

	while(*ipos <= 32) ++ipos;
	if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
	int x=0, neg = 0;char c;
	while( true ) {
		c=*ipos++; if(c == '-') neg = 1;
		else {
			if (c<=32) return neg?-x:x;
			x=(x<<1)+(x<<3)+c-'0';
		}
	}
}
inline void output(int x,int flag = 1) {
        if(x<0)
        {
          *opos++='-';
          x *= -1;
        }
	int dig=0;
	int y;
	while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
	while (dig--) *opos++=DIP[dig];
	*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
	ipos = InpFile; opos = OutFile;
	fread_unlocked(InpFile,90000000,1,stdin);
}
inline void FlushFASTIO() {
	fwrite_unlocked(OutFile,opos-OutFile,1,stdout);	
}

void U(int loc,int dif){
	for(int i=loc;i<=n;i+=(i&-i)) a[i]+=dif;
}
int Q(int loc){
	int ans=0;
	for(int i=loc;i>=1;i-=(i&-i)) ans+=a[i];
	return ans;
}
int main()
{
	InitFASTIO();
	t=input();
	while(t--)
	{
		memset(a,0,sizeof a);
		n=input();
		m=input();
		for (int i = 1; i <= n; i += 1)
		{
			U(i,1);
		}
		while(m--){
			q=input();
			x=input();
			y=input();
			z=input();
				
			if(q==2){
				U(x,-z);
				U(y+1,z);
			}
			else{
				U(x,z);
				U(y+1,-z);
			}
		}
		int temp,mn=1e9,mx=-1e9;
		for (int i = 1; i <= n; i += 1)
		{		
			temp=Q(i);
			mn=min(mn,temp);
			mx=max( mx,temp );
		}
		output(mx-mn);
	}
	FlushFASTIO();
	return 0;
}

