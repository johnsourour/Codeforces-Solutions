#include<bits/stdc++.h>
using namespace std;
long long n;
bool can(long long i, long long s)
{
	long long sum=0,n=i;
	while(i)
	{
		sum+=i%10;
		i/=10;
	}
	if(n-sum>=s)return true;
	else return false;
}
int main()
{
	long long s;
	cin>>n>>s;
	long long t=min(s+168,n),ans=n-t;
	if(s){
		for(long long i=s;i<=t;i++)
		{
			if(can(i,s))ans++;
		}
		cout<<ans<<endl;
	}
}
