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

    GraphAL(int vert) {
      //gh = new vector<T>gh[vert];
      gh.resize(vert);
      this->vertices = vert;
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

      static vector<int>visited(this->vertices);

      if (!visited[s]) {
        cout << " Visited " << s << endl;
        visited[s] = 1;
        for (int i = 0; i < gh[s].size(); ++i) { 
          if (!visited[gh[s][i]])
            graphDfs(gh[s][i]);
        }
      }
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

  return 0;
}

  
