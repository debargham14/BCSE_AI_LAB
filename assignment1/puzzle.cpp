/*
    the following code will test the different unirformed search techniques 
    against the classic knights tour problem (Given a source cell check whether
    the knight can reach a particular target cell or not)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int n; //to get the size of the n * n chessboard
//defining the knights move 
vector<pair<int, int>> dir = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, -1}, {-2, 1}, {2, -1}};

void getPathUsingBFS (int start_x, int start_y, int target_x, int target_y) {
    auto canGo = [&] (int x, int y) -> bool {
        return x >=0 && x < n && y >= 0 && y < n;
    };

    if (canGo(target_x, target_y) == false) {
        cout << "Entered target is out of the board\n";
        return;
    }
    vector<vector<bool>> vis (n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push ({start_x, start_y});
    vis[start_x][start_y] = true;
    
    map<pair<int, int>, pair<int, int>> parent;
    parent[{start_x, start_y}] = {-1, -1};
    
    
    
    while (!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        for (auto move : dir) {
            int next_pos_x = curr_pos.first + move.first;
            int next_pos_y = curr_pos.second + move.second;

            if (canGo (next_pos_x, next_pos_y)) {
                if (!vis[next_pos_x][next_pos_y]) {
                    parent[{next_pos_x, next_pos_y}] = {curr_pos.first, curr_pos.second};
                    vis[next_pos_x][next_pos_y] = true;
                    q.push ({next_pos_x, next_pos_y});
                }
            }
        }
    }

    vector<pair<int, int>> path;
    pair<int, int> par = {target_x, target_y};

    if ( ! vis[target_x][target_y]) {
        cout << "Goal Cannot be reached !";
    }
    else {
        while (par.first != -1 && par.second != -1) {
            path.push_back(par);
            par = parent[par];
        }  
        reverse(path.begin(), path.end());
        cout << "------------path-------------\n";
        for (pair<int, int> node : path) {
            cout << "{" << node.first << "," << node.second << "}" << "\n";
        }
    } 
}

//driver code to test the functionality
int main () {
    cout << "Enter the size of the board -> ";
    cin >> n;

    int start_x, start_y, target_x, target_y;
    cout << "Enter the starting cell -> ";
    cin >> start_x >> start_y;

    cout << "Enter the Goal cell -> ";
    cin >> target_x >> target_y;

    getPathUsingBFS (start_x, start_y, target_x, target_y);

    return 0;
}   