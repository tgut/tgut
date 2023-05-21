/*
 * @Author: tgut 
 * @Date: 2023-05-15 14:42:14 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 14:48:43
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &data,int begin ,int end){
    int len = data.size();
    for(int i =0;i<len;i++){
        for(int j = i+1;j<len;j++){
            if(data[i] > data[j]){
                swap(data[i],data[j]);
            }
        }
    }
}