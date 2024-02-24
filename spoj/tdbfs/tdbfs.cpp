#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>

using namespace std;

/*
Based on Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
*/

int main()
{
  int graphs_count;
  cin >> graphs_count;
  int graph_id = 1;

  while (graphs_count--)
  {
    vector<list<int>> graph;
    int vertices_count;
    cin >> vertices_count;
    graph.resize(vertices_count);

    for (int i = 0; i < vertices_count; i++)
    {
      int neighbours_count, vertex_id;
      cin >> vertex_id >> neighbours_count;
      for (int j = 0; j < neighbours_count; j++)
      {
        int neighbour_id;
        cin >> neighbour_id;
        graph[i].push_back(neighbour_id - 1);
      }
    }

    cout << "graph " << graph_id++ << endl;

    while (true)
    {
      int start_vertex_id, bfs_or_dfs;
      cin >> start_vertex_id >> bfs_or_dfs;

      if (start_vertex_id == 0 && bfs_or_dfs == 0)
      {
        break;
      }

      vector<bool> visited;
      visited.resize(vertices_count, false);
      vector<int> path;

      if (bfs_or_dfs == 0)
      {
        stack<int> s;
        s.push(start_vertex_id - 1);
        while (!s.empty())
        {
          int current_vertex_id = s.top();
          s.pop();
          if (visited[current_vertex_id])
          {
            continue;
          }
          visited[current_vertex_id] = true;
          path.push_back(current_vertex_id + 1);
          for (auto it = graph[current_vertex_id].rbegin(); it != graph[current_vertex_id].rend(); it++)
          {
            s.push(*it);
          }
        }
      }
      else
      {
        queue<int> q;
        q.push(start_vertex_id - 1);
        while (!q.empty())
        {
          int current_vertex_id = q.front();
          q.pop();
          if (visited[current_vertex_id])
          {
            continue;
          }
          visited[current_vertex_id] = true;
          path.push_back(current_vertex_id + 1);
          for (auto neighbour_id : graph[current_vertex_id])
          {
            q.push(neighbour_id);
          }
        }
      }
      for (int vertex_id : path)
      {
        cout << vertex_id << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
