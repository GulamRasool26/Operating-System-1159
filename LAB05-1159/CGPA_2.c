 #include <stdio.h>
 #include <pthread.h>
 
 typedef struct {
                int id;
                float cgpa;
                char* message;
                } ThreadData;
 void* printData(void* arg) {
                ThreadData* data = (ThreadData*)arg;
                printf("Thread %d with CGPA %f says: %s\n", data->id,data->cgpa, data->message);
                return NULL;
                            }
 int main() {
        pthread_t t1, t2;
        ThreadData data1 = {1159,3.55, "My name is Gulam Rasool"};
        pthread_create(&t1, NULL, printData, &data1);
        pthread_join(t1, NULL);
        printf("All threads done.\n");
        return 0;
        }
 
