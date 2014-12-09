#include<stdio.h>

int main()
{
  int c;
 
  c = getchar();
  
  while(c != EOF )
  {
   // printf("%s\n",'*'*10);
    printf("*********************************************\n");
    putchar(c);
    printf(" %c,%d,%d\n",c,c,c*3);
    printf("%d\n",c != EOF);
    c = getchar();
    // printf("%d test getchar() !- EOF %d\n",c,getchar() != EOF);
  }
  return(0);
  
}
