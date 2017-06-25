#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll tot(ll x)
{
	return ((x*(x-1))/2);
}
ll calc(ll x, ll y)
{
	x++;y++;
	ll sum=(x*tot(y))+(y*tot(x));
	return sum;
}
int main()
{
	ll y,x,m,b,mx=0,tmp;
	cin>>m>>b;
	x=m*b;y=b;
	for(ll xx=x;xx>=0;xx--)
	{
		tmp=calc(((x-xx)/m),xx);
		if(mx<tmp)mx=tmp;
	}
	cout<<mx;
	
}
