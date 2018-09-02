#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> adjs[MAXN];
int a[MAXN];

bool visited[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adjs[u - 1].push_back(v - 1);
    adjs[v - 1].push_back(u - 1);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }

  queue<unordered_set<int>> q;
  q.push({0});
  memset(visited, false, sizeof(visited));
  visited[0] = true;

  int aIdx = 0;
  bool failed = false;
  while(!q.empty()) {
    unordered_set<int>& currSet = q.front();
    int currA = a[aIdx++];

    if(!currSet.count(currA)) {
      failed = true;
      break;
    }
    currSet.erase(currA);
    if(currSet.empty()) {
      q.pop();
    }
    unordered_set<int> newSet;
    for(int adj : adjs[currA]) {
      if(visited[adj]) continue;
      visited[adj] = true;
      newSet.insert(adj);
    }
    if(!newSet.empty()) {
      q.push(newSet);
    }
  }
  printf("%s\n", failed ? "No" : "Yes");
  return 0;
}
