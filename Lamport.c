#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int clock[n][12];
    for (i = 0; i < n; i++){
        printf("Enter clock rate for process P%d ",i);
        scanf("%d", &clock[i][0]);
        clock[i][1]=0;
        for (j = 2; j <= 11; j++){
            clock[i][j]=clock[i][j-1]+clock[i][0];
        }
    }
    printf("\n\nClock data:\n");
    printf("P_ID\tClk_Rate\n");
    for (i = 0; i < n; i++){
        printf("P%d\t",i);
        for (j = 0; j <= 11; j++){
            printf("%d\t",clock[i][j]);
        }
        printf("\n");
    }
    while(1)
    {
        printf("\n\n");
        int sender,receiver,sender_time,receiver_time;
        printf("Enter sender process P");
        scanf("%d",&sender);
        printf("Enter sender time ");
        scanf("%d",&sender_time);
        printf("Enter receiver process P");
        scanf("%d",&receiver);
        printf("Enter receiver time ");
        scanf("%d",&receiver_time);
        int sender_valid=0, receiver_valid=0;
        for (i=0;i<=11;i++){
            if (clock[sender][i]==sender_time) sender_valid=1;
            if (clock[receiver][i]==receiver_time) receiver_valid=1;
        }

        if (!sender_valid || !receiver_valid){
            printf("\nError: Invalid time entered, Skipping message.\n");
        }
        else if (receiver_time<=sender_time){
            printf("\nClock adjustment needed at process P%d\n",receiver);
            for (i = 2; i <=11; i++){
                if (clock[receiver][i]==receiver_time){
                    clock[receiver][i]=sender_time+1;
                }
                else if(clock[receiver][i]>receiver_time){
                    clock[receiver][i]=clock[receiver][i-1]+clock[receiver][0];
                }
            }
            printf("\nAdjusted Clock:\n");
        }
        else{
            printf("\nNo Adjustment Needed\n");
        }

        printf("P_ID\tClk_Rate\n");
        for (i = 0; i < n; i++){
            printf("P%d\t", i);
            for (j = 0; j <= 11; j++){
                printf("%d\t", clock[i][j]);
            }
            printf("\n");
        }
        printf("\nPress Ctrl+C to stop\n");
    }
    return 0;
}
