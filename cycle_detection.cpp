#include <iostream>
#include <string>
#include <vector>

/*
Simple cycle detection with dfs

Input Format:

n = Node count
e = Edge Count
e lines of v1 v2
r = root

*/


std::vector<int> adj[1000];

int nodeCount;
int edgeCount;

void dfs(bool& isCycle, bool visited[], int curr, std::vector<int> adj[], std::vector<int> recursionStack)
{
	if (visited[curr] == true) {
		for (int i = 0; i < recursionStack.size(); i++)
			if (curr == recursionStack[i]) {
				isCycle = true;
				return;
			}
	}

	visited[curr] = true;
	recursionStack.push_back(curr);

	for (int i = 0; i < adj[curr].size(); i++) {
		dfs(isCycle, visited, adj[curr][i], adj, recursionStack); 
	}
}

int main()
{
	std::cin >> nodeCount;
	std::cin >> edgeCount;

	int temp1, temp2;

	for (int i = 0; i < edgeCount; i++) {
		std::cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
	}

	int root;

	std::cin >> root;


	bool visited[nodeCount];

	for (int i = 0; i < nodeCount; i++) {
		visited[i] = false;
	}
	bool isCycle = false;

	std::vector<int> recursionStack(0);

	dfs(isCycle, visited, root, adj, recursionStack);

	std::cout << isCycle << std::endl;


	return 0;
}