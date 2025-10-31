// Write a C program that uses threads to perform operations on shared variables:
// 1.  Create two global variables:
//   initialized to 0
//   initialized to 0
// 2.  Create 3 threads:
//     Thread 1: Adds all of the numbers between 1 to 100 to 100 times
//    Thread 2: Adds all of the numbers between 101 to 200 to 100 times
//    Thread 3: Adds all of the numbers between 201 to 300 to 100 times
// 3.  Use mutex to protect access to both shared variables
// 4.  Each thread prints when it starts and finishes
// 5.  Main thread prints final results:
//   Total sum (should be 45150, which is sum of 1 to 300)   Total count (should be 300)

#include<stdio.h>
#include<pthread.h>

int sum = 0;//global variable for sum
int count = 0;//global variable for count

pthread_mutex_t mutex;//Declaring Mutex for Synchronization

void* thread_func(void* arg)//Thread Function
{   
    pthread_mutex_lock(&mutex);//Locking Mutex
    int tid = *(int*)arg;
    printf("Thread %d is starting.......\n",tid);
    int limit = (tid *100) + 1;//finding the Limit of Loop
    
    for(int i=(limit - 100); i < limit;i++)//finding Sum
    {
        //updating Values
        sum += i;
        count ++;
    }
   
    printf("Thread %d is Ending......\n",tid);
     pthread_mutex_unlock(&mutex);
    
}
int main()
{   
    pthread_mutex_init(&mutex,NULL);//initializing Mutex
    pthread_t thread[3]; //initializing Thread
    int threads[3];

    printf("Main Thread Starting.........\n");
    //Creating Threads
    for (int i =0;i<3;i++)
    {
        threads[i] = i+1;
        pthread_create(&thread[i],NULL,thread_func,&threads[i]);
    }
    //Joining thread to make Main wait for threads
    for (int i =0;i<3;i++)
    {
        pthread_join(thread[i],NULL);
    }
    //displaying Output
    printf("Total Sum: %d and the count is : %d\n",sum,count);
    
    printf("Main Thread Ending.........\n");


}
