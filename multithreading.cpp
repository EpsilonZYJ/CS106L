#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

using std::cout;    using std::endl;
using std::string;  using std::vector;

const size_t kNumThreads = 10;
std::mutex mtx;
void greet(int id){
    std::lock_guard<std::mutex> lg(mtx);
//    mtx.lock();
//    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Hello there! My name is " << id << endl;
//    mtx.unlock();
}

void f(){
    std::atomic_int x = 0, y = 0;
    y = std::atomic_fetch_add(&x, y);
}

int main(){
    cout << "Greeting from my threads..." << endl;

//    std::thread thread1(greet, 1);
//    std::thread thread2(greet, 2);
//
//    thread1.join();
//    thread2.join();
    vector<std::thread> threads;
    for(size_t i = 0; i < kNumThreads; i++){
        threads.push_back(std::thread(greet, i));
    }

    for(auto& t: threads){
        t.join();
    }

    cout << "All greeting done ..." << endl;
    return 0;
}