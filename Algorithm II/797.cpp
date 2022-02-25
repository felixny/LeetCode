// 797. All Paths From Source to Target

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  void dfs(vector<vector<int>>& graph, vector<vector<int>>& result,
           vector<int>& path, int u) {
    path.push_back(u);
    if (u == graph.size() - 1)
      result.push_back(path);
    else
      for (int v : graph[u]) dfs(graph, result, path, v);
    path.pop_back();
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(graph, result, path, 0);
    return result;
  }
};



int main() { 
  
  vector<vector<int>> graph{{1, 2}, {3}, {3}, {}};
  Solution s;
  graph = s.allPathsSourceTarget(graph);
  
  
  //cout << graph.size() << endl;
  
 for (int v : graph[0])
 cout << v << endl;

 for (int v : graph[1])
 cout << v << endl;



  return 0; }