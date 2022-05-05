/*两个线程，a output 随即数，b print and delete

queue<int>;
thread_a(){
    //1.
            ger_random()-->judge if ele is zero, then choose to fill array;    
}

thread_b(){
    2.
            b get,reset to 0
}

main{

thread.creat(thread_a);
thread.joint();
}

1.ota client
2*/

#include<pthread.h>
#include<iostream>
#include<semaphore.h>//1.to print sequence
#include <condition_variable>//1
using namespace std;
#define LOOP 3
int number = 0;
mutex mtx;//1
condition_variable cvar;//1
bool isTrue = true;
void *generate_random(void* args){
    int i = 0;
    while(i < LOOP){
        unique_lock<std::mutex>ulk(mtx);
        cvar.wait(ulk, [] {return isTrue == true; });

        number = random();
        cout<<(i++)%10<<"  :"<<number<<endl;

        isTrue = !isTrue;
        ulk.unlock();
        cvar.notify_all();
    }
}

void *print_random(void* args){
    int j = 0;
    while(j < LOOP){
        unique_lock<std::mutex>ulk(mtx);
        cvar.wait(ulk, [] {return isTrue == false; });

        cout<<"pr :"<<number<<endl;
        j++;

        isTrue = !isTrue;
        ulk.unlock();
        cvar.notify_all();
    }
}
int main(){
    pthread_t pid_1;
    pthread_t pid_2;

    pthread_create(&pid_1,NULL,generate_random,NULL);
    pthread_create(&pid_2,NULL,print_random,NULL);
    pthread_join(pid_1);
    pthread_join(pid_2);
    pthread_exit(NULL);
    return 0;
}
///https://www.runoob.com/cplusplus/cpp-multithreading.html 多线程基础
//https://blog.csdn.net/noBle_Ora/article/details/60464695 顺序打印abc
//