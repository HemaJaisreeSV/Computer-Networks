#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int i,j,packet[30];
    int fsize = (rand()%16)+1;
    printf("\n\t Frame size : %d\n",fsize);
    printf("\n\t ---- DATA LOG ---- \n");
    printf("\n FRAME\t DATA\tWAITING\tACKNOW\tRESEND");
    for(i=0;i<fsize;i++)
    {
        packet[i]=rand()%1000;
        printf("\n %d \t %d",i+1,packet[i]);
        while(j=0 || rand()%2==0)
        {
            sleep(1);
            printf("\t1 ");
            sleep(1);
            for(j=2;rand()%2==0 && j<4;j++)
            {
                printf("%d ",j);
                sleep(1);
            }
            if(j==4)
                printf("\t No \tRESENDING...\n %d \t %d",i+1,packet[i]);
            else
                break;
        }

        if(j==0)
        {
            sleep(1);
            printf("\t0 ");
        }
        printf("\t YES \t No");
    }
printf("\n\n ------ ALL DATA PACKETS SENT ------\n");
return 0;
}
