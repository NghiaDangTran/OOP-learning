#include <stdio.h>
 #include <string.h>

void substring(char [], char[], int, int);
 int stringLenght(char []);
 void append(char[],char);
int main()
{
   char string[1000]="hello", sub[1000] , anh='!';
   int position, length, c = 0;
 
 append(string,anh);
 printf("%s",string);
   
   print
 

   return 0;
}
// C substring function definition
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c];
      c++;
   }
   sub[c] = '\0';
}


int stringLenght(char str[])
{
  int result = 0;

  while (str[result] != '\0')
  {
    result++;
  }
  return result;
}

void append( char str[],char value)
{
    str[stringLenght(str)]=value;
     str[stringLenght(str)+1]='\0';
}