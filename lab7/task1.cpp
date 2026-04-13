#include <stdio.h>
#include <iostream>

   #define V 4 
   int numbers[V];

using namespace std;


void init(int matrix[][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            matrix[i][j] = 0;
}

void add(int matrix[][V], int src, int dest) {
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

void print(int matrix[][V]) {
    printf("Adjacency Matrix:\n");
    cout<<"  ";
    for (int e = 0 ; e<V ; e++)
    {
        cout <<numbers[e]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < V; i++) {
        cout<<numbers[i]<<" ";

        for (int j = 0; j < V; j++) {
            
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];
    init(adjMatrix);

    for(int i=0;i<V;i++) {
        cout<<"insert the number "<<i<<" = ";
        cin>>numbers[i];
    }

    char q;

    for (int i=0;i<V;i++)
    {
        int f,h;
        if(q=='y') break;
        cout<<"enter first vertex = ";
        cin>>f;
        cout<<"enter SECOND vertex = ";
        cin>>h;

        add(adjMatrix,f,h);
    }

    
    print(adjMatrix);
    return 0;
}















