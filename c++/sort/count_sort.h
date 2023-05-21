/*
 * @Author: tgut 
 * @Date: 2023-05-15 13:01:22 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 18:26:33
 * @ref chatgpt
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void count_sort(vector<int> &data, int begin, int end)
{   int max_num = 0;
//find the largest number
    for(int ele:data){
        max_num = (max_num>=ele?max_num:ele);
    }
//using array to count the data
    vector<int> arr(max_num +1,0);

    for(int ele:data){
        arr[ele]++;
    }
    int index =0;
    for(int i = 1;i<= max_num;i++){
        while(arr[i] > 0){
            data[index++] = i;
            arr[i]--;
        }
    }
}