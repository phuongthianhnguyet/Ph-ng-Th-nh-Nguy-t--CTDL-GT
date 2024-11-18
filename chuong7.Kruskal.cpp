#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc để biểu diễn một cạnh trong đồ thị
struct Edge {
    int u, v, weight;
};

// Hàm so sánh để sắp xếp các cạnh theo trọng số tăng dần
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Hàm tìm gốc của tập hợp chứa đỉnh `v` (tìm đại diện)
int findParent(int v, vector<int>& parent) {
    if (v != parent[v]) {
        parent[v] = findParent(parent[v], parent); // Tối ưu hóa bằng kỹ thuật nén đường
    }
    return parent[v];
}

// Hàm hợp nhất hai tập hợp chứa `u` và `v`
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Thuật toán Kruskal
void kruskal(int n, vector<Edge>& edges) {
    // Bước 1: Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compare);

    // Bước 2: Khởi tạo các tập hợp cho các đỉnh
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst; // Lưu các cạnh thuộc cây khung nhỏ nhất
    int mstWeight = 0; // Tổng trọng số của cây khung nhỏ nhất

    // Bước 3: Xét từng cạnh trong danh sách
    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Kiểm tra xem cạnh có tạo thành chu trình hay không
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back(edges[i]); // Thêm cạnh vào cây khung
            mstWeight += weight;     // Cộng trọng số cạnh
            unionSets(u, v, parent, rank); // Hợp nhất hai tập hợp
        }
    }

    // In kết quả
    cout << "Cac canh trong cay khung toi thieu:\n";
    for (size_t i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].weight << endl;
    }
    cout << "Tong trong so cay khung toi thieu: " << mstWeight << endl;
}

int main() {
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Nhap cac canh (u v trong_so):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Gọi thuật toán Kruskal
    kruskal(n, edges);

    return 0;
}
