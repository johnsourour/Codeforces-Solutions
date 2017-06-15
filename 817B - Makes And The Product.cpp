#include<bits/stdc++.h>
using namespace std;
long long comb(long long n, long long k)
{
	long long prod = 1;
	for (int i = 1; i <= k; i++)
		prod *= (n - i + 1);
	for (int i = 2; i <= k; i++)
		prod /= (i);
	return prod;
}
int main()
{
	 unsigned long long n,f,s,t,tmp;
	f=s=t=10000000000;
	multiset<long long> ms;
	cin>>n;
	for(unsigned long long i=0;i<n;i++)
	{
		cin>>tmp;
		ms.insert(tmp);
		
		if(tmp<t){f=s;s=t;t=tmp;}
		else if(tmp<s){f=s;s=tmp;}
		else if(tmp<f)f=tmp;
		
	}
	if(t==f && f==s)
		cout<<comb(ms.count(f),3)<<endl;
	else if(f==s)
		cout<<comb(ms.count(f),2)<<endl;
	else if(t==s)
		cout<<ms.count(f)<<endl;
	else cout<<ms.count(f)*ms.count(t)*ms.count(s)<<endl;

	return 0;
}
