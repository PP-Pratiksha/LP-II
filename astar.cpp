#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<limits.h>

using namespace std;

struct Node {
    Node* parent;
    int matrix[3][3];
    int x, y;
    int cost, level;
};

class Comp {
public:
    bool operator()(const Node* left, const Node* right) const {
        return (left->cost + left->level) > (right->cost + right->level);
    }
};

class AStar {
public:
    void aStar(int initial[3][3], int goal[3][3], int x, int y) {
        priority_queue<Node*, vector<Node*>, Comp> pq;

        Node* root = newNode(initial, x, y, x, y, 0, nullptr);
        root->cost = calculateCost(initial, goal);
        pq.push(root);
        bool first = true;

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};

        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            if (first) {
                printMatrix(node->matrix);
                printValues(node->level, node->cost);
                first = false;
            } else {
                cout << "Selected Optimal State : " << endl;
                printMatrix(node->matrix);
                printValues(node->level, node->cost);
            }

            if (node->cost == 0) {
                cout << endl;
                cout << "FINAL OPTIMAL PATH TO THE GOAL STATE" << endl;
                printPath(node);
                return;
            }

            int possible = 0;
            for (int i = 0; i < 4; i++) {
                if (isValid(node->x + delRow[i], node->y + delCol[i])) {
                    possible += 1;
                }
            }

            cout << "Total moves possible: " << possible << endl;

            for (int i = 0; i < 4; i++) {
                if (isValid(node->x + delRow[i], node->y + delCol[i])) {
                    Node* child = newNode(node->matrix, node->x, node->y, node->x + delRow[i],
                            node->y + delCol[i], node->level + 1, node);

                    child->cost = calculateCost(child->matrix, goal);
                    pq.push(child);

                    printMatrix(child->matrix);
                    printValues(child->level, child->cost);
                    cout << endl;
                }
            }
        }
    }

    Node* newNode(int initial[3][3], int x1, int y1, int x2, int y2, int level, Node* parent) {
        Node* node = new Node();
        node->parent = parent;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                node->matrix[i][j] = initial[i][j];
            }
        }

        int temp = node->matrix[x1][y1];
        node->matrix[x1][y1] = node->matrix[x2][y2];
        node->matrix[x2][y2] = temp;

        node->cost = INT_MIN;
        node->level = level;

        node->x = x2;
        node->y = y2;

        return node;
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < 3 && y >= 0 && y < 3;
    }

    int calculateCost(int initial[3][3], int goal[3][3]) {
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (initial[i][j] != 0 && initial[i][j] != goal[i][j]) {
                    ans += 1;
                }
            }
        }

        return ans;
    }

    void printPath(Node* root) {
        if (root == nullptr) {
            return;
        }
        printPath(root->parent);
        printMatrix(root->matrix);
        printValues(root->level, root->cost);
    }

    void printMatrix(int initial[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << initial[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printValues(int level, int cost) {
        cout << "g(n) " << level << " | " << "h(n) " << cost << " | " << "f(n) " << (level + cost) << endl;
        cout << endl;
    }
};

int main() {
    int initial[3][3];
    int goal[3][3];

    cout << "Enter the initial state (3x3 matrix):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> initial[i][j];
        }
    }

    cout << "Enter the goal state (3x3 matrix):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> goal[i][j];
        }
    }

    int startX, startY;
    cout << "Enter the x and y coordinates of the empty tile (0-indexed):" << endl;
    cin >> startX >> startY;

    AStar obj;
    cout << "INITIAL PATH OF THE STATE" << endl;
    obj.aStar(initial, goal, startX, startY);

    return 0;
}
