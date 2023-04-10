#include <stdio.h>

#define NUM_PATHWAYS ((int) (sizeof(road_networks) / sizeof(road_networks[0])))

int main(){

    int i, j, point;
    
    int road_networks[][9] ={
        {1, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1}
    };

    printf("-------ADJACENCY MATRIX-------\n");
    printf("   A  B  C  D  E  F  G  H  I\n");

    for (i = 0; i < NUM_PATHWAYS; i++){
        printf("%c ", 'A' + i);   
            for (j = 0; j < NUM_PATHWAYS; j++){
                if (i == 2 || i == 3 || j == 2 || j == 3){
                    printf("[%d]", road_networks[i][j]);
                }else{
                    printf("%2d ", road_networks[i][j]);
                }
            }
        printf("\n");
    }
    printf("\n");

    printf("Which point are you located? 0-A, 1-B, 2-C, 3-D, 4-E, 5-F, 6-G, 7-H, 8-I: ");
    scanf("%d", &point);
    printf("\nAt point: %c", 'A' + point);
    
    switch (point){
        case 0: case 1: case 5:
            printf("\nPoint: C arrived to charging station");
            break;
        case 4: case 6:
            printf("\nPoint: D arrived to charging station");
            break;
        case 2: 
            printf("\nPoint: C is a charging station");
            break;
        case 3: 
            printf("\nPoint: D is a charging station");
            break;
        default:
            printf("\nPoint: No charging station reached");
            break;
    }

    return 0;
}