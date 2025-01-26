// sudooko game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sudo(int arrr[2][2]);
int main()
{
    int difficulty,i,j;
    printf("Choose the difficulty of the game : \n1 : easy\n2 : Medium\n3 : Hard \n");
    scanf("%d",&difficulty);
    srand(time(0)); 
    if(difficulty==1)
    {
        int arr1[2][2],arr2[2][2],arr3[2][2],arr4[2][2],arr5[2][2];
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
        sudo(arr1);
        sudo(arr2);
        sudo(arr3);
        sudo(arr4);
            }
        }
    }
}
void sudo(int arrr[2][2]) {
    int used[4] = {0,0,0,0}; // Track used numbers (1 to 6)
    int i, j, num;
    // Seed the random number generator
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            do {
                num = (rand() % 4) + 1; // Generate a number between 1 and 6
            } while (used[num - 1]!=0); // Ensure the number is not already used
            arrr[i][j] = num;      // Assign the unique number to the grid
            used[num - 1] = 1;     // Mark the number as used
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",arrr[i][j]);
        }
        printf("\n");
    }
}
