#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// H�m BFS d? duy?t d? th?
void BFS(vector<vector<int>>& adj, int start) {
    int V = adj.size(); // S? d?nh trong d? th?
    vector<bool> visited(V, false); // M?ng d�nh d?u c�c d?nh d� tham
    queue<int> q; // H�ng d?i d? luu c�c d?nh c?n tham

    // Kh?i d?ng BFS t? d?nh start
    visited[start] = true;
    q.push(start);

    cout << "BFS tu dinh " << start << ": ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " "; // In d?nh hi?n t?i

        // Duy?t t?t c? c�c d?nh k? v?i d?nh hi?n t?i
        for (int u : adj[v]) {
            if (!visited[u]) { // N?u d?nh chua du?c tham
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

// H�m th�m c?nh v�o d? th?
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Th�m d?nh v v�o danh s�ch k? c?a u
    adj[v].push_back(u); // Th�m d?nh u v�o danh s�ch k? c?a v (n?u l� d? th? v� hu?ng)
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

    int start;
    cout << "Nhap dinh bat dau duyet BFS: ";
    cin >> start;

    BFS(adj, start); // G?i h�m BFS

    return 0;
}
