#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int instance[5], count, sequence[10], safe, s = 0, j, completed, i;
    int available[5], allocation[10][5];
    int need[10][5], process, P[10], countofr, countofp, running[10];
    int maxDemand[10][5];  
    
    cout << "\n Enter the number of resources (<=5): ";
    cin >> countofr;

    for(int i = 0; i < countofr; i++)
    {
        cout << "\n Enter the max instances of resource R[" << i << "]:";
        cin >> instance[i];
        available[i] = instance[i];
    }

    cout << "\n Enter the number of processes (<=10): ";
    cin >> countofp;
    cout << "\n Enter the allocation matrix \n";

    for(i = 0; i < countofp; i++)
    {
        cout << "FOR THE PROCESS :P[" << i << "]" << endl;
        for(int j = 0; j < countofr; j++)
        {
            cout << "allocation of resource R[" << j << "] is : ";
            cin >> allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }

    cout << "\nEnter the MAX matrix \n\n";

    for(i = 0; i < countofp; i++)
    {
        cout << "FOR THE PROCESS P[" << i << "]" << endl;
        for(int j = 0; j < countofr; j++)
        {
            cout << "max demand of resource R[" << j << "] is : ";
            cin >> maxDemand[i][j];  
        }
    }

    cout << "\n the given data are : \n";

    cout << endl << "\nTotal resources in system: \n\n ";
    for(i = 0; i < countofr; i++){
        cout << "R[" << i << "] ";
    }
    cout << endl;
    for(i = 0; i < countofr; i++){
        cout << "    " << instance[i];
    }

    cout << "\n\n Allocation matrix \n\nt";
    for(j = 0; j < countofr; j++){
        cout << "R[" << j << "] ";
    }
    cout << endl;

    for(i = 0; i < countofp; i++)
    {
        cout << "P[" << i << "] ";
        for(j = 0; j < countofr; j++)
            cout << "    " << allocation[i][j];
        cout << endl;
    }

    cout << "\n\n Max matrix \n\nt";
    for(j = 0; j < countofr; j++)
        cout << "R[" << j << "] ";
    cout << endl;

    for(i = 0; i < countofp; i++){
        cout << "P[" << i << "] ";
        for(j = 0; j < countofr; j++)
            cout << "    " << maxDemand[i][j];  
        cout << endl;
    }

    for(i = 0; i < countofp; i++)
    {
        for(j = 0; j < countofr; j++)
        {
            need[i][j] = maxDemand[i][j] - allocation[i][j];  
        }
    }

    cout << "\n\n NEED matrix \n\nt";
    for(j = 0; j < countofr; j++)
        cout << "R[" << j << "] ";
    cout << endl;

    for(i = 0; i < countofp; i++){
        cout << "P[" << i << "] ";
        for(j = 0; j < countofr; j++)
            cout << "    " << need[i][j];
        cout << endl;
    }

    cout << "\n NOW to check whether above state is safe";
    cout << "\n sequence in which above requests can be fulfilled";
    cout << "\n press any key to continue";
    getch();

    count = countofp;

    for(i = 0; i < countofp; i++){
        running[i] = 1;
    }

    while(count){
        safe = 0; 
        for(i = 0; i < countofp; i++)
        {
            if(running[i]){
                completed = 1;
                for(j = 0; j < countofr; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        completed = 0;
                        break;
                    }
                }
                if(completed)
                {
                    running[i] = 0;
                    count--;
                    safe = 1;
                    for(j = 0; j < countofr; j++)
                    {
                        available[j] += allocation[i][j];
                    }
                    sequence[s++] = i;
                    cout << "\n\n Running process P[" << i << "]";
                    cout << endl << "\n\nTotal resources now available:\n\n";
                    for(int k = 0; k < countofr; k++)
                        cout << "R[" << k << "] ";
                    cout << endl;
                    for(int k = 0; k < countofr; k++)
                        cout << "    " << available[k];
                    break;                     
                }
            }
        }
        if(!safe)
            break;
    }

    if(safe)
    {
        cout << "\nThe System is in safe state";
        cout << "\nSafe sequence is:";
        for(i = 0; i < countofp; i++)
        {
            cout << "\t" << "P[" << sequence[i] << "]";
        }
    }
    else
    {
        cout << "\nThe System is in unsafe state";
    }
    getch();
}
