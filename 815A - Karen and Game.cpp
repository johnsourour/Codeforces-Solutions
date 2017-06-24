#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int A[105][105],n,m;
void rotate()
{
	for(int i=0;i<n;i++)for(int j=i+1;j<m;j++)
	{
		swap(A[i][j],A[j][i]);
	}
}
bool check()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)if(A[i][j])return true;
		return false;
}
int main()
{
	int R[105],t;
	bool done=true,swapped=false;
	ii C[105];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)cin>>A[i][j];
	
	if(n>m)
	{
		swapped=true;
		swap(n,m);
		rotate();
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		t=A[i][j];
		if(t)done=false;
		if(j==0)R[i]=t;
		else R[i]=min(R[i],t);
		if(i==0)C[j]=ii(t,t);
		else C[j]=ii(max(C[j].first,t),min(C[j].second,t));
	}
	
	int mxr=0;
	bool row=false;
	vector<string> ans;
	
	if(!done)
	for(int i=0;i<n;i++)
		if(R[i])
		{
			row=true;
			string tmp=swapped?"col ":"row ";
			tmp+=to_string(i+1);
			for(int k=0;k<R[i];k++)
			{
				for(int j=0;j<m;j++)A[i][j]--;
				ans.push_back(tmp);
			}
			mxr=max(mxr,R[i]);
		}
		
		if(!done)
	for(int j=0;j<m;j++)
	{
		int c=row?C[j].first-mxr:C[j].second;
		if(c)
		{
			string tmp=swapped?"row ":"col ";
			tmp+=to_string(j+1);
			for(int k=0;k<c;k++)
			{
				for(int i=0;i<n;i++)A[i][j]--;
				ans.push_back(tmp);
			}
		}
	}
	
	if(check() || (!ans.size() && !done))cout<<-1<<endl;
	else if(done)cout<<0<<endl;
	else
	{
		cout<<ans.size()<<endl;
		for(string s:ans)cout<<s<<endl;
	}
}
	
	
