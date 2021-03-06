#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MV=1e5+5;
struct Edge
{
	int v;
	bool isb; //is bridge
	Edge(int v=0,bool isb=0):v(v),isb(isb){}
};
vector<Edge> g[MV];
int nv;
int dfn[MV],dfs_clock;

int dfs(int u,int fa)
{
	int lowu=dfn[u]=++dfs_clock,lowv;
	int ch=0; //number of children
	int v;
	for(Edge &e:g[u])
	{
		v=e.v;
		if(!dfn[v])
		{
			ch++;
			lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>dfn[u]) e.isb=1;
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
			lowu=min(lowu,dfn[v]);
	}
	return lowu;
}
void find_cut_vertex()
{
	memset(dfn,0,sizeof(dfn));
	dfs_clock=0;
	for(int i=0;i<nv;i++)
		dfs(nv,-1);
}


int main()
{
	return 0;
}