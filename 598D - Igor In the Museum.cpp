#include<bits/stdc++.h>
using namespace std;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int n,m,adjMat[1005][1005];
void fill(int r,int c, int c1, int c2)
{
	if(r<0 || r>=n || c<0 || c>=m)return;
	if(adjMat[r][c]!=c1)return;
	adjMat[r][c]=c2;
	for(int i=0;i<4;i++)
		fill(r+dr[i],c+dc[i],c1,c2);
}
int dfs(int r, int c,int c1, int c2, int c3)
{
	if(r<0 || r>=n || c<0 || c>=m)return 0;
	if(adjMat[r][c]==c2)return 1;
	if(adjMat[r][c]==c3)return 0;
	if(adjMat[r][c]!=c1)return adjMat[r][c];
	int ans=0;
	adjMat[r][c]=c3;
	for(int i=0;i<4;i++)
		ans+=dfs(r+dr[i],c+dc[i],c1,c2,c3);
	return ans;
}
int main()
{
	int x,y,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			char tmp;
			scanf(" %c",&tmp);
			if(tmp=='.')adjMat[i][j]=0;
			else adjMat[i][j]=-1;
		}	
			
	while(k--)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		int ans=dfs(x,y,0,-1,-2);
		fill(x,y,-2,ans);
		printf("%d\n",ans);
	}
	return 0;	
}
