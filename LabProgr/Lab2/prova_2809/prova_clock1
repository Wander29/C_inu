//Import
 #define _XOPEN_SOURCE 500
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <time.h>
 #include <sys/time.h>


 int main(int argc, char *argv[])
 {
     struct timespec ts;
     int ret;
     while(1)
     {
         ret = clock_gettime (CLOCK_MONOTONIC, &ts);
         if (ret)
         {
             perror ("clock_gettime");
             return;
         }
         ts.tv_nsec += 20000; //goto sleep for 20000 n
         printf("Print before sleep tid%ld %ld\n",ts.tv_sec,ts.tv_nsec );
        // printf("going to sleep tid%d\n",turn );
         ret = clock_nanosleep (CLOCK_MONOTONIC, TIMER_ABSTIME,&ts, NULL);

     }
 }
