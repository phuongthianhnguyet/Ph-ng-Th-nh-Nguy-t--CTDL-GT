#include <iostream>
#include <vector>
using namespace std;

// Hàm d? quy DFS d? duy?t d? th?
void DFSUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    // Ðánh d?u d?nh hi?n t?i dã du?c tham
    visited[v] = true;
    cout << v << " "; // In d?nh hi?n t?i

    // Duy?t t?t c? các d?nh k? c?a d?nh v
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFSUtil(u, adj, visited); // Ð? quy DFS cho d?nh k? chua tham
        }
    }
}

// Hàm DFS cho toàn b? d? th?
void DFS(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false); // M?ng dánh d?u các d?nh dã tham

    cout << "DFS: ";
    // G?i DFS cho t?t c? các d?nh chua tham
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
    cout << endl;
}

// Hàm thêm c?nh vào d? th?
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Thêm v vào danh sách k? c?a u
    adj[v].push_back(u); // Thêm u vào danh sách k? c?a v (n?u là d? th? vô hu?ng)
}

// Hàm in danh sách k?
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
    int V, E; // S? d?nh và s? c?nh
    cout << "Nhap so dinh va so canh: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); // Danh sách k? d? bi?u di?n d? th?

    cout << "Nhap cac canh (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v); // Thêm c?nh vào d? th?
    }

    printGraph(adj); // In danh sách k?

    DFS(adj, V); // G?i hàm DFS d? duy?t d? th?

    return 0;
}
