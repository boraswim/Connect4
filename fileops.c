#include <stdio.h>

int main(){
    FILE *tablePtr;
    FILE *turnPtr;
    int table[9][9];
    int mode;
    turnPtr=fopen("turn.txt","w");

    printf("New game or continue (0=New, Else=Continue):");
    scanf("%d",&mode);

    if(mode==0){
        tablePtr=fopen("table.txt","w");
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                fprintf(tablePtr,"%1d ",0);
            }
                fprintf(tablePtr,"%s","\n");
        }
        fclose(tablePtr);
    }

        tablePtr=fopen("table.txt","r");
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                fscanf(tablePtr,"%1d",&table[i][j]);
            }
        }
        fclose(tablePtr);
    
    
    
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    tablePtr=fopen("table.txt","w");
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                fprintf(tablePtr,"%1d ",table[i][j]);
            }
                fprintf(tablePtr,"%s","\n");
        }
        fclose(tablePtr);

    return 0;
}