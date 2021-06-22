#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, lis;
vector<int> input;
int lis_array[100010], before[100010], after[100010], position_counter[100010], tmp[100010];
bool is_valid[100010];

void lis_before(int &temp, int &index) {
    int lis_index = lower_bound(lis_array, lis_array + lis, temp) - lis_array;
    lis_array[lis_index] = temp;
    if (lis == lis_index) lis++;
    before[index] = lis_index;
}

void lis_after() {
    tmp[lis - 1] = input[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        int lis_index = upper_bound(tmp, tmp + lis, input[i]) - tmp - 1;
        after[i] = lis - lis_index - 1;
        tmp[lis_index] = input[i];
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        input.push_back(temp);
        lis_before(temp, i);
    }
    lis_after();
    for (int i = 0; i < n; ++i) {
        if (after[i] + before[i] == lis - 1) {
            is_valid[i] = true;
            position_counter[before[i]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (is_valid[i]) {
            if (position_counter[before[i]] == 1) {
                cout << 3;
            } else cout << 2;
        } else cout << 1;
    }
    cout << endl;
}