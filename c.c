#include <stdio.h>

int main() {

    int right_neighbors[10];
    int left_neighbors[10];
    int connection_matrix[10][2];
    int adjacency_matrix[10][10];
    int degree[10];
    int degree_count[10] = {0};

    // Filling the right neighbors
    for (int i = 0; i < 9; i++) {
        right_neighbors[i] = i + 1;
    }
    // The last right
// Filling the left neighbors
for (int i = 0; i < 10; i++) {
    left_neighbors[i] = i - 1;
}
// The first left neighbor is the last element of the list
left_neighbors[0] = 9;

// Creating the connection matrix
for (int i = 0; i < 10; i++) {
    connection_matrix[i][0] = left_neighbors[i];
    connection_matrix[i][1] = right_neighbors[i];
}

// Printing the connection matrix
printf("Connection Matrix:\n");
for (int i = 0; i < 10; i++) {
    printf(" %d %d\n", connection_matrix[i][0], connection_matrix[i][1]);
}

// Creating the adjacency matrix
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        adjacency_matrix[i][j] = 0; // Initially setting all values to 0
    }
}

for (int i = 0; i < 10; i++) {
    adjacency_matrix[i][connection_matrix[i][0]] = 1;
    adjacency_matrix[i][connection_matrix[i][1]] = 1;
}

// Printing the adjacency matrix
printf("\nAdjacency Matrix:\n");
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        printf("%d ", adjacency_matrix[i][j]);
    }
    printf("\n");
}

// Summing the rows of the adjacency matrix and filling the degree vector
for (int i = 0; i < 10; i++) {
    int sum = 0;
    for (int j = 0; j < 10; j++) {
        sum += adjacency_matrix[i][j];
    }
    degree[i] = sum;
}

// Printing the degree vector
printf("\nDegree Vector:\n");
for (int i = 0; i < 10; i++) {
    printf("%d ", degree[i]);
}
printf("\n");

// Counting occurrences of each degree value and storing in degree_count
for(int i = 0; i < 10; i++){
    degree_count[degree[i]] = degree_count[degree[i]] + 1;
}

// Printing the counts
for(int i = 0; i < 10; i++){
   printf("%d, %d \n", i, degree_count[i]);
}

return 0;
