#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n,n1,n2,mn,mx,t,prev,zeros=0;
	cin>>n>>k;
	vector<int> A;
	vector<pair<int,int> >B;
	A.resize(n);
	n1=n2=-1;
	bool flag=false,ordered=true;
	mn=1e9;
	mx=-1e9;
	prev=0;
	for(int i=0;i<n;i++)
	{
		
		cin>>A[i];
		if(A[i] && ordered)
		{
			if(A[i]<prev)
			{
				ordered=false;
			}
			else 
			prev=A[i];
		}
		if(!A[i])
		{
			zeros++;
			if(!flag){
				flag=true;
				n1=i-1;
			} 
		}
		else if(flag)
		{
			flag=false;
			n2=i;
			B.push_back(make_pair(n1,n2));
			
		}
	}
	if(!B.size())B.push_back(make_pair(n1,n2));
	for(int i=0;i<k;i++){cin>>t;mn=min(t,mn);mx=max(t,mx);}
	int i=0;
	bool can=ordered?false:true;
	while(i<B.size() && !can)
	{
		
		zeros--;
		int f=B[i].first,s=B[i].second;
		if(f==-1 && s==-1)can=true;
		else if(f==-1)can=mx>A[s];
		else if(s==-1)can=mn<A[f];
		else
		{
			if(mx>A[s] || mn<A[f])can=true;
		}
		i++;
	}
	if(!can && zeros>0)can=true;
	if(can)cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
