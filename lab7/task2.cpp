#include <iostream>
#include <cstring>
using namespace std;

#define V 100

int adj[V][V];
int n;

void DFS(int node, int visited[])
{
    visited[node] = 1;
    cout << node << " ";
    
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

void BFS(int start)
{
    int queue[V];
    int visited[V];
    memset(visited, 0, sizeof(visited));
    
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";
        
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int choice;
    memset(adj, 0, sizeof(adj));
    n = 0;
    
    while (1) {
        cout << "\n1. Init Graph\n2. Add Edge\n3. Show Matrix\n4. DFS\n5. BFS\n6. Check Connected\n7. Test\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Vertices: ";
            cin >> n;
            memset(adj, 0, sizeof(adj));
            cout << "Graph created with " << n << " nodes\n";
        }
        
        else if (choice == 2) {
            if (n == 0) {
                cout << "Init graph first\n";
            } else {
                int u, v;
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                adj[u][v] = 1;
                adj[v][u] = 1;
                cout << "Edge added\n";
            }
        }
        
        else if (choice == 3) {
            if (n == 0) {
                cout << "Graph not initialized\n";
            } else {
                cout << "\nMatrix:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << adj[i][j] << " ";
                    }
                    cout << "\n";
                }
            }
        }
        
        else if (choice == 4) {
            if (n == 0) {
                cout << "Init first\n";
            } else {
                int start;
                cout << "Start node: ";
                cin >> start;
                cout << "DFS: ";
                int visited[V];
                memset(visited, 0, sizeof(visited));
                DFS(start, visited);
                cout << "\n";
            }
        }
        
        else if (choice == 5) {
            if (n == 0) {
                cout << "Init first\n";
            } else {
                int start;
                cout << "Start node: ";
                cin >> start;
                cout << "BFS: ";
                BFS(start);
                cout << "\n";
            }
        }
        
        else if (choice == 6) {
            if (n == 0) {
                cout << "Init first\n";
            } else {
                int visited[V];
                memset(visited, 0, sizeof(visited));
                DFS(0, visited);
                
                int connected = 1;
                for (int i = 0; i < n; i++) {
                    if (!visited[i]) {
                        connected = 0;
                        break;
                    }
                }
                cout << "\n";
                if (connected) {
                    cout << "Connected\n";
                } else {
                    cout << "Not connected\n";
                }
            }
        }
        
        else if (choice == 0) {
            cout << "Exit\n";
            break;
        }
    }
    
    return 0;
}
