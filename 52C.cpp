#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#define inf 0x3fffffff;

using namespace std;

int n, m;
long long input[200020];
long long arr[200020 * 4];
long long lazy[200020 * 4];

int rmq_init(int left, int right, int node) {
    if (left == right) return arr[node] = input[left];
    int mid = (left + right) / 2;
    int left_min = rmq_init(left, mid, node * 2);
    int right_min = rmq_init(mid + 1, right, node * 2 + 1);
    return arr[node] = min(left_min, right_min);
}

void update(int left, int right, int value, int node, int node_left, int node_right) {
    if (lazy[node] != 0) {
        arr[node] += lazy[node];
        if (node_left != node_right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (node_left > node_right || node_left > right || node_right < left) return;
    if (left <= node_left && right >= node_right) {
        arr[node] += value;
        if (node_left != node_right) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    int mid = (node_left + node_right) / 2;
    update(left, right, value, node * 2, node_left, mid);
    update(left, right, value, node * 2 + 1, mid + 1, node_right);
    arr[node] = min(arr[node * 2], arr[node * 2 + 1]);
}

long long query(int left, int right, int node, int node_left, int node_right) {
    if (lazy[node] != 0) {
        arr[node] += lazy[node];
        if (node_left != node_right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (node_left > node_right || node_left > right || node_right < left) return inf;
    if (left <= node_left && right >= node_right) return arr[node];
    int mid = (node_left + node_right) / 2;
    long long left_min = query(left, right, node * 2, node_left, mid);
    long long right_min = query(left, right, node * 2 + 1, mid + 1, node_right);
    return min(left_min, right_min);
}

void inc(int l, int r, int &value) {
    if (l > r) {
        update(l, n, value, 1, 1, n);
        update(1, r, value, 1, 1, n);
    } else update(l, r, value, 1, 1, n);
}

long long rmq(int l, int r) {
    if (l > r) {
        long long left_min = query(1, r, 1, 1, n);
        long long right_min = query(l, n, 1, 1, n);
        return min(left_min, right_min);
    }
    return query(l, r, 1, 1, n);
}

void operation() {
    for (int i = 0; i < m; ++i) {
        vector<int> command;
        int number = 0;
        string temp;
        getline(cin, temp);
        stringstream stream(temp);
        while (stream >> number)
            command.push_back(number);
        if (command.size() == 2) {
            cout << rmq(command[0]+1, command[1]+1) << endl;
        } else if (command.size() == 3) {
            inc(command[0]+1, command[1]+1, command[2]);
        }

    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        input[i] = temp;
    }
    cin >> m;
    string buffer_flush;
    getline(cin, buffer_flush);
    rmq_init(0, n - 1, 1);
    operation();
}