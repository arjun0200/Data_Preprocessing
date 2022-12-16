#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long  ll;
#define  maxn 1005
int flag[maxn],d[maxn],g[maxn][maxn],a[maxn],tmp[maxn];
vector<int>q[maxn];
int  main(void)
{
	int n,m,i,j,x,y,mark;
	while(scanf("%d%d",&n,&m),n!=0 && m!=0)
	{
		mark=1;
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
		}
		for(i=n;i;i--)
		{
			int k,u=-1;
			for(j=1;j<=n;j++)
				if(flag[j]==0 && d[j]>u)
					k=j,u=d[j];
			a[i]=k;
			flag[k]=1;
			for(j=1;j<=n;j++)
				if(flag[j]==0 && g[k][j])
					d[j]++;
		}
		for(i=1;i<=n;i++)
		{
			memset(tmp,0,sizeof(tmp));
			for(j=i+1;j<=n;j++)
				if(g[a[i]][a[j]])
					tmp[++tmp[0]]=a[j];
			for(j=2;j<=tmp[0];j++)
				if(!g[tmp[1]][tmp[j]])
					mark=0;
		}
		if(mark)
			printf("Perfect\n");
	    else
			printf("Imperfect\n");
		printf("\n");
	}
	return 0;
}