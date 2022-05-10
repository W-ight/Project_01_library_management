#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
struct time
{
    int year,month,date;
}date;
struct 
{
    char name[100];
    char auth_name[200];
    int pages;
    int copies;
}book;
struct logon
{
    char name[100];
    int password;
}user;


void print_mess( char message[])
{
    int l=0,i;
    // calculate the spaces needed to print.
    l=(185-strlen(message))/2;
    printf("\t\t\t");
    for (i=0; i<l; i++)
        printf(" ");// print the space.
    printf("%s",message); // print the message at the centre.
}
void head_mess( char message[])
{
    system("cls");// clears the screen everytime for new operation.
    printf("\n\t\t\t ##########################################################################################");
    printf("\n\t\t\t ##############                                                              ##############");
    printf("\n\t\t\t ##############              LIBRARY MANAGEMENT PROJECT IN C                 ##############");
    printf("\n\t\t\t ##############                                                              ##############");
    printf("\n\t\t\t ##########################################################################################");
    printf("\n\t\t\t ------------------------------------------------------------------------------------------");
    print_mess(message);
    printf("\n\t\t\t ------------------------------------------------------------------------------------------");
}
void welcome_mess()
{
    head_mess("made by Rakesh");
    printf("\n\n\n\n");
    printf("\n\t\t\t **//**//****//**//****//**//****//**//****//**//****//**//****//**//****//**//****//**//**");
    printf("\n\t\t\t       ============================================================================");
    printf("\n\t\t\t       =                                 WELCOME                                  =");
    printf("\n\t\t\t       =                                   TO                                     =");
    printf("\n\t\t\t       =                                 LIBRARY                                  =");
    printf("\n\t\t\t       =                                MANAGMENT                                 =");
    printf("\n\t\t\t       =                                 SYSTEM                                   =");
    printf("\n\t\t\t       ============================================================================");
    printf("\n\t\t\t **//**//****//**//****//**//****//**//****//**//****//**//****//**//****//**//****//**//**\n");
    printf("\n\n\t\t\t Enter any key to continue >>>>>> ");
    getch();
}

void search()
{   int i,n,f=0,t=0;
    FILE *fp;
    fp=fopen("lib_file.txt","r");
    char name[100];
    fseek(fp,0L,2);
    n=ftell(fp);//position of the end.
    head_mess("SEARCH BOOK");
    do{
    printf("\n\n\t\t\t Enter book name:");
    scanf("%s",name);
    rewind(fp);//again at startin position
    for (int i=0;i<n;i++)
    {fscanf(fp,"%s",book.name);
        if (strcmp(name,book.name)==0 )
        {
            f=1;
            printf("\n\n\t\t\t Books details are as follows:\n");
            fscanf(fp,"%s %d %d",book.auth_name,&book.pages,&book.copies);
            fprintf(stdout,"\n\t\t\t Book name is:%s\n",book.name);
            fprintf(stdout,"\n\t\t\t Author name is:%s\n",book.auth_name);
            fprintf(stdout,"\n\t\t\t Number of pages:%d\n",book.pages);
            fprintf(stdout,"\n\t\t\t Number of copies:%d\n",book.copies);
            break;
        }}
        if(f==1)
        {
            printf("\n\n\n\t\t\t Press Enter to continue->>>>>>>>");
            getch();
            break;
        }
        else
        {printf("\n\t\t\t WRONG NAME!!!!\n\n\t\t\tEnter Book Name  again.\n\n");
        t++;
        }
    }while(t<3);
    if (t==3)
    {
        head_mess("BOOK NOT FOUND");
        printf("\n\t\t\t ->>>>>>Book is not avaliable.");
        getch();
        system("cls");
    }
    fclose(fp);
}
void delete()
{   int t=0;
    char name[100];
    FILE *fp,*fptr;
    fp=fopen("lib_file.txt","r");
    fptr=fopen("temp.txt","w");
    head_mess("DELETE THE BOOK RECORD");
    printf("\n\n\t\t\tEnter the name of the book:");
    scanf("%s",name);
    rewind(fp);//file pointer at the startin position
    while (!feof(fp))
    {
        fscanf(fp,"%s %s %d %d",book.name,book.auth_name,&book.pages,&book.copies);
        if (strcmp(name,book.name)!=0)
            {//fwrite(&book,sizeof(book),1,fptr);
            //fscanf(fp,"%s %s %d %d",book.name,book.auth_name,&book.pages,&book.copies);
            fprintf(fptr,"\n%s %s %d %d",book.name,book.auth_name,book.pages,book.copies);
        }
        else
            t=1;
    }
    (t)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(fptr);
    remove("lib_file.txt");
    rename("temp.txt","lib_file.txt");
    getch();
}
void add_user()
{
    FILE *fp;
    fp=fopen("login.txt","a+");
    if (fp==NULL)
    {
        printf("Error_bro\n");
    }
    head_mess("ADD USER");
    printf("\n\n\t\t\t Enter The Name and password below:");
    printf("\n\n\t\t\t User Name:");
    fscanf(stdin,"%s",user.name);
    printf("\n\n\t\t\t User Password:");
    fscanf(stdin,"%d",&user.password);
    fprintf(fp,"%s %d",user.name,user.password);
    fclose(fp);
}
void show_all()
{   FILE *fg;
    fg=fopen("lib_file.txt","r");
    if (fg==NULL)
    {
        printf("Error_bro\n");
    }
    head_mess("ALL BOOKS DATA");
    //while(!feof(fg))
    do
    {
    fscanf(fg,"%s %s %d %d",book.name,book.auth_name,&book.pages,&book.copies);
    fprintf(stdout,"\n\n\t\t\t Book name is:%s\n",book.name);
    fprintf(stdout,"\n\n\t\t\t Author name is:%s\n",book.auth_name);
    fprintf(stdout,"\n\n\t\t\t Number of book pages:%d\n",book.pages);
    fprintf(stdout,"\n\n\t\t\t Number of book copies:%d\n",book.copies);
    printf("\n\n\t\t\t=================================================");
    }while(!feof(fg));
    fclose(fg);
    //fflush(stdin);
    getch();
    /*system("cls");
    system("cls");
    system("cls");
    system("cls");
    system("cls");*/
    
}
void add_book()
{
    FILE *fg;
    fg=fopen("lib_file.txt","a+");//to append the new book details in the file
    head_mess("ADD BOOK");
    printf("\n\n\t\t\t ENTER THE BOOK DETAILS BELOW:");
    printf("\n\n\n\t\t\t Enter the book name :");
    fscanf(stdin,"%s",book.name);
    printf("\n\n\t\t\t Enter the author name:");
    fscanf(stdin,"%s",book.auth_name);
    printf("\n\n\t\t\t Enter the number of pages:");
    fscanf(stdin,"%d",&book.pages);
    printf("\n\n\t\t\t Enter the number of copies:");
    fscanf(stdin,"%d",&book.copies);
    fprintf(fg,"\n%s %s %d %d",book.name,book.auth_name,book.pages,book.copies);
    fclose(fg);
}
void menu()
{
    int cho;
    do
    {   
        //system("cls");
        head_mess("MAIN MENU");
        printf("\n\n\t\t\t 1-> Search book");
        printf("\n\t\t\t 2-> Add a book record");
        printf("\n\t\t\t 3-> Delete book");
        printf("\n\t\t\t 4-> Add user");
        printf("\n\t\t\t 5-> View books");
        printf("\n\t\t\t 0-> EXIT");
        printf("\n\n\t\t\t Enter your choice >>>");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1:
            search();
            break;
            case 2:
            add_book();
            break;
            case 3:
            delete();
            break;
            case 4:
            add_user();
            break;
            case 5:
            show_all();
            break;
            case 0:
            printf("\n\n\t\t\t Thank you!!!\n\n\n\n\n");
            exit(1);
            break;
            default:
            printf("\n\n\t\t\tINVALID INPUT!!! Try again...");

        }
    }while (cho!=0);
}
void login()
{ 
    unsigned char std_name[100]={0};
    int password,t=0,f=0,n;
    FILE *fp=NULL;
    head_mess("LOGIN");
    fp=fopen("login.txt","r");
    if (fp==NULL)
    {
        printf("Error_bro\n");
    }
    fseek(fp,0L,2);
    n=ftell(fp);//position of the end.
    do{
    printf("\n\n\t\t\t Enter User Name:");
    scanf("%s",std_name);
    printf("\n\n\t\t\t Enter the password:");
    scanf("%d",&password);
    rewind(fp);//again at startin position
    for (int i=0;i<n;i++)
    {fscanf(fp,"%s %d",user.name,&user.password);
        if ((strcmp(std_name,user.name)==0 ) && (password==user.password))
        {
            f=1;
            break;
        }}
        if(f==1)
        {
            menu();
        }
        else
        {printf("\n\n\t\t\t LOGIN FAILED!!!!\n\n\n\t\t\t Enter Name and password again.\n\n");
        t++;
        }
    }while(t<3); //gives threee tries to login.
    if (t==3)
    {
        head_mess("LOGIN FAILED");
        printf("\n\n\t\t\t->>>>>>Unknown user.");
        getch();
        system("cls");
    }
    fclose(fp);
}
int main()
{   
    welcome_mess();
    login();
    return 0;
}
