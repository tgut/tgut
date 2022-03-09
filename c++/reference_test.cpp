#include<iostream>
using namespace std;
void reset(int &tmp){
    tmp = 0;
}
int main(){
    int test = 128;
    cout<<"before reset test is:"<<test<<endl;
    reset(test);
    cout<<"before reset test is:"<<test<<endl;
}