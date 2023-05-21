/*
 * @Author: tgut 
 * @Date: 2023-05-21 11:45:42 
 * @Last Modified by: tgut
 * @Last Modified time: 2023-05-21 11:46:15
 * @ref https://www.geeksforgeeks.org/counting-sort/#
 */
//not test,just ref geeksforgeeks
void bucketSort(float arr[], int n)
{
      
    // 1) Create n empty buckets
    vector<float> b[n];
  
    // 2) Put array elements 
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
  
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
  
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}