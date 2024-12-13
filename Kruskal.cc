// #include <stdio.h>
#include <iostream>
#include <algorithm>
// #include <cstring>
#include <vector>
#include <chrono>
using namespace std;


// Nombre de vertexs i arestes
int n, m;


vector<int> roots; // Vector que conte l'arrel del node i-essim

// Metode per trobar l'arrel del vertex "x"
int find(int x){
    return (x == roots[x]) ? x : roots[x] = find(roots[x]);
}
// Metode per unir 2 components conexes
void Union(int x, int y){
    roots[find(x)] = find(y);
}
// Metode que determina si 2 vertexs son o no de la mateixa component conexa
bool sameComponent(int x, int y){
    return find(x) == find(y);
}


// Estructura aresta(edge)
struct Edge{
    int u; // Vertex d'origen
    int v; // Vertex de desti
    int weight; // Pes de l'aresta
    Edge(){}
    // Comparador por pes
    // Cambiar el signe a > par obtenir l'arbre d'expansio maxima
    bool operator<( const Edge &e ) const {
        return weight < e.weight;
    }
};

vector<Edge> edges; // Vector que conte les arestes del graf

vector<Edge> MST; // Vector que contindra les arestes de l'arbre d'expansio minima al final de l'execucio


int Kruskal(){
    int u, v, weight; // Aresta actual
    int total_weight = 0; // Pes total del MST
    int num_edges = 0; // Nombre d'arestes afegides al MST

    // Construim el vector roots
    roots.resize(n+1);
    for( int i = 1; i <= n; ++i) roots[i] = i;

    // Ordanem el vector per pes
    sort(edges.begin(), edges.end());

    // Per a cada aresta, fins a trobar l'MST
    for( int i = 0; i < m; ++i){
        // Aresta actual
        u = edges[i].u;
        v = edges[i].v;
        weight = edges[i].weight;

        // Si no formem cap cicle, afegim l'aresta
        if(!sameComponent(u, v)){
            total_weight += weight;
            MST[num_edges] = edges[i];
            num_edges++;
            // Unim les components conexes
            Union(u, v);
        }

        // Quan haguem acabat
        if (n - 1 == num_edges) i = m;
    }

    // Si l'MST trobat no té tots els vértices enviem missatge d'error
    if( n - 1 != num_edges ){
        // cout << "No existeix un MST valid pel graf ingressat, el graf ha de ser conexe." << endl;
        return -1;
    }

    // cout << "L'MST trobat conte les seguents arestes" << endl;
    // for(int i = 0; i < num_edges; ++i)
    //     cout << MST[i].u << " " << MST[i].v << " " << MST[i].weight << endl; // u v pes
    // cout << "El cost minim de l'MST es" << total_weight << endl;
    return total_weight;
}

int main(){
    // cout << endl;
    auto inicio = chrono::high_resolution_clock::now();

    // scanf("%d %d", &n , &m);
    cin >> n >> m;
    edges.resize(m);
    MST.resize(n-1);

    // Llegim el graf, fem un vector amb totes les arestes
    for( int i = 0 ; i < m ; ++i ){
        Edge e;
        scanf("%d %d %d" , &e.u , &e.v , &e.weight);
        edges[i] = e;
    }
    
    int x = Kruskal();

    auto final = chrono::high_resolution_clock::now();
    int resultat = chrono::duration_cast<chrono::microseconds>(final-inicio).count();

    // printf("%d", resultat);
    cout << resultat;
}