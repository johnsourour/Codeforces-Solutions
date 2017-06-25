#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, val,cnt=0,cur=1,last;
  vector<int> st;
	vector<int>::iterator it;
	string s;
	bool ok=false,was=false;
	cin>>n;
	while(cur<=n)
	{
		cin>>s;
		if(s=="add")
		{
			ok=false;
			cin>>val;
      st.push_back(val);
			if(val!=cur)was=false;
		}
		else
		{
			if(st.back()==cur)
			{
				st.pop_back();cur++;
			}
			
			else if(ok || was ||  st.back()==last)
			{
				cur++;				
				ok=true;
			}
			else if(st.back()<cur){
				while(st.back()<cur)st.pop_back();
				if(st.back()==cur){
				st.pop_back();cur++;ok=false;}
				else
				{
					
				ok=true;
				cnt++;cur++;
				}
			}
			else
			{
				ok=true;
				was=true;
				last=st.back();
				cnt++;cur++;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}
