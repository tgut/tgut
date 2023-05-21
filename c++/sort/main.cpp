/*
 * @Author: tgut 
 * @Date: 2023-05-11 17:50:48 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-15 18:25:55
 */
#include<iostream>
#include<vector>
#include "radix_sort.h"

int main(){
    vector<int> data = {1,34,5,7,8,9,32,11,1};
    cout<<"inital sequence is:"<<endl;
    for(int ele:data){
        cout<<ele<<" ";
    }
    cout<<endl;
    radix_sort(data,0,data.size()-1);
    cout<<"sort sequence is:"<<endl;
    for(int ele:data){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
