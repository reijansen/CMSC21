#include <stdio.h>
#include <math.h>

int main(){
    
    int i;

    for (i = 0; i <= 10; i++)
    {
        printf("2 to the %d is %d. \n", i, (int)pow(2,i));
    }
    
    return 0;
}
