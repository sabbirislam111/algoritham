// Bellman-Ford

// input -> A weighted graph & a src node (with no negative cycles)
// output -> shortest destance for src node to all other nodes


// - create a distance array "d" with all values infinity O(n)
// - d[src] = 0

// for i = 1 to n-1    O(n)
//   for all edge e(u, v, w): O(n * m)
    //  if d[u] + w < d[v]
         // d[v] = d[u] + w

// -print the distance array "d"


// O(n) + (1) + (n * m)
// O(n * m)
// O(|E| * |V|)
// O(n ^ 3)

