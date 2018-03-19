#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

struct User
{
    char name[50];
    char phone[15];
    char pass[30];
    int user_type;

};


void debugRead();
void open_all_file(void);
void fscene(void);
void sign_in(void);
void sign_up(void);
void reg(char x);
void driver_menu(struct User user);
void passenger_menu(struct User user);

int main()
{
    open_all_file();
    fscene();

    return 0;
}

void open_all_file(void)
{
    FILE *user_data, *ride_req;
    user_data=fopen("UserDataBase.dat","rb+");
    if(user_data==NULL)
        {
            user_data=fopen("UserDataBase.dat","wb+");
        }
    fclose(user_data);

    ride_req=fopen("RideRequest.txt","rb+");
    if(ride_req==NULL)
        {
            ride_req=fopen("RideRequest.txt","wb+");
        }
    fclose(ride_req);
}

void fscene(void)
{
    int choice;
    do
    {
        printf("Do you want to sign in or sign up?\nPress 1 to sign in or press 2 to sign up: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                sign_in();
                break;
            case 2:
                sign_up();
                break;
            default:
                printf("input error");
                break;
        }
    }while(!(choice==1||choice==2));
}
void sign_in(void)
{
    char phone[15],pass[30];
    getchar();
    printf("\nPhone number: ");
    gets(phone);
    printf("Password: ");
    gets(pass);
    struct User user;
    FILE *fp;
    fp = fopen("UserDataBase.dat","rb+");
    while(fread(&user,sizeof(user),1,fp)==1) {
        if(strcmp(user.phone,phone)==0&&strcmp(user.pass,pass)==0)
        {
            if(user.user_type==1)
                driver_menu(user);
            else if(user.user_type==2)
                passenger_menu(user);
        }
    }
    printf("\nUser not found\nPlease Try again\n\n");
    fscene();

    fclose(fp);

}
void sign_up(void)
{
    FILE  *fp;
    FILE *fp2;
    struct User user;
    struct User temp;

    getchar();
    printf("Name: ");
    gets(user.name);
    printf("Phone: ");
    gets(user.phone);
    printf("Password: ");
    gets(user.pass);
    printf("Are you a driver or passenger?\nPress 1 for Driver & 2 for Passenger: ");
    scanf("%d",&user.user_type);


    fp2 = fopen("UserDataBase.dat","rb+");
    while(fread(&temp,sizeof(temp),1,fp2)==1)
    {

        if(strcmp(temp.phone,user.phone)==0)
        {
            printf("Account Exists\n");
            fscene();
        }
    }
    fclose(fp2);

    fp=fopen("UserDataBase.dat","rb+");
    fseek(fp,0,SEEK_END);
    fwrite(&user,sizeof(user),1,fp);
    fclose(fp);
    printf("You've been successfully registered");
    sign_in();
}

void driver_menu(struct User user)
{
    printf("perfect driver");
    getch();
}

void passenger_menu(struct User user)
{
    printf("perfect passenger");
    getch();
}

