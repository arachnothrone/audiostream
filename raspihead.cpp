// Bluetooth headphones emulator
// (c) arachnothrone
// c++ -o raspihead raspihead.cpp -std=c++11 -lpthread

#include <iostream>
#include <string>
#include <vector>
//#include <pthread.h>
#include <unistd.h>         // sleep, usleep
#include <thread>

// // function for thread 1
// void *func1(void *arg){
//     int i;
//     for (i = 0; i < 6; i++){
//         std::cout << "\nFUNC 1: " << i << " sec\n";
//         sleep(2);
//     }
//     pthread_exit(NULL);
//     //return NULL;
// }

// // function for thread 2
// void *func2(void *arg){
//     int i;
//     for (i = 0; i < 10; i++){
//         std::cout << "\nFUNC 2: " << i << " SEC\n";
//         usleep(900000);
//     }
//     pthread_exit(NULL);
// }

// // function for thread 3
// void *func3(void *arg){
//     int i;
//     for (i = 0; i < 140; i++){
//         std::cout << "." << std::flush;
//         usleep(100000);
//     }
//     return NULL;
//     //pthread_exit(NULL);
// }

// int main(int argc, char const *argv[])
// {
//     int err;

//     // thread ID (unsigned long int)
//     pthread_t ntid1;
//     pthread_t ntid2;
//     pthread_t ntid3;

//     // start thread 1, pthread_create() returns 0 if thread started successfully
//     err = pthread_create(&ntid1, NULL, func1, NULL);
//     if (err != 0)
//         std::cout << "Failed to start thread1, " << ntid1 << " error=" << err << '\n';
//     usleep(200000);
//     err = pthread_create(&ntid2, NULL, func2, NULL);
//     if (err != 0)
//         std::cout << "Failed to start thread2, " << ntid2 << " error=" << err << '\n';

//     pthread_create(&ntid3, NULL, func3, NULL);

//     // joind threads to main, wait them to finish
//     pthread_join(ntid1, NULL);
//     pthread_join(ntid2, NULL);
//     pthread_join(ntid3, NULL);
    
//     std::cout << "\n -- END -- \n";
//     return 0;
// }

// ---------------------------------------------------------------------
void func1(){
    //std::cout << "FUNC 1" << std::endl;
    int i;
    for (i = 0; i < 6; i++){
        std::cout << "\nFUNC 1: " << i << " sec\n";
        sleep(2);
    }
}

void func2(){
    int i;
    for (i = 0; i < 10; i++){
        usleep(100000);
        std::cout << "\nFUNC 2: " << i << " SEC\n";
        usleep(850000);
    }
}

void func3(){
    int i;
    for (i = 0; i < 140; i++){
        std::cout << "." << std::flush;
        usleep(100000);
    }
}

int main()
{
    // threads start
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);

    // join threads with the main
    t1.join();
    t2.join();
    t3.join();

    std::cout << "\n -- END -- \n";
    return 0;
}
