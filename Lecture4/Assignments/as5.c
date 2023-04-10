#include <stdio.h>

int main(){
    
    int i, j, a, b, c=1, A[6][7]={0};

    do{
        printf("Enter number of days in month:");
        scanf("%d", &i);
    }while(i < 28 || i > 31);

    do{
        printf("Enter the starting day of the week (1=Sun, 7=Sat):");
        scanf("%d", &j);
    } while(j < 1 || j > 7);

    if (j == 1)
    {
        j = 0;
    }
    else
    {
        j = j - 1;
    }

    for (a = 0; a < 6; a++)
    {
        for (b = 0; b < 7; b++)
        {
            if (c==1 && b<j)
            {
                printf("    ");
            }
            else
            {
                if (c<=i)
                {
                    A[a][b] = c;
                    printf("%3d ",c);
                    c++;
                }
                else
                {
                    break;
                }
            }
        }
        if (c>i)
        {
            break;
        }
        printf("\n");
    }
    
    return 0;
}