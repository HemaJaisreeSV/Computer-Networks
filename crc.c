#include<stdio.h>
#include<unistd.h>
#include<string.h>

int crc(char *input, char *output, char *gp)
{
    int i,j;
    for(i=0; i<strlen(input); i++)
    {
        if((output[i])=='1')
             for(j=0; j<strlen(gp);j++)
             {
                if (output[i+j]==gp[j])
                    output[i+j]='0';
                else
                    output[i+j]='1';
             }
    }
    for(i=0;i<strlen(output);i++)
        if((output[i])=='1')
            return 1;
    return 0;
}

int main()
{
    int mode=0;
    char input[50],output[50];
    char recv[50], gp[50];
    system("clear");
    printf("\n Enter the input message in binary\n");

    scanf("%s",&input);
    printf("\n Enter the generator polynomial\n");
    scanf("%s",&gp);
    
    strcpy(output,input);
    crc(input,output,gp);
    
    printf("\n The transmitted message is %s %s\n",input,
    output+strlen(input));

    printf("\n\n Enter the received message in binary \n");
    scanf("%s",&recv);

    if(!crc(recv,output,gp))
        printf("\n No error in data\n");
    else
        printf("\n Error in data transmission has occurred\n");
}
