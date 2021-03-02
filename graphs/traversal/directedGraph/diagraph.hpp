/**
 *      file    :  diagraph.hpp 
 *      author  :  techiedheeraj
 *      created :  2021 Feb 28 22:53:30 
 *      lastMod :  Sun Feb 28 22:53:30 2021 
 **/

namespace diagraph { 
  class Diagraph {
    private:
      int vertices;
      std::vector<std::vector<int>>gh;
      std::vector<int> visited;

    public:
      Diagraph() : Diagraph(5) {}
      Diagraph(int vert) : vertices{vert} {
        gh.resize(this->vertices);
        visited.resize(this->vertices, 0);
      }

      void addEdge(int v, int e) {
        gh[v].push_back(e);
      }

      void printGraph() {
        printGraph(0, this->gh);
      }

      std::vector<std::vector<int>> getGraph() {
        return this->gh;
      }

      void printGraph(int vert, const std::vector<std::vector<int>>& gh) {

        if (vert >= this->vertices) 
          return;

        std::cout << vert << "->";
        std::string res = "";
        for (int i =0; i < gh[vert].size(); ++i)
          std::cout << gh[vert][i] << (res = (gh[vert].size()-i == 1) ? "" : "->");
        std::cout << "\n";
        printGraph(vert+1, gh);
      }

      void bfs(int s) {
        std::vector<std::vector<int>>tmp;
        bfs(s, tmp);
      }

      void bfs(int s, std::vector<std::vector<int>>& gr, bool rev=false) {
        std::queue<int>q;
        std::fill(visited.begin(), visited.end(), 0);

        q.push(s);
        visited[s] = 1;
        while(!q.empty()) {
          auto v = q.front(); q.pop();
          for (int i = 0; i < gh[v].size(); ++i) {
            if (rev) { 
              if (std::find(gr[gh[v][i]].begin(), gr[gh[v][i]].end(), v) == gr[gh[v][i]].end())
                gr[gh[v][i]].push_back(v);
            }
            if (!visited[gh[v][i]]) {
              visited[gh[v][i]] = 1;
              q.push(gh[v][i]);
            }
          }
        }
      }

      void dfs(int s) {
        dfs(s, this->gh);
      }

      void dfs(int s, std::vector<std::vector<int>>& gr) {
        dfs(s, gr, true);
      }

      void dfs(int s, std::vector<std::vector<int>>& gr, bool clear) {

        if (clear) std::fill(visited.begin(), visited.end(), 0);
        if (!visited[s]) {
          visited[s] = 1;
          std::cout << " visited " << s << std::endl;

          for (int i=0; i < gr[s].size(); ++i) {
            dfs(gr[s][i], gr, false);
          }
        }
      }

      std::vector<std::vector<int>> reverse() {
        std::vector<std::vector<int>> revGraph(this->vertices);

        for (int i =0; i < this->vertices; ++i) {
          if (!this->visited[i])
            bfs(i, revGraph, true);
        }

        return revGraph;
      }
  };
}
