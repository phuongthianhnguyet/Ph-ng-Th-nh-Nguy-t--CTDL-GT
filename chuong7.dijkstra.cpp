#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Số lượng đỉnh trong đồ thị

// Hàm tìm đỉnh có khoảng cách nhỏ nhất trong tập các đỉnh chưa được xử lý
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Thuật toán Dijkstra tìm đường đi ngắn nhất từ đỉnh nguồn `src`
void dijkstra(int graph[V][V], int src) {
    int dist[V];       // Mảng lưu khoảng cách ngắn nhất từ `src` đến các đỉnh
    bool sptSet[V];    // Mảng đánh dấu đỉnh đã được xử lý

    // Khởi tạo tất cả khoảng cách là vô hạn và chưa xử lý đỉnh nào
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0; // Khoảng cách từ `src` đến chính nó là 0

    // Tìm đường đi ngắn nhất cho tất cả các đỉnh
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Chọn đỉnh có khoảng cách nhỏ nhất
        sptSet[u] = true;                 // Đánh dấu đỉnh đã xử lý

        // Cập nhật giá trị khoảng cách của các đỉnh kề với đỉnh `u`
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // In khoảng cách ngắn nhất từ đỉnh nguồn `src` đến các đỉnh khác
    cout << "Khoang cach tu dinh " << src << " den cac dinh khac:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Dinh " << i << " : " << dist[i] << endl;
    }
}

int main() {
    // Đồ thị dưới dạng ma trận kề
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 6},
        {1, 2, 0, 0, 1},
        {0, 0, 6, 1, 0}
    };

    int src;
    cout << "Nhap dinh nguon: ";
    cin >> src;

    // Gọi thuật toán Dijkstra
    dijkstra(graph, src);

    return 0;
}
