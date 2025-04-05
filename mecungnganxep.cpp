#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Point {
    int x, y;
};
bool isValid(int x, int y, int N, int M, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return x >= 0 && y >= 0 && x < N && y < M && maze[x][y] == 0 && !visited[x][y];
}
bool dfs(int N, int M, vector<vector<int>>& maze, Point start, Point end, vector<vector<bool>>& visited, vector<Point>& path) {
    stack<Point> s;
    s.push(start);
    visited[start.x][start.y] = true;
    while (!s.empty()) {
        Point curr = s.top();
        s.pop();
        path.push_back(curr);
        if (curr.x == end.x && curr.y == end.y) {
            return true;
        }
        for (auto dir : {Point{0, 1}, Point{1, 0}, Point{0, -1}, Point{-1, 0}}) {
            int newX = curr.x + dir.x;
            int newY = curr.y + dir.y;
            if (isValid(newX, newY, N, M, maze, visited)) {
                visited[newX][newY] = true;
                s.push(Point{newX, newY});
            }
        }
    }
    return false;
}
int main() {
    int N, M;
    cout << "Enter maze dimensions (N M): ";
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M));
    cout << "Enter maze (0 for open, 1 for blocked):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> maze[i][j];
        }
    }  
    Point start, end;
    cout << "Enter start (x0 y0) and end (x1 y1): ";
    cin >> start.x >> start.y >> end.x >> end.y;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<Point> path;
    if (dfs(N, M, maze, start, end, visited, path)) {
        cout << "Path found:" << endl;
        for (const auto& p : path) {
            cout << "(" << p.x << ", " << p.y << ")" << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }
    return 0;
}
