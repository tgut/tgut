/*
 * @Author: tgut 
 * @Date: 2023-05-20 16:15:02 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-21 11:46:50
 * @ref:https://www.geeksforgeeks.org/radix-sort/?ref=gcse
 */
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

//cout sort
void cout_sort(vector<int>&data,int pos){
    int len = data.size();
    vector<int> count(10);
    vector<int> result(len);//计数排序后的临时数组
    for(auto ele:data){//统计对应pos上的数字之和
        count[ele/(pos)%10]++;
    }

    for(int i = 1;i<10;i++){//累加count
        count[i]+=count[i-1];
    }

//注意赋值，必须逆序来遍历，这样是稳定排序（todo）。
//todo ref https://www.geeksforgeeks.org/counting-sort/#
    for(int i= len - 1;i >= 0;i--){
    
        result[count[data[i]/(pos)%10] - 1]=data[i];
        count[data[i]/(pos)%10]--;
    }
    // cout<<"position "<< (pos)<<" sort:";
    for(int i=0;i<len;i++){
        // cout<<result[i]<<" ";
        data[i] = result[i];
    }
    cout<<endl;

}

//radix sort
void radix_sort(vector<int>&data,int begin,int end){
    int max_ele = 0;
    for(auto ele:data){
        max_ele = max(max_ele,ele);
    }

    int pos = 1;
    while(max_ele){
        cout_sort(data, pos);
        pos*=10;
        max_ele/=10;
    }
}