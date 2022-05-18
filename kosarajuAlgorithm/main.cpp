#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(int node, stack<int> &st, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1;
    for(auto it: adj[node]) {
        if(!visited[it]) {
            dfs(it, st, visited, adj);
        }
    }

    st.push(node);
}
void reverseDfs(int node, vector<int> &visited, vector<int> transpose[]) {
    cout << node << " ";
    visited[node] = 1;
    for(auto it: transpose[node]) {
        if(!visited[it]) {
            reverseDfs(it, visited, transpose);
        }
    }
}
int main() {

    int n=6;
	vector<int> adj[n+1];
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);

	stack<int> st;
	vector<int> visited(n+1, 0);

	for(int i=1;i<=n;i++) {
	    if(!visited[i]) {
	        dfs(i, st, visited, adj);
	    }
	}

	vector<int> transpose[n+1];

	for(int node=1;node<=n;node++) {
	    visited[node] = 0;
	    for(int value: adj[node]) {
	        transpose[value].push_back(node);
	    }
	}

    int count=1;

	while(!st.empty()) {
	    int node = st.top();
	    st.pop();
	    if(!visited[node]) {
	        cout << "Strongly connected component "<<count<<": ";
	        reverseDfs(node, visited, transpose);
	        cout << endl;
	        count++;
	    }

	}


	return 0;
}
