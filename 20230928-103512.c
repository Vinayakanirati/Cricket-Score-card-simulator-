#include<stdio.h>
#include<stdlib.h>
struct players
{
char name[20];
int  score ;
int balls;
};
void displayscore(int totalruns,int totalwickets,float overs,struct players striker,struct players nonstriker)
{
printf("\nTeam Score:%d/%d",totalruns,totalwickets);
printf("\n%s\t%d(%d)",striker.name,striker.score,striker.balls);
printf("      ");
printf("%s\t%d(%d)", nonstriker.name, nonstriker.score,nonstriker.balls);
printf("\nOvers:%.1f",overs);
}
void updatescore(int runs,int wickets,int *totalruns,int *totalwickets,float *overs,struct players *striker)
{
(*totalruns)+=runs;
(*totalwickets)+=wickets;
(*overs)+=0.1;
striker->score+=runs;
}
int main()
{ 

int numPlayer;
printf("\nenter number of players:");
scanf("%d",&numPlayer);
struct players player[numPlayer];
for(int i=1;i<=numPlayer;i++)
{ 
printf("\nENTER PLAYER %d NAME:",i);
scanf("%s",player[i].name);
player[i].score=0;
player[i].balls=0;
} 
struct players striker;
struct players nonstriker;
striker=player[1];
nonstriker=player[2];
int totalruns=0;
int totalwickets=0;
float overs=0.0;
int balls=0;
int j= 2;
while(1)
{
int runs;
int wickets;
printf("\nenter the runs scored this ball from 1 to 6:");
scanf("%d",&runs);
balls++;
striker.balls++;
if(balls==6)
{
overs=overs+0.4;
balls=0;
}
printf("\nEnter 1 if  it's  a wicket else enter 0 ");
scanf("%d",&wickets);
if(runs<0||runs>6)
{
printf("\nInvalid runs !");
continue;
}
updatescore(runs, wickets,&totalruns,& totalwickets,&overs,&striker);
displayscore (totalruns,totalwickets,overs,striker, nonstriker);
if (wickets==1)
{
striker=player[++j];
}
if(runs==1||runs==3)
{
struct players temp;
temp=striker;
striker=nonstriker;
nonstriker=temp;
}
int choice;
printf("\nEnter 1 to continue and 0 to exit");
scanf("%d",&choice);
if(choice==0)
{
printf("\n***Match ended ***\n");
displayscore(totalruns,totalwickets, overs,striker,nonstriker);
break;
}
}
return 0;
}