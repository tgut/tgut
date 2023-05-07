#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> threeSum(vector<int> &num)
    {
        // write code here

        if (num.size() == 0)
        {
            return {{}};
        }
        int len = num.size() - 1;
        set<vector<int>> result;
        sort(num.begin(), num.end());
        // for(auto e:num){
        //     cout<<e<<" ";
        // }
        // cout<<endl;
        

        // cout<<"here2"<<endl;

        for (int m = 0; m < len; m++)
        {
            for (int n = len; n > m; n--)
            {
                int data = -(num[m] + num[n]);
                if (num[n] < data)
                {
                    continue;
                }
                else
                {
                   for(int j = m+1;j < n;j++)
                    if (num[j] == data)
                    {
                        result.insert({num[m], num[j] ,num[n]});
                        // cout<<"example:"<< num[m] <<" " <<num[j]<<" "<<num[n]<<endl;
                    }
                }
            }
        }
        vector<vector<int>> result_f;
        for(auto e:result){
            result_f.push_back(e);
        }

        return result_f;
    }
};

int main()
{
    vector<int> data = {0,0,0};
    Solution* test = new Solution();
    // cout<<"here1"<<endl;
    vector<vector<int>> result = test->threeSum(data);
    for(auto e:result){
        cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
    }
}