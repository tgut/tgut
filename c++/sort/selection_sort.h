/*
 * @Author: tgut 
 * @Date: 2023-05-15 14:41:59 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 14:44:06
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void selection_sort(vector<int> &data,int begin,int end){
    int len= data.size();

    for(int i = 0; i < len - 1;i++){
        int min = i;
        for(int j = i + 1;j < len;j++ ){
            if(data[min] > data[j]){
                min = j;
            }
        }
        if(min != i){
            swap(data[min],data[i]);
        }
    }
}