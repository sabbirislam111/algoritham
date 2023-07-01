// Bellman-Ford

// input -> A weighted graph & a src node (with no negative cycles)
// output -> shortest destance for src node to all other nodes


// - create a distance array "d" with all values infinity O(n)
// - d[src] = 0

// - negative_cycle = false

// for i = 1 to n:
//   for all edge e(u, v, w):
    //  if d[u] + w < d[v]:
         // d[v] = d[u] + w
         // if i == n:
         //  negative_cycle = true


// - print weighted negative cycle exista
// -print the distance array "d"



