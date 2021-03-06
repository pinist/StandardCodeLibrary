#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e3+5;

int bit[M][M];//Binary Index Tree
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int v) //add v at (x,y)
{
	for(;x<M;x+=lowbit(x))
		for(int j=y;j<M;j+=lowbit(j))
			bit[x][j]+=v;
}
void init(int n,int m,int a[M][M])
{
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			add(i,j,a[i][j]);
}
int get_sum(int x,int y) //sum of (1~x,1~y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=bit[i][j];
	return ans;
}
int get_sum(int stx,int sty,int edx,int edy) // sum of (stx~edx,sty~edy)
{
	return get_sum(edx,edy)-get_sum(stx-1,edy)-get_sum(edx,sty-1)+get_sum(stx-1,sty-1);
}

int main()
{
	return 0;
}