/*
 * @Author: tgut
 * @Date: 2023-05-15 14:50:08
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 17:14:16
 * @ref https://www.geeksforgeeks.org/shellsort/#
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* function to sort arr using shellSort */
void shell_sort(vector<int> &data, int begin, int end)
{
    int len = data.size();
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < gap; i++)//sort each gap's subarray
        {
            for (int j = i; j < len; j += gap)//begin insert sort
            {
                int tmp = data[j];
                int m = j;

                while (m > i && data[m - gap] > tmp)
                {
                    data[m] = data[m - gap];
                    m -= gap;
                }
                
                data[m] = tmp;
            }
        }
    }
}
