/* 
Integrantes: Patricio Canales
             Eleazar Vásquez
             Manuel Jaramillo
 */
#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<long long,long long>>> &g, long long start, vector<long long> &dist,vector<long long> &padres)
  {
  priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> q;
  q.push({0, start}); 
  dist[start] = 0; 
  while (not q.empty())
  { 
    long long priority = q.top().first, u = q.top().second; 
    q.pop(); 
    if (priority != dist[u]) continue; 
    for (pair<long long,long long> p : g[u]) { 
      int v = p.first, w = p.second; 
      if (dist[u] + w < dist[v]) { 
        dist[v] = dist[u] + w; 
        padres[v] = u; 
        q.push({dist[v], v}); 
      }
    } 
  } 
}

long n,m = 100000;
vector<long long> costos (n, 1e12); 
vector<long long> padres (n, -1); 
vector<vector<pair<long long,long long>>> ady(n);
//Rellenar matriz de adyacencia para ambos lados; 
int main(){
  for(int i = 0; i < m; ++i) { 
    long long n1, n2, w; 
    cin >> n1 >> n2 >> w; 
    ady[n1-1].push_back({n2-1,w}); 
    ady[n2-1].push_back({n1-1,w}); 
  }
  dijkstra(ady,0,costos,padres);
  return 0;
}
