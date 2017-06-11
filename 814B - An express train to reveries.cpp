#include<bits/stdc++.h>
using namespace std;
int main()
{
	multiset<int> AS;
	vector<int>A;
	int n,t,ind,val;
	bool done=false;
	cin>>n;
	A.resize(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
		if(AS.count(A[i]))
		ind=i;
		AS.insert(A[i]);
	}
	for(int i=0;i<n;i++){
		cin>>t;
		if(!AS.count(i+1))val=i+1;

		if(t!=A[i])
		{
			if(A[i]==A[ind])ind=i;
			if(!AS.count(t) && AS.count(A[i])>1){A[i]=t;done=true;break;}
		}
	}
	if(!done)A[ind]=val;
	for(int i:A)cout<<i<<" ";
	
	return 0;
}
