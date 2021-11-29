

#include<stdio.h>
#include<string.h>


int valid_password(char *password)
{
    int i,j,count=0;
    for(i=0;i<strlen(password);i++)
    {
        if(password[i]>='A' && password[i]<='Z')
        {
            count++;
        }
    }
    if(count>0)
    {
        for(j=0;j<strlen(password);j++)
        {
            if(password[j]>='0' && password[j]<='9')
            {
                count++;
            }
        }
        if(count>3)
        {
            for(j=0;j<strlen(password);j++)
            {
                if(password[j]=='@' || password[j]=='#' || password[j]=='$' || password[j]=='%' || password[j]=='&')
                {
                    count++;
                }
            }
            if(count>4)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    char pass[20],email[20];
    printf("enter email\n");
    scanf("%s",email);
    printf("enter password\n");
    scanf("%s",pass);
  

    if(valid_password(pass)==1)
    {
        printf("valid password\n");
    }
    else
    {
        printf("invalid password\n");
    }
    return 0;
}




//commands to upload code to repository to new repository

//git init
//git add am.c
//git commit -m "first commit"
//git remote add origin
//git push -u origin master
//git status
//git log
//git diff
//git diff --staged


