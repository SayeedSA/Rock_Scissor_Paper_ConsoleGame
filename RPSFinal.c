#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

void login();
void logic();
void runGame();
void registration();
int gameMenu();
void setup();
void accountDelete();
void storySearch();
void viewScore();
void editPassword();
void updateInfo();
void mainMenu();
void exitGame();

char checkUsername[45], showUsername[45], maxPointUser[45], searchUN[40], searchPW[40];
char fn[50],ln[50],un[40],pw[40],pn[20];
int you,computer,ch, found=0;  ///global variable
int ywin=0, cwin=0, gRound=0,draw=0, yscore=0, cscore=0, cScorePrint=0, yScorePrint=0, cMax=0, yMax=0, input=0;
int i,len,len1,j;
FILE *f, *fTemp, *log1;

struct logins
{
    char fname[50];
    char lname[50];
    char username[40];
    char password[40];
    char phone_Number[20];
} l,l2;

void runGame()
{
    system("cls");
    setup();
    logic();
}

void registration()
{
    //system("COLOR 5F");
    FILE *log;
    log=fopen("login12.txt","ab+");
    printf("Enter FirstName:");
    scanf("%s", &l.fname);
    printf("Enter LastName:");
    scanf("%s", &l.lname);
    printf("Enter Username:");
    scanf("%s", &l.username);

    while(fread(&l2,sizeof(l2),1,log))
    {
        if(strcmp(l.username,l2.username)==0)
        {
            system("cls");
            printf("This username has already been taken!\nTry using another username.\nPress any key to continue.. ");
            fclose(log);
            getch();
            system("cls");
            registration();
        }
        else
        {
            continue;
        }
    }

    printf("Enter Password:");
    scanf("%s", &l.password);
    printf("Enter Phone Number:");
    scanf("%s", &l.phone_Number);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("Your UserName is UserId\n\n");
    printf("Now Login With User Id Or Password\n\n");
    printf("\n Press Any key to continue.......\n");
    getch();
    system("CLS");
    login();

}

void login()
{
    //system("COLOR 5F");

    char checkPassword[20];
    log1=fopen("login12.txt","r");
    if(log1==NULL)
    {
        printf("No log in registry found!\nRegister first..\n");
        main();
    }
    else{
    printf("USER ID: ");
    scanf("%s", &checkUsername);
    printf("USER PASSWORD: ");
    scanf("%s", &checkPassword);

    while(fread(&l,sizeof(l),1,log1)==1)
    {
        if(stricmp(checkUsername,l.username)==0 && strcmp(checkPassword,l.password)==0)
        {
            system("cls");
            fclose(log1);
            mainMenu();

        }
    }
    fclose(log1);
    printf("\nPlease enter valid user id or password\n");
    printf("Try again\n");
    main();
}
}

void logic()
{
    switch(you)
    {
    case 1:
        if(computer==1)  ///you=rock, computer=rock
        {
            printf("\nYou = rock \nComputer = rock");
            printf("\nGame Draw");
            draw++;
            gRound++;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");

        }
        else if(computer==2)   ///you=rock, computer=paper
        {
            printf("\nYou = rock \nComputer = paper");
            printf("\nComputer Win");
            gRound++;
            cwin++;
            cscore=cscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        else
        {
            printf("\nYou = rock\nComputer = scissor");
            printf("\n You Win");
            ywin++;
            gRound++;
            yscore=yscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        break;
    case 2:
        if(computer==1)  ///you=paper, computer=rock
        {
            printf("\nYou = paper \nComputer = rock");
            printf("\nYou Win");
            ywin++;
            gRound++;
            yscore=yscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        else if(computer==2)   ///you=paper, computer=paper
        {
            printf("\nYou = paper \nComputer = paper");
            printf("\nGame Draw");
            draw++;
            gRound++;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        else
        {
            printf("\nYou = paper\nComputer = scissor");
            printf("\nComputer Win");
            cwin++;
            gRound++;
            cscore=cscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        break;
    case 3:
        if(computer==1)  ///you=scissor, computer=rock
        {
            printf("\nYou = Scissor \nComputer = rock");
            printf("\nComputer Win");
            cwin++;
            gRound++;
            cscore=cscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        else if(computer==2)   ///you=scissor, computer=paper
        {
            printf("\nYou = Scissor \nComputer = paper");
            printf("\nYou Win");
            ywin++;
            gRound++;
            yscore=yscore+5;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        else
        {
            printf("\nYou = Scissor\nComputer = scissor");
            printf("\nGame Draw");
            draw++;
            gRound++;
            printf("\n\n\n");
            printf("Round = %d\t", gRound);
            printf("Draw = %d\t", draw);
            printf("You won = %d time(s)\t", ywin);
            printf("Computer won = %d time(s)\t\n", cwin);
            printf("%s's score = %d\t",checkUsername,yscore);
            printf("Computer's score = %d\t\n\n",cscore);
            printf("Enter any key to play again.. ");
        }
        break;
    case 4:
        system("cls");
        mainMenu();
        break;
    default:
        system("cls");
        printf("\n Invalid User Choice");
        printf("Press any key to continue.. ");
    }
    getch();
    system("cls");
    runGame();
}

void accountDelete()
{
    do
    {
        found=0;
        printf("Enter your password: ");
        scanf("%s",&searchPW);
        f=fopen("login12.txt","r");
        fTemp=fopen("temp.txt","w");
        while(fread(&l,sizeof(l),1,f)==1)
        {
            if(strcmp(searchPW,l.password)==0 && strcmp(checkUsername,l.username)==0)
            {
                found++;
            }
        }
        fclose(f);
        if(found==1)
        {
            f=fopen("login12.txt","rb+");
            printf("Remove account request for %s\n",checkUsername);
            while(fread(&l,sizeof(l),1,f)==1)
            {
                if(strcmp(checkUsername,l.username)!=0 && strcmp(searchPW,l.password)!=0)
                {

                    fwrite(&l,sizeof(l),1,fTemp);
                }
            }
            fclose(f);
            fclose(fTemp);
            remove("login12.txt");
            rename("temp.txt","login12.txt");
            printf("Successfully removed your account..\n");
            ch=0;
        }
        else
        {
            printf("\n..::Password incorrect!");
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
        scanf("%d",&ch);
        }
    }
    while(ch==1);
}

void storySearch()
{
    do
    {
        found=0;
        printf("Enter username to search: ");
        scanf("%s",&searchUN);
        f=fopen("gameScore.txt","r");
        printf("Search result for %s\n",searchUN);
        while(fscanf(f, "%d %d %s\n", &cScorePrint, &yScorePrint, &showUsername)==3)
        {
            if(strcmp(showUsername,searchUN)==0)
            {
                found++;
                printf("Computer's score : %d, %s's score : %d\n", cScorePrint, showUsername, yScorePrint);
            }
        }
        if(found==0)
        {
            printf("\n..::No match found!");
        }
        else
        {
            printf("\n..::%d match(s) found!",found);
        }

        fclose(f);
        printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
        scanf("%d",&ch);
    }
    while(ch==1);
}

void viewScore()
{
    if( (f = fopen("gameScore.txt","r")) == NULL)
    {
        printf("Error opening file. File may not exist!\n");
    }
    while(fscanf(f, "%d %d %s\n", &cScorePrint, &yScorePrint, &showUsername) == 3)
    {
        printf("Computer's score : %d, %s's score : %d\n", cScorePrint, showUsername, yScorePrint);
        if(cMax < cScorePrint)
        {
            cMax = cScorePrint;
        }
        if(yMax < yScorePrint)
        {
            yMax = yScorePrint;
            memcpy(maxPointUser, showUsername, sizeof(showUsername));
        }
    }
    printf("Computer's all time highest score: %d\n", cMax);
    printf("Player's all time highest score: %d, Scorer: %s\n", yMax, maxPointUser);
    printf("Enter any key to continue.. ");
    fclose(f);
    getch();
}

void editPassword()
{
    do
    {
        found=0;
        printf("Enter your old password: ");
        scanf("%s",&searchPW);
        f=fopen("login12.txt","r");
        fTemp=fopen("temp.txt","ab+");
        while(fread(&l,sizeof(l),1,f)==1)
        {
            if(strcmp(searchPW,l.password)==0 && strcmp(checkUsername,l.username)==0)
            {
                found++;
                memcpy(fn,l.fname,sizeof(l.fname));
                memcpy(ln,l.lname,sizeof(l.lname));
                memcpy(un,l.username,sizeof(l.username));
                memcpy(pn,l.phone_Number,sizeof(l.phone_Number));
            }
        }
        fclose(f);
        if(found==1)
        {
            f=fopen("login12.txt","rb+");
            printf("Password change request for %s\n",checkUsername);
            while(fread(&l,sizeof(l),1,f)==1)
            {
                if(stricmp(searchPW,l.password)!=0 && strcmp(checkUsername,l.username)!=0)
                {
                    printf("chk : %s\n",l.username);
                    fwrite(&l,sizeof(l),1,fTemp);
                }
            }
            printf("Enter new password: ");
            scanf("%s",l.password);
            memcpy(l.fname,fn,sizeof(fn));
            memcpy(l.lname,ln,sizeof(ln));
            memcpy(l.username,un,sizeof(un));
            memcpy(l.phone_Number,pn,sizeof(pn));
            fwrite(&l,sizeof(l),1,fTemp);
            fclose(f);
            fclose(fTemp);
            remove("login12.txt");
            rename("temp.txt","login12.txt");
            printf("Successfully changed password..\n");
        }
        else
        {
            printf("\n..::Incorrect password!");
        }


        printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
        scanf("%d",&ch);
    }
    while(ch==1);
}

void updateInfo()
{
    int n3;
    system("COLOR 5F");
    printf("                    ***********************UPDATE INFORMATION*************************\n\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("                    \xB2\xB2          1.To update password         Enter 1        \xB2\xB2\n");
    printf("                    \xB2\xB2          2.To delete your account     Enter 2        \xB2\xB2\n");
    printf("                    \xB2\xB2          3.To go to the previous menu Enter 3        \xB2\xB2\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n                             ENTER YOUR CHOICE: ");

    scanf("%d",&n3);
    if(n3==1)
    {
        system("cls");
        editPassword();
        system("cls");
        printf("Password changed!\nYou must log in again..\n");
        main();
    }
    else if(n3==2)
    {
        system("cls");
        accountDelete();
        system("cls");
        printf("Account deleted!\nYou must log in/Register to use again..\n");
        main();
    }
    else if(n3==3)
    {
        system("cls");
        mainMenu();
    }
    else
    {
        system("cls");
        printf("Wrong input!\nTry again..\n\n");
        updateInfo();
    }
}

void mainMenu()
{
    int n1;
    system("COLOR 5F");
    printf("                    ***********************MAIN MENU*************************\n\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("                    \xB2\xB2            1.To play game           Enter 1          \xB2\xB2\n");
    printf("                    \xB2\xB2            2.To update information  Enter 2          \xB2\xB2\n");
    printf("                    \xB2\xB2            3.To view score          Enter 3          \xB2\xB2\n");
    printf("                    \xB2\xB2            4.To exit                Enter 4          \xB2\xB2\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n                             ENTER YOUR CHOICE: ");

    scanf("%d",&n1);

    if(n1==1)
    {
        system("cls");
        while(1)
        {
            runGame();
        }
    }
    else if(n1==2)
    {
        system("cls");
        updateInfo();
    }
    else if(n1==3)
    {
        system("cls");
        int n2;
        system("COLOR 5F");
        printf("                    ***********************VIEW SCORE*************************\n\n");
        printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
        printf("                    \xB2\xB2        1.To view all score             Enter 1       \xB2\xB2\n");
        printf("                    \xB2\xB2        2.To view specific user's score Enter 2       \xB2\xB2\n");
        printf("                    \xB2\xB2        3.To go to previous menu        Enter 3       \xB2\xB2\n");
        printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
        printf("\n                             ENTER YOUR CHOICE: ");

        scanf("%d",&n2);

        if(n2==1)
        {
            system("cls");
            viewScore();
            system("cls");
            mainMenu();
        }
        else if(n2==2)
        {
            system("cls");
            storySearch();
            system("cls");
            mainMenu();
        }
        else if(n2==3)
        {
            system("cls");
            mainMenu();
        }
        else
        {
            system("cls");
            printf("Wrong input!\nTry again..\n\n");
            mainMenu();
        }

    }
    else if(n1==4)
    {
        exitGame();
    }
    else
    {
        system("cls");
        printf("Wrong input!\nTry again..\n\n");
        mainMenu();
    }
}

void exitGame()
{
    system("cls");
label2:
    printf("\t1.Save score and exit\n");
    printf("\t2.Exit without saving the score\n");
    printf("\t3.Return to main menu\n");
    scanf("%d", &input);
    if(input==1)
    {
        f = fopen("gameScore.txt","a+");
        fprintf(f, "%d ", cscore);
        fprintf(f, "%d ", yscore);
        fprintf(f, "%s\n", checkUsername);
        fclose(f);
        exit(0);
    }
    else if(input == 2)
    {
        exit(0);
    }
    else if(input == 3)
    {
        mainMenu();
    }
    else
    {
        printf("Wrong input, try again.\n");
        goto label2;
    }
}

int gameMenu()
{
    system("COLOR 5F");         ///for coloring background and foreground
    int you1;
    printf("\n                               WELCOME TO ROCK PAPER SCISSOR GAME                          \n\n");
    printf("                    ***********************GAME MENU*************************\n\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("                    \xB2\xB2                1.Select Rock                         \xB2\xB2\n");
    printf("                    \xB2\xB2                2.Select Paper                        \xB2\xB2\n");
    printf("                    \xB2\xB2                3.Select Scissor                      \xB2\xB2\n");
    printf("                    \xB2\xB2                4.Go to main menu                     \xB2\xB2\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

    printf("\n                             ENTER YOUR CHOICE: ");

    scanf("%d", &you1);
    return(you1);
}


void setup()    ///computer rand number set
{
label:
    computer=rand()%4;
    if(computer==0)
        goto label;
    you=gameMenu();
}

int main()
{
    int n;
    system("COLOR 5F");
    printf("                    ***********************REGISTER AND LOGIN*************************\n\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("                    \xB2\xB2                1.To log in   Enter 1                 \xB2\xB2\n");
    printf("                    \xB2\xB2                2.To Register Enter 2                 \xB2\xB2\n");
    printf("                    \xB2\xB2                3.To exit     Enter 3                 \xB2\xB2\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n                             ENTER YOUR CHOICE: ");


    scanf("%d",&n);
    if(n==1)
    {
        login();
    }
    else if(n==2)
    {
        registration();
    }
    else if(n==3)
    {
        exit(0);
    }
    else
    {
        printf("invalid\n");
        printf("Try again\n");
        main();
    }

    return 0;
}
