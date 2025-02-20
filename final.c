#include<stdio.h>
#include<string.h>
//structure
struct Player
{
    //Full Name
    //Age
    //Player Role
    //ODI Match
    //Total Runs
    //Highest Run

    char name[40];
    int age;
    char role[40];
    int odi_match;
    int total_runs;
    int highest_run;
    float avrg;
    float vlp;

};
//array of a structure
struct Player cricketer[11];
int all_players;
//function define
void PrintInformation(int playerIndex);
void PrintInformationAll();
void PrintInformationAllOfname(char name[]);
int MEPindex();
int NCPindex();
int TSPindex();
int HHPindex();
int HRTPindex();
void Allr(char all[]);
int VALUEABLE();

int main()
{
    char name[40];
    char all[40];
    char filename[40];

    FILE *fp;
    int i;
    printf("Please Enter The Input File Name : ");
    gets(filename);
    fp = fopen(filename, "r");
    fscanf(fp, "%d\n", &all_players);

    for(i=0; i<all_players; i++)
    {
        fgets(cricketer[i].name, 40, fp);
         fscanf(fp, "%d\n", &cricketer[i].age);
        fgets(cricketer[i].role, 40, fp);
        fscanf(fp, "%d\n", &cricketer[i].odi_match);
        fscanf(fp, "%d\n", &cricketer[i].total_runs);
        fscanf(fp, "%d\n", &cricketer[i].highest_run);

        cricketer[i].name[strlen(cricketer[i].name)-1] = '\0';
        cricketer[i].role[strlen(cricketer[i].role)-1] = '\0';
    }
    fclose(fp);

    while(1)
    {
        int choice;
        printf("\n1. Print All Players information: ");
        printf("\n2. Show A Particular player information: ");
        printf("\n3. Show the MOST Experienced Player: ");
        printf("\n4. Show the New Commer Player: ");
        printf("\n5. Show the Top Scorer Player: ");
        printf("\n6. Show the Hard Hitter Player: ");
        printf("\n7. Show the Highest Run Taker Player: ");
        printf("\n8. Show the MOST Valuable Player: ");
        printf("\n9. Show the Allrounders: ");
        printf("\n10. Exit/Quit.");
        printf("\nPlease Enter Your Choice : ");

        scanf("%d", &choice);

        if(choice == 1)
        {
            //Print All Players information
            PrintInformationAll();
        }
        else if(choice==2)
        {
            printf("\nPlease Enter the  name : ");
            getchar();
            gets(name);
            PrintInformationAllOfname(name);
        }
        else if(choice==3)
        {
            int n = MEPindex();
            printf("\n");
            puts(cricketer[n].name);
            printf("AGE:%d\n", cricketer[n].age);
        }
        else if(choice==4)
        {
            int idx = NCPindex();
            printf("\n");
            puts(cricketer[idx].name);
            printf("AGE:%d\n", cricketer[idx].age);
        }
        else if(choice==5)
        {
            int idx = TSPindex();
            printf("\n");
            puts(cricketer[idx].name);
            printf("Total Runs:%d\n", cricketer[idx].total_runs);
        }
        else if(choice==6)
        {
            int i=HHPindex();
            printf("\n");
            puts(cricketer[i].name);
            printf("Average : %.3f\n",cricketer[i].avrg);

        }
        else if(choice==7)
        {
            int idx = HRTPindex();
            printf("\n");
            puts(cricketer[idx].name);
            printf("Highest Run:%d\n", cricketer[idx].highest_run);
        }
         else if(choice==8)
        {
            int idx = VALUEABLE();
            printf("\n");
            puts(cricketer[idx].name);
            printf("Value Score:%.3f\n", cricketer[idx].vlp);
        }
        else if(choice==9)
        {
          Allr("Allrounder");
        }
        else if(choice==10)
        {
            break;
        }
    }
    return 0;
}


//user define function
void PrintInformation(int playerIndex)
{
    printf("\n");
    puts(cricketer[playerIndex].name);
    printf("%d\n", cricketer[playerIndex].age);
    puts(cricketer[playerIndex].role);
    printf("%d", cricketer[playerIndex].odi_match);
    printf("\n%d",cricketer[playerIndex].total_runs);
    printf("\n%d\n",cricketer[playerIndex].highest_run);
}
void PrintInformationAll()
{
    int i;
    for(i=0;i<all_players;i++)
    {
        PrintInformation(i);
    }
}
void PrintInformationAllOfname(char name[])
{
    int i;
    for(i=0; i<all_players; i++)
    {
        if(strcmp(cricketer[i].name, name) == 0)
        {
            PrintInformation(i);
        }
    }
}
int MEPindex()
{
    int i;
     int mepindex = 0;
    for(i=0;i<all_players;i++)
    {
        if(cricketer[i].age > cricketer[mepindex].age)
        {
            mepindex = i;
        }
    }

    return mepindex;
}
int NCPindex()
{
    int i;
     int ncpindex = 0;
    for(i=0;i<all_players;i++)
    {
        if(cricketer[i].age < cricketer[ncpindex].age)
        {
            ncpindex = i;
        }
    }

    return ncpindex;
}
int TSPindex()
{
    int i;
     int tspindex = 0;
    for(i=0;i<all_players;i++)
    {
        if(cricketer[i].total_runs > cricketer[tspindex].total_runs)
        {
            tspindex = i;
        }
    }

    return tspindex;
}
int HHPindex()
{
    int i;
    int hhpi=0;
    for(i=0;i<all_players;i++)
    {
        cricketer[i].avrg=(float) cricketer[i].total_runs/cricketer[i].odi_match;
    }
    int hhpindex=0;
    for(i=1;i<all_players;i++)
    {
        if(cricketer[i].avrg > cricketer[hhpindex].avrg)
        {
            hhpindex=i;
        }
    }
    return hhpindex;
}
int HRTPindex()
{
    int i;
     int hrtpindex = 0;
    for(i=1;i<all_players;i++)
    {
        if(cricketer[i].highest_run > cricketer[hrtpindex].highest_run)
        {
            hrtpindex = i;
        }
    }

    return hrtpindex;
}
void Allr(char all[])
{
    int i;
    for(i=0; i<all_players; i++)
    {
        if(strcmp(cricketer[i].role, "Allrounder") == 0)
        {
            PrintInformation(i);
        }
    }
}

int VALUEABLE()
{
    int i;
    for(i=0;i<all_players;i++)
    {
        cricketer[i].vlp=cricketer[i].age+cricketer[i].odi_match+cricketer[i].total_runs+cricketer[i].highest_run+((float)cricketer[i].total_runs/cricketer[i].odi_match)+((float)cricketer[i].highest_run / cricketer[i].age)+(strcmp(cricketer[i].role, "Allrounder") == 0 ? 50 : 0);
    }
    int maxindex=0;
    for(i=1;i<all_players;i++)
    {
        if(cricketer[i].vlp > cricketer[maxindex].vlp)
        {
            maxindex=i;
        }
    }
    return maxindex;
}

