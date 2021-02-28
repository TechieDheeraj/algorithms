/**
 *      file    :  diagraphUsingAdjacencyList.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Feb 28 17:36:56 
 *      lastMod :  Sun Feb 28 17:36:56 2021 
 **/

#include<bits/stdc++.h>

#define LOCAL 1
using namespace std;

class Diagraph {
  private:
    vector<vector<int>> gh;
    vector<int>visited;
    vector<int>edgeTo;
    stack<int>revPost;
    int vertices;

  public:
    Diagraph() : Diagraph(5) { }
    Diagraph(int vert) : vertices{vert} {
      gh.resize(this->vertices);
      visited.resize(this->vertices, 0);
      edgeTo.resize(this->vertices);
    }

    void addEdge(int s, int e) {
      gh[s].push_back(e);
    }
    
    void printGraph() {
      static int vert = 0;    

      if (vert >= this->vertices)
        return;

      cout << vert << " -> "; 
      string res;
      for (int i =0; i < gh[vert].size(); ++i)
        cout << gh[vert][i] << (res = ((gh[vert].size()-i) == 1) ? " " : "-> ");
      cout << "\n";
      vert++;
      printGraph();
    }

    void dfs(int s) {
      // All the nodes reachable from s;
      if (!visited[s]) {
        visited[s] = 1;
        cout << "visited " << s << endl;

        for (int i = 0; i < gh[s].size(); ++i) {
          if (!visited[gh[s][i]]) {
            edgeTo[gh[s][i]] = s;
            dfs(gh[s][i]);
          }
        }
        this->revPost.push(s);
      }
    }

    void bfs(int s) {
      fill(visited.begin(), visited.end(), 0);
      queue<int>q;

      q.push(s);
      cout << "visited " << s << endl;
      visited[s] = 1;

      while(!q.empty()) {
        auto node = q.front(); q.pop();

        for (int i=0; i < gh[node].size(); ++i) {
          if (!visited[gh[node][i]]) {
            visited[gh[node][i]] = 1;
            cout << "visited " << gh[node][i] << endl;
            q.push(gh[node][i]);
          }
        }
      }
    }

    void topologicalSort() {
      fill(visited.begin(), visited.end(), 0);
      std::stack<int>().swap(this->revPost);

      for (int i = 0; i < this->vertices; ++i) {
        dfs(i);
      }
    }

    stack<int> reversePostOrder() {
      return this->revPost;
    }
};

int main() {

  int vert;
  freopen("in1.txt", "r", stdin);

  cin >> vert;

  Diagraph *gObj = new Diagraph(vert); 
  int edges;

  cin >> edges;

  for (int i = 0; i < edges; ++i) {
    int s, e;
    cin >> s >> e;

    gObj->addEdge(s, e);
  }
    
  cout << "=============== Adjacency List =================" << endl;
  gObj->printGraph();
  int s = 5;
  cout << "=============== All nodes reachable from " << s << " =================" << endl;
  gObj->dfs(s);
  cout << "=============== Using BFS Starting from " << s << " =================" << endl;
  gObj->bfs(s);

  cout << "=============== Using Topological Sort " << s << " =================" << endl;
  gObj->topologicalSort(); 
  auto revOrder = gObj->reversePostOrder();
  cout << "\nReverse Postorder is: " << "\n"; 

  string res = "";
  while(!revOrder.empty()) {
    cout << revOrder.top() << (res = (revOrder.size() == 1) ? "": "-> "); 
    revOrder.pop();
  }
  cout << "\n";

  return 0;
}
