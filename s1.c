1.	#include <pthread.h>  
2.	    #include<unistd.h>  
3.	    #include <bits/stdc++.h>  
4.	    #include <semaphore.h>  
5.	      
6.	  
7.	    using namespace std;  
8.	    int resources = 6;  
9.	    bool flag;  
10.	      
11.	  
12.	    void * first(void *) {  
13.	      
14.	  
15.	      
16.	  
17.	        while(flag);  
18.	      
19.	  
20.	        /* critical section */  
21.	        cout << endl  
22.	             << ">>> Lock acquired, by First function" << endl  
23.	             << endl;  
24.	        int a;  
25.	        flag = true;  
26.	        a = resources;  
27.	        a = a + 1;  
28.	        sleep(1);  
29.	        resources = a;  
30.	        flag = false;  
31.	        cout << endl  
32.	             << ">>> Lock released, by First function" << endl  
33.	             << endl;  
34.	        printf("The value of resources is %d\n", resources);  
35.	        /* remainder section */  
36.	    }  
37.	    void * second(void *) {  
38.	      
39.	  
40.	        while(flag)  
41.	            ;  
42.	          
43.	        /* critical section */  
44.	        cout << endl  
45.	             << ">>> Lock acquired, by Second function" << endl  
46.	             << endl;  
47.	        int a;  
48.	        flag = true;  
49.	        a = resources;  
50.	        a = a - 1;  
51.	        resources = a;  
52.	        sleep(2);  
53.	        flag = false;  
54.	        cout << endl  
55.	             << ">>> Lock released, by Second function" << endl  
56.	             << endl;  
57.	        printf("The value of resources is %d \n", resources);  
58.	        /* remainder section */  
59.	    }  
60.	    int main() {  
61.	        pthread_t thread1, thread2;  
62.	        flag = false;  
63.	      
