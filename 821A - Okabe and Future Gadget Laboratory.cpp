#include<set>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int n, A[55][55], t;
	vector<set<int> > sr, sc;
	cin >> n;
	sr.resize(n);
	sc.resize(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> t;
			A[i][j] = t;
			sr[i].insert(t);
			sc[j].insert(t);
		}
	}
	bool valid = true, found = false;
	for (int i = 0; i<n && valid; i++)
	{
		for (int j = 0; j<n && valid; j++)
		{
			int tmp = A[i][j];
			if (tmp>1)
			{
				found = false;
				for (int k : sr[i])
				{
					if (k == tmp)continue;
					int val = tmp - k;
					if (val>0 && sc[j].count(val)>0)
					{
						found = true; 
						break;
						//cout << i << " " << j << " " << val << " " << A[i][k] << endl;
					}
				}
				valid = found;
			}
		}
	}
	if (valid)cout << "Yes";
	else cout << "No";
	return 0;
}
