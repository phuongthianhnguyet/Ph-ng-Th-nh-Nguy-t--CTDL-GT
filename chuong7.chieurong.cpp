#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Hàm BFS d? duy?t d? th?
void BFS(vector<vector<int>>& adj, int start) {
    int V = adj.size(); // S? d?nh trong d? th?
    vector<bool> visited(V, false); // M?ng dánh d?u các d?nh dã tham
    queue<int> q; // Hàng d?i d? luu các d?nh c?n tham

    // Kh?i d?ng BFS t? d?nh start
    visited[start] = true;
    q.push(start);

    cout << "BFS tu dinh " << start << ": ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " "; // In d?nh hi?n t?i

        // Duy?t t?t c? các d?nh k? v?i d?nh hi?n t?i
        for (int u : adj[v]) {
            if (!visited[u]) { // N?u d?nh chua du?c tham
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

// Hàm thêm c?nh vào d? th?
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Thêm d?nh v vào danh sách k? c?a u
    adj[v].push_back(u); // Thêm d?nh u vào danh sách k? c?a v (n?u là d? th? vô hu?ng)
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

    int start;
    cout << "Nhap dinh bat dau duyet BFS: ";
    cin >> start;

    BFS(adj, start); // G?i hàm BFS

    return 0;
}
