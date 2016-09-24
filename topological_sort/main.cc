#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

namespace {

typedef map<char, vector<char>> AdjList;

void DFS(char v, const AdjList& E, vector<char>* sorted) {
  map<char, bool> visited;
  stack<char> stk;
  stk.push(v);
  visited[v] = true;
  while (!stk.empty()) {
    char c = stk.top();
    bool found = false;
    if (E.find(c) != E.end()) {
      for (char adj : E.at(c)) {
        if (!visited[adj]) {
          stk.push(adj);
          visited[adj] = true;
          found = true;
          break;
        }
      }
    }
    if (!found) {
      stk.pop();
      sorted->push_back(c);
    }
  }
}

vector<char> Sort(const set<char>& V, const AdjList& E) {
  set<char> _V = V;
  AdjList _E;
  for (const pair<char, vector<char>> ei : E) {
    for (char c : ei.second) {
      _E[c].push_back(ei.first);
    }
    _V.erase(_V.find(ei.first));
  }
  vector<char> sorted;
  for (const char vi : _V) {
    DFS(vi, _E, &sorted);
  }
  return sorted;
}

}  // namespace

int main() {
  set<char> V{'a', 'b', 'c', 'd', 'e', 'x'};
  AdjList E;
  E['a'] = {'b'};
  E['b'] = {'d'};
  E['c'] = {'d'};
  E['d'] = {'e'};
  for (char c : Sort(V, E)) {
    cout << c << endl;
  }
  return 0;
}
