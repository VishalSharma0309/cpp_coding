/*
A graph is a set of vertices and a set of edges connecting them.
Unlike a tree, a graph does not have a well-defined structure.

A tree is a special case of graphs. 

* Adjacent vertices: two vertices with a direct edge b/w them
* Degree of a vertex: no. of edges going through a vertex
* Path: The collection of edges that can be taken to reach from one vertex to the other
* Connected Graph: If there is a direct or indirect path b/w every pair of nodes
* Connected Components: The components of a graph which are connected in its own but not with other components
* Tree: is a connected graph which has no cycles

For n vertices:
* min. no. of edges in a connected graph: n-1 -> O(n)
* max. no. of egdes in a completely connected graph: nC2 = n(n-1)/2 -> O(n^2)

*/

/*
Implementation thoughts
(i) Edge List: A list of pairs of vetices directly connected
    Not a very optimal way. Each query can take upto O(n^2)

(ii) Adjacent List: Each vertex will have a list of vertices to which it is directly connected
    Each query can take upto O(n) or less. This is space efficient.

(iii) Adjacency  Matrix:
    To check if i is connected with j, go to (i,j)th term of the matrix and check if its true or not
    Very time efficient, but is space costly (space O(n^2))

*/

#include <bits/stdc++.h>
using namespace std;


/* print the graph
sv is the starting vertex
This functions moves in the direction it sets on till it can't possibly continue in that dirn
This approach is called DFS or Depth-First Search
*/
/*
Ex: 0->(1,2) 1->(0,3,4) 2->(0,6) 3->(1,5) 4->(1,5) 5->(3,4,6) 6->(2,5)
DFS order: 0 1 3 5 4 6 2
*/
void print_dfs (int ** edges, int n, int sv, bool * visited){
    cout << sv << endl;
    visited[sv] = true;
    for (int i=0 ; i<n ; i++){
        if (i == sv){
            continue;
        }
        
        if (edges[sv][i] == 1){
            if (visited[i]){
                continue;
            }            
            print_dfs (edges, n, i, visited);
        }
    }
}

/*
BFS: Bredth-First Search
Ex: 0->(1,2) 1->(0,3,4) 2->(0,6) 3->(1,5) 4->(1,5) 5->(3,4,6) 6->(2,5)
BFS Order: 0 1 2 3 4 6 5
*/
void print_bfs (int ** edges, int n, bool * visited, int sv=0){

    queue <int> pending_nodes;
    pending_nodes.push(sv);
    visited[sv] = true;

    while (pending_nodes.size() != 0){
        
        int top_node = pending_nodes.front();
        pending_nodes.pop();
        cout << top_node << " ";
        for (int i=0 ; i<n ; ++i){
            if (i == top_node){
                continue;
            }
            if (edges[top_node][i] == 1 && visited[i] == false){
                pending_nodes.push(i);
                visited[i] = true;
            }
        }
    }

}



int main(){
    // no. of vertices & edges
    int n;
    int e;
    cin >> n >> e;

    int ** edges = new int*[n];
    for (int i=0 ; i<n ; ++i){
        edges[i] = new int [n];

        for (int j=0 ; j<n ; ++j){
            edges[i][j] = 0;
        }
    }
    for (int i=0 ; i<e ; ++i){
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool * visited = new bool[n];
    for (int i=0 ; i<n ; ++i){
        visited[i] = false;
    }
    
    print_bfs (edges, n, visited);


    // deallocating memory
    delete [] visited;
    for (int i=0 ; i<n ; ++i){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}