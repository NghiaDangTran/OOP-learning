#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char str[5][30][100] = {
        {"AB", "Edmonton","Calgary","Medicine Hat"}, {"BC", "zrynotqmfe", "asdbasdg", "aaaaa"}

    }; //5 for read 4 character + null-terminator


    char finalsol[99][80]={"AB",};
    char str1[5][30] = {"102%", "5%", "30%", "00%"};
    qsort(str1, 5, sizeof(*str1), (int (*)(const void *, const void *))strcmp);
    qsort(str[1], 4, sizeof(*str[1]), (int (*)(const void *, const void *))strcmp);

    // qsort(str, 5, sizeof(*str), (int (*)(const void *, const void *))strcmp);

    puts("");
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", str1[i]);
    }
    char test[] = "Lab";
    return 0;
}
