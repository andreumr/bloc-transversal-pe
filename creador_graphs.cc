#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <random>
#include <list>
#include <chrono>
using namespace std;

#define MAX_WEIGHT 100
#define MAX_N 500
#define MIN_N 1


int generateRandomNumber(int min, int max) {
    int rd_num = rand();
    rd_num = (rd_num % (max - min + 1)) + min;
    return rd_num;
}


struct Edge {
    int u, v, cost;
    Edge (int a, int b, int c) {u = a; v = b; cost = c;}
    bool operator < (const Edge &p) const {
        if (u == p.u) return v < p.v;
        return u < p.u;
    }
};

vector<Edge> aristas_disponibles;

vector<int> padre;
//Método para encontrar la raiz del vértice actual X
int Find( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}
//Método para unir 2 componentes conexas
void Union( int x , int y ){
    padre[ Find( x ) ] = Find( y );
}
//Método que me determina si 2 vértices estan o no en la misma componente conexa
bool sameComponent( int x , int y ){
    return Find( x ) == Find( y );
}


int main(){
    srand(time(NULL));
    int n, m;
    n = generateRandomNumber(MIN_N, MAX_N);
    m = generateRandomNumber(n-1, n*(n-1)/2);
    // cin >> n >> m;
    set<int> G[n];
    padre.resize(n);
    for (int i = 0; i < n; i++){
        padre[i] = i;
    }
    queue<Edge> pq;

    for(int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            aristas_disponibles.push_back(Edge(i, j, generateRandomNumber(0, MAX_WEIGHT)));
        }
    }

    int max = aristas_disponibles.size()-1;
    for (int i = 0; i < n-1; i++){
        int j = generateRandomNumber(0, max);
        Edge e = aristas_disponibles[j];
        while (sameComponent(e.u, e.v)){
            j--;
            if (j < 0) j = aristas_disponibles.size()-1;
            e = aristas_disponibles[j];
        }
        pq.push(e);
        Union(e.u, e.v);
        aristas_disponibles.erase(aristas_disponibles.begin()+j);
        max--;
    }


    for (int i = n-1; i < m; i++){
        int j = generateRandomNumber(0, max);
        Edge e = aristas_disponibles[j];
        pq.push(e);
        aristas_disponibles.erase(aristas_disponibles.begin()+j);
        max--;
    }

    // Escribim les arestes del graf per la so
    printf("%d %d\n", n, m);
    while(!pq.empty()){
        Edge e = pq.front();
        pq.pop();
        printf("%d %d %d\n", e.u + 1, e.v + 1, e.cost);
    }
}