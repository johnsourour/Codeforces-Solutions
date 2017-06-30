#include<bits/stdc++.h>
using namespace std;

int main()
{
	int se[105],A[105],n,m,cnt,t,cur;

	bool possible;
	memset(A,-1, sizeof A);
		memset(se,-1, sizeof se);
	cnt=0;
	cin>>n>>m;
	
	possible=true;
	cin>>cur;
	for(int i=1;i<m;i++)
	{
		cin>>t;
		
		if(possible)
		{
			int val;
			if(t<=cur)val=(n-cur+t);
			else val=t-cur;
			if(se[val]!=cur && se[val]!=-1)possible=false;
	     	se[val]=cur;
			
			if(A[cur]==-1){
				
				A[cur]=val;
			}
			else if(A[cur]!=val)possible=false;
			
			cur=t;
		}
	}
	if(!possible)cout<<-1;
	else 
	{
		stack<int> st;
		for(int k=1;k<=n;k++)
		{
		
			if(se[k]==-1){st.push(k);	}
			//cout<<se[k];
		}
		for(int i=1;i<=n;i++)
		{
			if(A[i]!=-1)cout<<A[i]<<" ";
			else 
			{
				cout<<st.top()<<" ";
				st.pop();
			}
		}
	}
	
	

}
