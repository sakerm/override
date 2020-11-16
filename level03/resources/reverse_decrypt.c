#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[17] = "Q}|u`sfg~sf{}|a3";
    char tmp[17];

    for (int i = 0; i <= 21; i++)
    {
        for (int j = 0; j < 17; j++)
            tmp[j] = buf[j] ^ i; 
        printf("%s -> %d\n", tmp, 322424845 - i);
    }
    return 0;
}