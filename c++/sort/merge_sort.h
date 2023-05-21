/*
 * @Author: tgut
 * @Date: 2023-05-15 10:39:12
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 11:54:50
 * refer link:https://www.geeksforgeeks.org/merge-sort/
 */
#include <vector>
#include <algorithm>
using namespace std;

//this is stable sort.
void merge(vector<int> &data, int begin, int mid, int end)
{
    vector<int> tmp(end - begin + 1, 0);
    int m = 0, i = begin, j = mid + 1;
    for (; i <= mid && j <= end;)
    {
        if (data[i] < data[j])
        {
            tmp[m] = data[i];
            i++;
        }
        else
        {
            tmp[m] = data[j];
            j++;
        }
        m++;
    }
    if (i > mid)
    {
        for (; j <= end; j++)
        {
            tmp[m] = data[j];
            m++;
        }
    }

    if (j > end)
    {
        for (; i <= mid; i++)
        {
            tmp[m] = data[i];
            m++;
        }
    }

    for (int n = 0; n < m; n++)
    {
        data[begin + n] = tmp[n];
    }
}

void merge_sort(vector<int> &data, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = begin + (end - begin) / 2;
    merge_sort(data, begin, mid);
    merge_sort(data, mid + 1, end);

    merge(data, begin, mid, end);
}