# Kruskal's Algorithm To find Minimum Spanning Tree (MST) of a graph

```C
  #include <stdio.h>
  
  // Structure to store graph edges
  struct Edge {
      int src, dest, weight;
  };
  
  // Find parent of a vertex
  int find(int parent[], int i) {
      if (parent[i] == i){
          return i;
      }
      return find(parent, parent[i]);
  }
  
  // Combine two sets
  // {1} {2} {3} {4} -> each element is a set
  // unionSet(1,3) -> 1 parent of 3
  void unionSet(int parent[], int x, int y) {
      int rootX = find(parent, x);
      int rootY = find(parent, y);
  
      parent[rootY] = rootX;
  }
  
  // Sort edges by weight (Bubble Sort)
  void sortEdges(struct Edge edges[], int E) {
      struct Edge temp;
  
      for (int i = 0; i < E - 1; i++) {
          for (int j = 0; j < E - i - 1; j++) {
  
              if (edges[j].weight > edges[j + 1].weight) {
                  temp = edges[j];
                  edges[j] = edges[j + 1];
                  edges[j + 1] = temp;
              }
          }
      }
  }
  
  // Kruskal's Algorithm
  void kruskal(struct Edge edges[], int VCount, int ECount) {
  
      int parent[VCount];
      int totalCost = 0;
      int edgeCount = 0;
  
      // Initially, every vertex is its own parent
      for (int i = 0; i < VCount; i++) {
          parent[i] = i;
      }
  
      // Sort edges by increasing weight
      sortEdges(edges, ECount);
  
      printf("\nMinimum Spanning Tree:\n");
      printf("Edge\tCost\n");
  
      // Select minimum cost edges
      for (int i = 0; i < ECount && edgeCount < VCount - 1; i++) {
  
          int u = edges[i].src;
          int v = edges[i].dest;
          
          int rootU = find(parent, u);
          int rootV = find(parent, v);
  
          // Check whether adding edge creates a cycle
          if (rootU != rootV) {
  
              printf("%d - %d\t%d\n",
                     u, v, edges[i].weight);
  
              unionSet(parent, rootU, rootV);
  
              totalCost += edges[i].weight;
              edgeCount++;
          }
      }
  
      if (edgeCount != VCount - 1) {
          printf("Graph is not connected. MST does not exist.\n");
      } else {
          printf("\nTotal Minimum Cost = %d\n", totalCost);
      }
  }
  
  int main() {
      int VCount, ECount;
      printf("Enter number of vertices: ");
      scanf("%d", &VCount);
      printf("Enter number of edges: ");
      scanf("%d", &ECount);
      
      struct Edge edges[ECount];
  
      printf("\nEnter edges (Source Destination Cost):\n");
  
      for (int i = 0; i < ECount; i++) {
          scanf("%d %d %d",
                &edges[i].src,
                &edges[i].dest,
                &edges[i].weight);
      }
  
      kruskal(edges, VCount, ECount);
      return 0;
  }

```
