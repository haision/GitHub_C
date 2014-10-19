#include <stdio.h>

int main(int argc, char *argv[])
{

  char day[15] = "abcdefghijklmn";
  char* strTmp = "opqrstuvwxyz";

  printf("&day is       %p\n",&day);
  printf("&day[0] is    %p\n",&day[0]);
  printf("day is        %p\n",day);
  
  printf("\n&strTmp is	%p\n",&strTmp);
  printf("&strTmp[0] is	%p\n",&strTmp[0]);
  printf("strTmp is	%p\n",strTmp);
  
  return 0;
}
