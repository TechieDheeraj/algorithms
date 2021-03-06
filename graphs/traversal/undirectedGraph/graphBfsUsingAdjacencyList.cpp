/**
 *      file    :  graphBfsUsingAdjacencyList.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Feb 14 18:27:56 
 *      lastMod :  Sun Feb 14 18:27:56 2021 
 **/

#include<bits/stdc++.h>

using namespace std;

class MyException : public exception {

  public:
    string what() {
      return "My exception ";
    }
};

template<class T>
class GraphAL {

  public:
    //vector<T>gh;
    vector<vector<T>>gh;
    int vertices;
    vector<T>edgeTo;
    vector<int>visitedDfs;

    GraphAL(int vert) {
      //gh = new vector<T>gh[vert];
      gh.resize(vert);
      this->edgeTo.resize(vert);
      this->vertices = vert;
      this->visitedDfs.resize(vert);
    }

    void addEdge(T u, T v) { 
      if (u >= vertices || v >= vertices)
        throw "Invalid vertices "; 

      gh[u].push_back(v);
      gh[v].push_back(u);
    }

    void printGraph() {
      static int vert = 0;

      if (vert >= this->vertices)
        return;

      int size = gh[vert].size();
      cout << "\n";
      cout << vert;
      for (int i =0; i < size; ++i)
        cout << " -> " << gh[vert][i] << " " ;
      cout << "\n";

      vert++;
      printGraph();
    }

    void graphBfs(int s, int e) {

      vector<int>visited(this->vertices);
      queue<pair<int, T>>q;

      q.push(make_pair(0, s));
      visited[s] = 1;
      while (!q.empty()) {
        auto i = gh[q.front().second];
        auto tmp = q.front();
        q.pop();

        /*
         * UNCOMMENT below code to find path to node e using bfs
         *

        if (tmp.second == e) {
          cout << "Reached Destination in " << tmp.first << endl;
          break;
        }
        */

        for (int j = 0; j < i.size(); ++j) {
          if (!visited[i[j]]) {
            visited[i[j]] = 1;
            q.push(make_pair(tmp.first+1, i[j]));
          }
        }
      }
    }

    void graphDfs(int s) {

      if (!visitedDfs[s]) {
        cout << " Visited " << s << endl;
        visitedDfs[s] = 1;
        for (int i = 0; i < gh[s].size(); ++i) { 
          if (!visitedDfs[gh[s][i]]) {
            this->edgeTo[gh[s][i]] = s;
            graphDfs(gh[s][i]);
          }
        }
      }
    }

    stack<int> pathTo(int st, int v) {
      stack<int>s;

      if (!this->visitedDfs[v]) return {};

      for (int x = v; x != st; x = this->edgeTo[x])
        s.push(x);
      s.push(st);

      cout << "Path is: "; 
      while (!s.empty()) {
        cout << s.top() << "-> ";
        s.pop();
      }
      cout << endl;

      return s;
    }
};

int main() {
  int vert = 0;
  int edges = 0;

  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> vert; 
  GraphAL<int> gh(vert);

  cin >> edges;
  for (int i =0; i < edges; ++i) {
    int s, e;
    cin >> s >> e;
    gh.addEdge(s, e);
  }
  /*
  try {
    gh.addEdge(0, 1);
    gh.addEdge(1, 2);
    gh.addEdge(3, 4);
    gh.addEdge(4, 0);
    gh.addEdge(3, 1);
  }
  catch(string e) {
    cout << "throws exception " << e << endl;
  }
  */

  int s, e;
  gh.printGraph();
  cin >> s >> e;

  //gh.graphBfs(s, e);
  gh.graphDfs(s);
  for (int i = 0; i < gh.edgeTo.size(); ++i)
    cout << "Reached " << i << " from " <<  gh.edgeTo[i] << endl;

  gh.pathTo(s, e);

  return 0;
}
