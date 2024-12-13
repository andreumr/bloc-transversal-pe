// #include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
// #include <cstring>
#include <chrono>
using namespace std;


// Estructura aresta(edge)
struct Edge {
   int u, v, weight;
   Edge (int a, int b, int c) {u = a; v = b; weight = c;}
   bool operator < (const Edge &p) const {
      return weight > p.weight; // Min-heap per la priority_queue
   }
};

vector<bool> visited; // Vertexs visitats
vector<vector<int>> G; // Llista d'adgessencies
vector<vector<int>> weights; // Llista de pesos (organitzada igual que G)
vector<Edge> MST; // Aquest vector contindra les arestes de l'arbre d'expancio minima


int prims_mst(int n, int m, int k) {
   priority_queue<Edge> pq;
   visited[k] = true;

   // Afegim les arestes del node inicial k a la priority_queue
   for (int i = 0; i < G[k].size(); ++i) {
      int v = G[k][i];
      int w = weights[k][i];
      pq.push(Edge(k, v, w));
   }

   int total_weight = 0; // Pes total
   int total_edges = 0; // Arestes afegides a l'MST

   // Mentre quedin arestes per tractar i s'hagin tractar menys de n-1 arestes
   while (!pq.empty() and total_edges != n - 1) {
      Edge a = pq.top();
      pq.pop();
      int u = a.u, v = a.v, w = a.weight; // Aresta actual

      // Processar l'aresta només si el node final no està visitat
      if (!visited[v]) {
         visited[v] = true;
         total_weight += w;
         MST.push_back(a);
         total_edges++;

         // Afegim les arestes adjacents al nou node visitat a pq
         u = v;
         for (int i = 0; i < G[u].size(); i++) {
            v = G[u][i];
            w = weights[u][i];
            if (!visited[v]) pq.push(Edge(u, v, w));
         }
      }
   }

   // Comprovem si el graf és connex
   for (int i = 1; i <= n; i++) {
      if (!visited[i]) return -1; // Si algun node no està visitat, MST no és possible
   }

   return total_weight;
}

int main() {
   auto inicio = chrono::high_resolution_clock::now();
   int n, m;

   // scanf("%d %d" , &n , &m);
   cin >> n >> m;

   weights.resize(n+1);
   G.resize(n+1);
   visited.resize(n+1, false);
   
   // Llegir cada aresta del graf
   for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d" , &u , &v , &w);
      G[u].push_back(v);
      G[v].push_back(u);
      weights[u].push_back(w);
      weights[v].push_back(w);
   }

   // // Calculem l'MST
   int x = prims_mst(n, m, 1);

   // if (x == -1) cout << "No existeix un MST valid pel graf ingressat, el graf ha de ser conexe." << endl;
   // else {
   //    // for( int i = 0 ; i < MST.size() ; ++i )
   //    //    cout << MST[i].u << " " << MST[i].v << " " << MST[i].weight << endl; // u v pes
   //    cout << "El cost minim de l'MST es" << total_weight << endl;
   // }

   auto final = chrono::high_resolution_clock::now();
   int resultat = chrono::duration_cast<chrono::microseconds>(final-inicio).count();
   // printf(",%d,%d,%d", resultat, n, m);
   cout << "," << resultat << "," << n << "," << m << endl;
}