#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트 version
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
}

// DFS (Depth First Search)
void Dfs(int here)
{
	// 첫 방문!
	visited[here] = true;
	cout << "Visited : " << here << endl;


	// 인접 리스트 version
	// 모든 인접 정점을 순회
	for (int i = 0; i < adjacent[here].size(); ++i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
		{
			Dfs(there);
		}
	}

}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; ++i)
	{
		if (visited[i] == false)
		{
			Dfs(i);
		}
	}

}

int main()
{
	CreateGraph();

	DfsAll();

	return 0;
}