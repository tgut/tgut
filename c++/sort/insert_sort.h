/*
 * @Author: tgut 
 * @Date: 2023-05-15 13:01:22 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 13:03:51
 * @ref https://www.geeksforgeeks.org/insertion-sort/#
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insert_sort(vector<int> &data, int begin, int end)
{
    int len = data.size();
    for (int i = 0; i < len - 1; i++)
    {
        if (data[i] > data[i + 1])
        {
            swap(data[i], data[i + 1]);
            int pos = i;
            // cout<<" ,move";
            while (pos > 0 && data[pos] < data[pos - 1])
            {   
                // cout<<" "<<data[pos-1];
                swap(data[pos], data[pos - 1]);
                pos--;
            }
            // cout<<endl;
        }
    }
}