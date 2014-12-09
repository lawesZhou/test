#include <stdio.h>

char * getoneline()
{
 extern char line[];
 char c;
 int pl = 0;
 while(c=getchar())
 {
   if (c == EOF || c == '\n')break;
   line[pl++] = c;
 }
 return line;
}

int main()
{
 char * tline = getoneline();
 printf("%s\n",tline);
 printf("%s\n",getoneline());
 return (0);
}
