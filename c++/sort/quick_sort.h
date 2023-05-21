/*
 * @Author: tgut 
 * @Date: 2023-05-11 17:50:32 
 * @Last Modified by:   tgut 
 * @Last Modified time: 2023-05-11 17:50:32 
 */

#include <vector>
#include <algorithm>
using namespace std;

int tgut_sort(vector<int> &data, int begin, int end)
{

    int i = begin - 1;
    int pivot = data[end];
    for (int j = begin; j < end; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[end]);//pay attention,swap the array instead of the data[i+1] and pivot.
   
    return (i + 1);
}

void quick_sort(vector<int>& data, int begin, int end)
{ //begin is the first element position, end is the last element position.

    if (begin >= end)
    {
        return;
    }
    int mid = tgut_sort(data, begin, end);
    quick_sort(data, begin, mid - 1);
    quick_sort(data, mid + 1, end);
}