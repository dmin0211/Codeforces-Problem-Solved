#include <iostream>
#include <algorithm>
using namespace std;

int n, q;
int l, r;
int arr[200001];
int index[200001];
long long sum = 0;

int main()
{

    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        index[l - 1] += 1;
        index[r] -= 1;
    }

    for (int i = 1; i < n; i++)
    {
        index[i] += index[i - 1];
    }

    sort(arr, arr + n);
    sort(index, index + n);

    for (int i = 0; i < n; i++)
    {
        sum += (long long)arr[i] * (long long)index[i];
    }

    printf("%I64d\n", sum);

}