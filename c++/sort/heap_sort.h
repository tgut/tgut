/*
 * @Author: tgut
 * @Date: 2023-05-15 11:50:16
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 12:28:52
 */

#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &data, int N, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;
    if (l < N && data[largest] < data[l])
    {
        largest = l;
    }

    if (r < N && data[largest] < data[r])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(data[i], data[largest]);
        heapify(data, N, largest);
    }
}
// this is unstable sort.
// to keep interface unified here we pass three parameters,the begin/end is unused.
void heap_sort(vector<int> &data, int begin, int end)
{
    int len = data.size();
    for (int i = len / 2 - 1; i >= 0; i--)//i should be include 0;
    {
        heapify(data, len, i);
    }

    // begin to sort
    for (int i = len; i > 0; i--)
    {
        // cout<<data[0]<<" "<<endl;
        swap(data[0], data[i - 1]);

        heapify(data, i - 1, 0);
    }
}