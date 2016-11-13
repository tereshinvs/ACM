#include <iostream>
#include <map>

using namespace std;

int n, m, k;
map< pair<int, int>, vector< pair<unsigned long long, bool > > > table;
pair< pair<unsigned long long, unsigned long long>, int > data[100];

int res = 0, res_schedule[100][2], temp_schedule[100][2];

void dfs()

int main()
	{
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++)
			cin >> data[i].first.first >> data[i].first.second >> data[i].second;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				for (int q = data[i].first.first; q <= data[i].first.second; q++)
					{
						if (data[j].first.first <= q*k && q*k <= data[i].first.second)
							map[make_pair(i, j)].push_back(make_pair(q, true));
						if (data[j].first.first <= q+k && q+k <= data[i].first.second)
							map[make_pair(i, j)].push_back(make_pair(q, false));
					}
		for (int i = 0; i < m; i++)
			dfs(i);
		return 0;
	}