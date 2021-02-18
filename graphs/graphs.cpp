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
    Each query can take upto O(n) or less

(iii) Adjacency  Matrix:
    To check if i is connected with j, go to (i,j)th term of the matrix and check if its true or not
    Very time efficient, but is space costly (space O(n^2))

*/