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
#define PI  3.1415926535
class point{
	public:
	double x;
	double y;
	double z;
};
point p[50010];
bool cmp(point b, point a){
    if(a.x>b.x)return true;
    else if(a.x==b.x && a.y>b.y)return true;
    else if(a.x==b.x && a.y==b.y && a.z>b.z)return true;
    else return false;
}
int i,j,t,n;
double l,r,zr,zpre;
bool isFine(double Y){
	zpre=-1000000;
	int k=1,f=0;
	FOR(i,0,n){
		if(p[i].y<Y)
			continue;
		zr=(p[i].y-Y)*tan(p[i].z*PI/180);
		//cout<<(p[i].x-zr)<<"  "<<(p[i].x+zr)<<"  "<<i<<"  "<<Y<<endl;
		if(k==1){
			if(l<(p[i].x-zr))
				continue;
			else if(l>(p[i].x+zr))
				continue;
			else{
				k=0;
				zpre=p[i].x+zr;
			}
		}
		else{
			if(zpre<(p[i].x-zr))
				continue;
			zpre=max(p[i].x+zr,zpre);
		}
		if(r<=zpre)
			return true;
	}
	return false;
}
int main(){
	double x1,y1,z1,z2,x2,y2,a,b,hi=0,lo=0,mid;
	cin>>n;
	cin>>l>>r;
	FOR(i,0,n){
		cin>>p[i].x>>p[i].y>>p[i].z;
		hi=max(p[i].y,hi);
	}
	sort(p,p+n,cmp);
	//cout<<isFine(0)<<endl;
	while(hi-lo>1e-9){
		mid=(lo+hi)/2;
		bool f=isFine(mid);
	//	cout<<f<<endl;
		if(f){
			lo=mid;
		}
		else
			hi=mid;
	}		    	
	printf("%.9f\n",mid);	
}

