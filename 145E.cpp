#include <iostream>
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

string input_str;
int t;
int count4[4000005];
int count7[4000005];
int left_longest[4000005];
int right_longest[4000005];
bool lazy[4000005];

void propagate(int now, int s, int e) {
    if (lazy[now]) {

        if (s != e) {
            lazy[now * 2] = !lazy[now * 2];
            lazy[now * 2 + 1] = !lazy[now * 2 + 1];

            if (lazy[now * 2]) {
                left_longest[now] = max(right_longest[now * 2] + count4[now * 2 + 1], count7[now * 2] + right_longest[now * 2 + 1]);
                right_longest[now] = max(left_longest[now * 2] + count7[now * 2 + 1], count4[now * 2] + left_longest[now * 2 + 1]);
            }
            else {
                left_longest[now] = max(left_longest[now * 2] + count7[now * 2 + 1], count4[now * 2] + left_longest[now * 2 + 1]);
                right_longest[now] = max(right_longest[now * 2 + 1] + count7[now * 2], count4[now * 2 + 1] + right_longest[now * 2]);
            }
        }

        int temp = count4[now];
        count4[now] = count7[now];
        count7[now] = temp;
        lazy[now] = 0;
    }
}

void init(int left, int right, int current) {
    if (left > right) return;
    if (left == right) {
//    cout<<current<<": "<<input_arr[left]<<endl;
        if (input_str[left-1] == '4') {
            count4[current]++;
        } else {
            count7[current]++;
        }
        left_longest[current] = 1;
        right_longest[current] = 1;
        return;
    }
    int mid = (left + right) / 2;
    init(left, mid, current * 2);
    init(mid + 1, right, current * 2 + 1);
    count4[current] += (count4[current * 2] + count4[current * 2 + 1]);
    count7[current] += (count7[current * 2] + count7[current * 2 + 1]);
    left_longest[current] =
            max(left_longest[current * 2] + count7[current * 2 + 1], left_longest[current * 2 + 1] + count4[current * 2]);
    right_longest[current] =
            max(right_longest[current * 2] + count4[current * 2 + 1], right_longest[current * 2 + 1] + count7[current * 2]);
}

void update(int left, int right, int L, int R, int current) {
//  cout<<"current : "<<current<<"\tleft : "<<left<<"\tright : "<<right<<endl;
//  rmq_lazy(current, left, right);
    propagate(current, left, right);
//  cout<<"middle lazy current : "<<current<<"\tcount4 : "<<count4[current]<<"\tcount7 : "<<count7[current]<<"\tleft : "<<left_longest[current]<<"\tright : "<<right_longest[current]<<endl;
    if (left > R || right < L || left > right) return;
    if (left >= L && right <= R) {
        lazy[current] = !lazy[current];
        propagate(current, left, right);
        return;
    }
    if(left==right) return;
    int mid = (left + right) / 2;
    update(left, mid, L, R, current * 2);
    update(mid + 1, right, L, R, current * 2 + 1);

    count4[current] = count4[current * 2] + count4[current * 2 + 1];
    count7[current] = count7[current * 2] + count7[current * 2 + 1];
    left_longest[current] =
            max(left_longest[current * 2] + count7[current * 2 + 1], left_longest[current * 2 + 1] + count4[current * 2]);
    right_longest[current] =
            max(right_longest[current * 2] + count4[current * 2 + 1], right_longest[current * 2 + 1] + count7[current * 2]);
//  cout<<"last current : "<<current<<"\tcount4 : "<<count4[current]<<"\tcount7 : "<<count7[current]<<"\tleft : "<<left_longest[current]<<"\tright : "<<right_longest[current]<<endl;
}

int main() {
    FIO;
    int n;
    cin >> t >> n;
    cin >> input_str;
    init(1, t, 1);
    for (int i = 0; i < n; ++i) {
        cin >> input_str;
        if (input_str == "count") {
            cout << left_longest[1] << endl;
        } else if (input_str == "switch") {
            int left, right;
            cin >> left >> right;
            update(1, t, left, right, 1);
        }
    }
}