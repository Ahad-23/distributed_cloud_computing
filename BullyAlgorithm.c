// types of messages exchanged when election is conducted?
// election message -> process to start the election
// reply message ->
// coordinatior message
// first display what is a coordinator
// enter  who is nitiating the election process, lets say 4, 4 sends election message to 5,4 sends election message to 6,4 sends election message to 7
// 5 sends ok to 4, 6 sends ok to 4
// 5 initiates the election, 5 sends message to 6, 5 sends message to 6
// 6 sends ok to 5
// 6 sends message to 7
// no reply
// 6 winner
// 6 sends coordinator message to 1,2,3,4,5,6,7
#include <stdio.h>
int main()
{
    int n, i, j, init, coordinator = -1;
    printf("Enter no. of processes");
    scanf("%d", &n);
    int processes[n];
    for (i = 0; i < n; i++)
        processes[i]=i+1;
    printf("Process %d is the coordinator",processes[n-1]);
    printf("Process %d fails",processes[n-1]);
    printf("Enter initiator process ID ");
    scanf("%d", &init);
    
    printf("\nElection initiated by process %d\n", init);
    // Initiator sends election messages to all higher-ID processes
    for (i = 0; i < n; i++)
    {
        if (processes[i] > init)
        {
            printf("Message sent from %d to %d.\n", init, processes[i]);
        }
    }
    // All higher processes send acknowledgments back to init
    for (i = 0; i < n; i++)
    {
        if (processes[i] > init)
        {
            printf("Acknowledged the message sent from %d to %d.\n",
                   processes[i], init);
        }
    }
    // Each higher process continues election
    for (i = 0; i < n; i++)
    {
        if (processes[i] > init)
        {
            // First print all election messages from processes[i] to its higher processes
            for (j = 0; j < n; j++)
            {
                if (processes[j] > processes[i])
                {
                    printf("Message sent from %d to %d.\n", processes[i],
                           processes[j]);
                }
            }
            // Then print all acknowledgments from those higher processes back to processes[i]
            for (j = 0; j < n; j++)
            {
                if (processes[j] > processes[i])
                {

                    printf("Acknowledged the message sent from %d to %d.\n",
                           processes[j], processes[i]);
                }
            }
        }
    }
    coordinator = processes[n - 1]; // Highest ID wins
    printf("\nCoordinator: %d  \n", coordinator);
    // Coordinator sends coordinator message to all other processes
    for (i = 0; i < n; i++)
    {
        if (processes[i] != coordinator)
        {
            printf("Coordinator message sent from %d to %d.\n", coordinator,
                   processes[i]);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (processes[i] != coordinator)
        {
            printf("Acknowledgement message sent from %d to %d.\n", processes[i], coordinator);
        }
    }
    return 0;
}