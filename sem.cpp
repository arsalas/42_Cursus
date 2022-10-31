
#include <iostream>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

using namespace std;

#define SEM_NAME "/sem_name"

sem_t *pSem;

void * testThread (void *ptr)
{
    sem_wait(pSem);
    printf("###read or write the data area###\n");
    sleep(20);
    sem_close(pSem);
}

int main()
{
    pSem = sem_open(SEM_NAME, O_CREAT, 0666, 5);

    pthread_t pid;
    int semVal;

    for (int i = 0; i < 7; ++i)
    {
        pthread_create(&pid, NULL, testThread, NULL);

        sleep(1);

       sem_getvalue(pSem, &semVal);
       cout<<"semaphore value:"<<semVal<<endl;
    }
    sem_close(pSem);
    sem_unlink(SEM_NAME);
}

