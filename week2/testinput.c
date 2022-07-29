#include <stdio.h>

int main(void)
{
    float f1,f2,f3;

    while (1)
    {
        printf("Please enter three numbers.\n");
        printf("\tFirst number please.\n");
        if (scanf("%f", &f1) != 1)
            break;
        printf("\tSecond number please.\n");
        if (scanf("%f", &f2) != 1)
            break;
        printf("\tThird number please.\n");
        if (scanf("%f", &f3) != 1)
            break;

        printf("Your sum     is %f\n", f1+f2+f3);
        printf("Your average is %f\n", (f1+f2+f3)/3);
    }

}