#include <stdio.h>
 
void substring(char [], int, int);
 int stringLenght(char []);
 #define AGE 10
void append(char [],char);

int compare(char[],char[]);

int main()
{
   char string[1000]="hello", sub[1000];
   int position, length, c = 0;
 char  word[1000] ="hell";
if(c)
{
     printf("Required substring is \"%s\"\n", word);
}
 
   substring(string, 4, 5);
   substring(word, stringLenght(word)-1, stringLenght(word));
 append(word, '1');
   printf("Required substring is \"%s\"\n", word);
 

if(stringLenght(word))
{
    printf("1");
}

   return 0;
}
// C substring function definition
char [] substring(char Str[], int start, int end) {
   int at = 0;
   char copy[1000];
   while (at < end) {
      copy[at] = Str[start+at];
      at++;
   }
   copy[at] = '\0';

   return copy;
}


int stringLenght(char str[])
{
int result=0;

while(str[result]!='\0')
  {
result++;
  }
return result;

}


void append(char str[], char value)
{
str[stringLenght(str)]=value;
str[stringLenght(str)+1]='\0';


}


int compare(char str1[],char str2[])
{
if (stringLenght(str1)!=stringLenght(str2))
return 0;
for(int i=0;i<stringLenght(str1);i++)
{if(str1[i]!=str2[i])
return 0;
}

return 1;
}