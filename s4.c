#include<stdio.h>
int main()
 {
   FILE *fp;
   char ch;
   int num=5; //to read last 5 characters from the file
   long length;
   
   fp = fopen("test.txt", "r"); //file name is test.txt
   if (fp == NULL) {
      puts("cannot open this file");
      exit(1);
   }
 
   fseek(fp, 0, SEEK_END); 
   length = ftell(fp);
   fseek(fp, (length - num), SEEK_SET);
 
   do {
      ch = fgetc(fp);
      putchar(ch);
   } while (ch != EOF);
 
   fclose(fp);
   return(0);
}
