#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n,m,num;
	char c;
	cin>>n>>s>>m;
	
	for(int k=0;k<m;k++)
	{
		cin>>num>>c;
		int mx=0,cur=0,add=num;
		for(int i=0;i<n;i++)
		{
			char cc=s.at(i);
			if(cc==c){
				cur++;}
			else if(add>0)
			{
				add--;
				cur++;
			}
			else
			{
				while (s.at(i - cur) == c) cur--;
			
			}
			cout<<cur<<endl;
			mx=max(mx,cur);
		}
		
		cout<<mx<<endl;
	}
	return 0;
}
