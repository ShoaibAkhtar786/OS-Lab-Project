#include<stdio.h>
#include<pthread.h>
int global[2];

void *add_thread(void *s)
{
    int *s_array = s;

    int a,b;
    a=s_array[0];
    b=s_array[1];

    printf("Sum of the two numbers using thread = %d\n",a+b);
}

int main() 
{
    printf("Enter the  First number: ");
    scanf("%d",&global[0]);

    printf("Enter the Second number: ");
    scanf("%d",&global[1]);
    pthread_t tid_add;
    pthread_create(&tid_add,NULL,add_thread,global);
    pthread_join(tid_add,NULL);

    return 0;
}
