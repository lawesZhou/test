#include <stdio.h>
#include <malloc.h>

int main()
{
  int c;
  int blanksCnt = 0,tabCnt = 0,nlineCnt = 0 ;
  char * output =(char*)malloc(1000);
  int pout = 0;
  
  while((c= getchar()) != 'e' )
  {
//     printf("%c",c);
     if(c == '\n')
	{
         *(output+pout++) = '\\';
         *(output+pout++) = 'n';
         nlineCnt ++;
         continue;
        }
     else if(c == '\t')
	{
         *(output+pout++) = '\\';
         *(output+pout++) = 't';
         tabCnt ++;
  	 continue;
	}
     else if(c == ' ')
	{
         blanksCnt ++;
	}
     if(pout != 0 && c == ' ' && output[pout-1] == ' ' )
        continue;
     output[pout++] = c;       
  }
  printf("----------blanksCnt=%d,tabCnt=%d,nlineCnt=%d\n",blanksCnt,tabCnt,nlineCnt); 
  printf("%s\n",output);
  free(output);
  return(0);
}
