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

# Fractional Knapsack problem using a greedy approach in C

- The greedy approach selects items according to their profit-to-weight ratio: `Ratio=Profit/Weight`
- We select the item with the highest ratio first.

```C
#include<stdio.h>

struct product{
    int profit;
    int weight;
};

// sort the array based on ratio of profit and weight. (descending)
void sort(struct product products[], int n){
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j < n - i - 1; j++){
            float r1 = (float)products[j].profit / products[j].weight;
            float r2 = (float)products[j+1].profit / products[j+1].weight;

            if(r1 < r2){
                struct product temp;
                temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;
            }
        }
    }
}

int main() {
    // max = 16 kg
    // profits(P) = [14, 30, 36, 20, 18]
    // weights(W) = [2, 5, 6, 4, 3] kg
    // W/P (unit) = [7, 6, 6, 5, 6]

    int n, capacity;
    printf("Enter the no. of items: ");
    scanf("%d", &n);
    struct product products[n];

    printf("Enter the profit and weights of the products: ");

    for(int i = 0; i < n; i++){
        scanf("%d%d", &(products[i].profit), &(products[i].weight));
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    sort(products, n);

    // Fractional Knapsack using Greedy Approach
    float totalProfit = 0;

    printf("\nSelected Items:\n");
    printf("Weight\tProfit\tFraction\n");

    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        }

        // If complete item can fit
        if (products[i].weight <= capacity) {
            capacity -= products[i].weight;
            totalProfit += products[i].profit;

            printf("%d\t%d\n",
                   products[i].weight,
                   products[i].profit);
        }

        // If only a fraction can fit
        else {

            float fraction = (float) capacity / products[i].weight;
            totalProfit += products[i].profit * fraction;

            printf("%d\t%d\t%.2f\n",
                   products[i].weight,
                   products[i].profit,
                   fraction);

            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);
    
    return 0;
}

```

# 0/1 Knapsack using Recursion, Brute Force and Structure in C

We need to select items such that:
- The total weight does not exceed the capacity.
- The total profit is maximum.
- Each item is either selected completely (1) or rejected (0).
- Items cannot be divided into fractions.

```C
#include <stdio.h>

struct Item {
    int weight;
    int profit;
};

// Recursive Brute Force function
int knapsack(struct Item items[], int n, int capacity) {

    // Base case
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If current item is heavier than capacity
    if (items[n - 1].weight > capacity) {
        return knapsack(items, n - 1, capacity);
    }

    // Include or exclude the current item
    int include = items[n - 1].profit + knapsack(items, n - 1, capacity - items[n - 1].weight);
    int exclude = knapsack(items, n - 1, capacity);

    // Return maximum profit
    return (include > exclude) ? include : exclude;
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("\nEnter weight and profit of each item:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);

        scanf("%d %d",
              &items[i].weight,
              &items[i].profit);
    }

    int maximumProfit = knapsack(items, n, capacity);

    printf("\nMaximum Profit = %d\n", maximumProfit);

    return 0;
}

```










