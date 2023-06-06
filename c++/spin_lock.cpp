#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class SpinLock {
  std::atomic_bool locked = false;

public:
  void lock() {
    while (locked.exchange(true)) {
    }
  }

  void unlock() {
    locked = false;
  }
};

int main() {
  SpinLock lock;

  // Create two threads.
  std::thread thread1([&]() {
    // Try to acquire the lock.
    lock.lock();

    // Do something that needs to be protected by the lock.
    std::cout << "Thread 1 acquired the lock." << std::endl;

    // Release the lock.
    lock.unlock();
  });

  std::thread thread2([&]() {
    // Try to acquire the lock.
    lock.lock();

    // Do something that needs to be protected by the lock.
    std::cout << "Thread 2 acquired the lock." << std::endl;

    // Release the lock.
    lock.unlock();
  });

  // Wait for the threads to finish.
  thread1.join();
  thread2.join();

  return 0;
}
