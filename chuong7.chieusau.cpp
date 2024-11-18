#include <iostream>
#include <vector>
using namespace std;

// H�m d? quy DFS d? duy?t d? th?
void DFSUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    // ��nh d?u d?nh hi?n t?i d� du?c tham
    visited[v] = true;
    cout << v << " "; // In d?nh hi?n t?i

    // Duy?t t?t c? c�c d?nh k? c?a d?nh v
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFSUtil(u, adj, visited); // �? quy DFS cho d?nh k? chua tham
        }
    }
}

// H�m DFS cho to�n b? d? th?
void DFS(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false); // M?ng d�nh d?u c�c d?nh d� tham

    cout << "DFS: ";
    // G?i DFS cho t?t c? c�c d?nh chua tham
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
    cout << endl;
}

// H�m th�m c?nh v�o d? th?
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Th�m v v�o danh s�ch k? c?a u
    adj[v].push_back(u); // Th�m u v�o danh s�ch k? c?a v (n?u l� d? th? v� hu?ng)
}

// H�m in danh s�ch k?
void printGraph(const vector<vector<int>>& adj) {
    cout << "Danh sach ke cua do thi:" << endl;
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E; // S? d?nh v� s? c?nh
    cout << "Nhap so dinh va so canh: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); // Danh s�ch k? d? bi?u di?n d? th?

    cout << "Nhap cac canh (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v); // Th�m c?nh v�o d? th?
    }

    printGraph(adj); // In danh s�ch k?

    DFS(adj, V); // G?i h�m DFS d? duy?t d? th?

    return 0;
}
