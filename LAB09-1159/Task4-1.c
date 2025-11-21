 #include <stdio.h>
 #include <pthread.h>
 #include <semaphore.h>
 #include <unistd.h>

 sem_t resource_semaphore;
 int counter=0;
 void* decreement(void* arg) {
 int thread_id = *(int*)arg;
// printf("Thread %d: Waiting for resource...\n", thread_id);
//  sem_wait(&resource_semaphore); // Wait: decrement counter
 printf("Thread %d: Acquired resource!\n", thread_id);
//  sleep(2);
for (int i=0;i<100000;i++){ counter--;} // Use resource
 // Use resource
 printf("Thread %d: Releasing resource...\n", thread_id);
 sem_post(&resource_semaphore); // Signal: increment counter
 return NULL;
 }
  void* increement(void* arg) {
 int thread_id = *(int*)arg;
// printf("Thread %d: Waiting for resource...\n", thread_id);
//  sem_wait(&resource_semaphore); // Wait: decrement counter
 printf("Thread %d: Acquired resource!\n", thread_id);
//  sleep(2);
for (int i=0;i<100000;i++) {counter++; }// Use resource
 printf("Thread %d: Releasing resource...\n", thread_id);
 sem_post(&resource_semaphore); // Signal: increment counter
 return NULL;
 }
 int main() {
 sem_init(&resource_semaphore, 0, 1); 
 pthread_t t1,t2;
 int id1=1,id2=2;
 pthread_create(&t1, NULL, increement,&id1);
 pthread_create(&t2, NULL, decreement,&id2);  

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 printf("Counter: %d\n", counter);
 


 sem_destroy(&resource_semaphore);
 return 0;
 }