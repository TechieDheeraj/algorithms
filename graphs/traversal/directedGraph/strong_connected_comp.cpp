/**
 *      file    :  strong_connected_comp.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Mar 02 00:48:57 
 *      lastMod :  Tue Mar  2 00:48:57 2021 
 **/

#include<bits/stdc++.h>
#include"diagraph.hpp"

using namespace diagraph;

class KosaRajuShair {
  private:
    int vertices;
    std::stack<int>ts;
    std::vector<int>visited;
    std::vector<int>scc;
  public:
    KosaRajuShair(int vert): vertices{vert} {
      visited.resize(this->vertices, 0);
      scc.resize(this->vertices, 0);
    }
    
    void dfs(int s, std::vector<std::vector<int>>& gh, bool findTs) {
      dfs(s, gh, findTs, -1);
    }

    void dfs(int s, std::vector<std::vector<int>>& gh, bool findTs, int compc) {

      if (!visited[s]) {
        visited[s] = 1;

        if (compc >= 0) {
          scc[s] = compc;
        }

        for (int i = 0; i < gh[s].size(); ++i) {
          if (!visited[gh[s][i]]) {
            dfs(gh[s][i], gh, findTs, compc);
          }
        }
        if (findTs)
          this->ts.push(s);
      }
    }

    void topologicalSort(std::vector<std::vector<int>>& gh) {
      for ( int i = 0; i < this->vertices; ++i) {  
        dfs(i, gh, true); 
      }
    }

    std::vector<int> strongCC(diagraph::Diagraph* dObj) {
      std::vector<std::vector<int>> revGraph = dObj->reverse();
      std::cout << " ==========  Reversed graph ========== " << std::endl;
      dObj->printGraph(0, revGraph);

      /* 
       * Phase 1: Compute Reverse PostOrder(Topological Order) of G^R
       * Phase 2: Run DFS in G, visiting unmarked vertices in Reverse postorder of G^R
       */

      topologicalSort(revGraph);
      int componentNum = 0;
      std::fill(visited.begin(), visited.end(), 0);

      auto origGraph = dObj->getGraph();

      while(!this->ts.empty()) {

        int v = ts.top(); ts.pop();
        if (!visited[v]) {
          dfs(v, origGraph, false, componentNum);

          componentNum++;
        }
      }
      return this->scc;
    }
};

int main() {

  freopen("in3.txt", "r", stdin);

  int vert;
  std::cin >> vert;

  KosaRajuShair *obj = new KosaRajuShair(vert);
  Diagraph *gObj = new Diagraph(vert);
  int edges;
  std::cin >> edges;

  for (int i =0; i < edges; ++i) {
    int s, e;
    std::cin >> s >> e;
    gObj->addEdge(s, e);
  }

  gObj->printGraph();

  auto res = obj->strongCC(gObj);
  std::cout << " =====================  Strongly Connected component list ==================== " << std::endl;
  std::cout << "\n     <Vertex>   ComponentNo. " << std::endl;
  for (int i = 0; i < res.size(); ++i) {
    std::cout << "\t" << i << "\t   " << res[i] << std::endl;
  }
    
  return 0;
}
