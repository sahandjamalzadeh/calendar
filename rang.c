#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<windows.h>

void calendar();
void menu();
void age();
void conversion();
void period();

typedef enum
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8, 
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12, 
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}


void calendar() {
    int year, month, monthday, startday, roozmah, i,day,dayborn,year1,back;
    setTextColor(LIGHT_GREEN);
    printf("welcome to calendar section\n");
    printf("----------\n");
    printf("please enter year: ");
    scanf("%d", &year);
    if(year == 0)
    {
        menu();
    }
    if(year > 1498 || year < 1206)
    {
        printf("invalid input\n");
        menu();
    }
    printf("----------\n");
    printf("please enter month(1-12): ");
    scanf("%d", &month);
    if(month == 0)
    {
        menu();
    }
    if(month > 12)
    {
        printf("invalid input");
        menu();
    }
    printf("-------\n");
    printf("please enter your day:");
    scanf("%d",&day);
    if(day == 0)
    {
        menu();
    }
    if(day > 31 )
    {
        printf("invalid input\n");
        menu();
    }



    if (month < 7) {
        monthday = (month - 1) * 31;
        roozmah = 31;
    } else if(month < 12 && 6 < month){
        monthday = 6 * 31 + (month - 7) * 30;
        roozmah = 30;
    }
        else if(month == 12 && (year % 33 == 1 || year % 33 == 5 || year % 33 == 9 || year % 33 == 13 || year % 33 == 17 || year % 33 == 22 || year % 33 == 26 || year % 33 == 30)) {
            roozmah = 30;
        }
        else{
            roozmah = 29;
        }
    

    startday = ((year - 1206) * 365) + monthday + 5;

    for (i = 1206; i <= year; i++) {
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30) {
            startday++;
        }
    }

    startday = startday % 7;
    system("cls");
     setTextColor(LIGHT_PURPLE);


    printf("---------------\n");
    printf("%d\n",year);

    if (month == 1)
    {
        printf("\x1b[30;47m         FARVARDIN         \x1b[0m\n");
    } 
    else if (month == 2)
    {
        printf("\x1b[30;47m        ORDIBEHESHT        \x1b[0m\n");
    } 
    else if (month == 3)
    {
        printf("\x1b[30;47m         KHORDAD          \x1b[0m\n");
    } 
    else if (month == 4)
    {
        printf("\x1b[30;47m         TIR               \x1b[0m\n");
    } 
    else if (month == 5) 
    {
        printf("\x1b[30;47m         MORDAD            \x1b[0m\n");
    } 
    else if (month == 6) 
    {
        printf("\x1b[30;47m         SHAHRIVAR          \x1b[0m\n");
    } 
    else if (month == 7) 
    {
        printf("\x1b[30;47m            MEHR             \x1b[0m\n");
    }
    else if (month == 8)
    {
        printf("\x1b[30;47m           ABAN               \x1b[0m\n");
    } 
    else if (month == 9) 
    {
        printf("\x1b[30;47m           AZAR               \x1b[0m\n");
    } 
    else if (month == 10)
    {
        printf("\x1b[30;47m            DEY             \x1b[0m\n");
    } 
    else if (month == 11) 
    {
        printf("\x1b[30;47m             BAHMAN              \x1b[0m\n");
    } 
    else if (month == 12)
    {
        printf("\x1b[30;47m          ESFAND            \x1b[0m\n");
    }
    setTextColor(LIGHT_RED);

    printf(" SH 1SH 2SH 3SH 4SH 5SH  JO \n");

    for (i = 1; i <= startday; i++) {
        printf("    ");
    }

    for (i = 1; i <= roozmah; i++) {
        if(i<10){
            printf("  %d ",i);
        }
        else{
        printf(" %d ", i);}
        if ((i + startday) % 7 == 0) {
            printf("\n");
        }
        
    }
    printf("\n");
    year1=(1402-year)+day;
     if(month < 7)
    {
        year1+=((month-1)*31);
    }
    else if(month > 6 && month < 12)
    {
        year1+=(6*31)+((month-7)*30);
    }
    else if(month == 12)
    {
        year1+=(6*31)+(5*30);
    }
    for(i = 1206; i <= year; i++)
    {
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30) {
            year1++;
        }
    }
    dayborn=year1 % 7;
     if(dayborn == 0)
    {
        printf("4shanbeh\n");
    }
    else if(dayborn == 1)
    {
        printf("5shanbeh.\n");
    }
    else if(dayborn == 2)
    {
        printf("jomeh.\n");
    }
    else if(dayborn == 3)
    {
        printf("shanbeh.\n");
    }
    else if(dayborn == 4)
    {
        printf("1shanbeh.\n");
    }
    else if(dayborn == 5)
    {
        printf("2shanbeh.\n");
    }
    else if(dayborn == 6)
    {
        printf("3shanbeh.\n");
    }
     setTextColor(LIGHT_RED);
     int b;
     scanf("%d",&b);
     menu();
    
}


void age()
{
    int year, month, day, year1, year2, i,year3,dayborn, saal, mah, rooz ,miladyear, miladmonth, miladday,tavalaod, tavalaod1, tavalaod2;
     setTextColor(LIGHT_AQUA);
    printf("----------\n");
    printf("welcome to age section\n");
    printf("----------\n");
    printf("please enter year: ");
    scanf("%d",&year);
    if(year == 0)
    {
        menu();
    }
    if(year > 1498 || year < 1206)
    {
         printf("invalid input\n");
        menu();
        
    }
    printf("----------\n");
    printf("please enter month(1-12): ");
    scanf("%d",&month);
    if(month == 0)
    {
        menu();
    }
    if (month > 12)
    {
         printf("invalid input\n");
        menu();
    }
    printf("----------\n");
    printf("please enter day(1-31): ");
    scanf("%d",&day);
    if(day == 0)
    {
        menu();
    }
    if(day > 31)
    {
         printf("invalid input\n");
        menu();
    }
    printf("----------\n");
    system("cls");
    year1=0;
    year1=((1402-1206)*365)+(6*31)+(4*30)+7+47;
    year2=0;
    year2=((year-1206)*365)+day;
    if(month < 7)
    {
        year2+=((month-1)*31);
    }
    else if(month > 6 && month < 12)
    {
        year2+=(6*31)+((month-7)*30);
    }
    else if(month == 12)
    {
        year2+=(6*31)+(5*30);
    }
    for(i = 1206; i <= year; i++)
    {
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30) {
            year2++;
        }
    }
    year3=0;
    year3=year1-year2;
     setTextColor(LIGHT_AQUA);
    printf("you was lived for %d days in your life. \n",year3);
     setTextColor(LIGHT_RED);
    printf("          *****          \n");
    saal=0;
    mah=0;
    rooz=0;
    saal= year3 / 365;
    mah= (year3 % 365) / 30;
    rooz= (year3 % 365) % 30;
     setTextColor(LIGHT_AQUA);
    printf("you was lived for %d years & %d months & %d days.\n",saal,mah,rooz);
    dayborn=year2 % 7;
     setTextColor(LIGHT_RED);
    printf("          *****          \n");
     setTextColor(LIGHT_AQUA);
    printf("you was born on ");
    if(dayborn == 0)
    {
        printf("4shanbeh\n");
    }
    else if(dayborn == 1)
    {
        printf("5shanbeh.\n");
    }
    else if(dayborn == 2)
    {
        printf("jomeh.\n");
    }
    else if(dayborn == 3)
    {
        printf("shanbeh.\n");
    }
    else if(dayborn == 4)
    {
        printf("1shanbeh.\n");
    }
    else if(dayborn == 5)
    {
        printf("2shanbeh.\n");
    }
    else if(dayborn == 6)
    {
        printf("3shanbeh.\n");
    }
     setTextColor(LIGHT_RED);
    printf("          *****          \n");
    setTextColor(LIGHT_AQUA);
    printf("you was born on %d - %d - %d in solar year.\n",year,month,day);
    setTextColor(LIGHT_RED);
     printf("          *****          \n");
      miladyear=year + 621;
    miladmonth=month + 2;
    miladday=day + 20;
    if(miladday > 31)
    {
        miladday-=31;
        miladmonth++;
    } 
    if(miladmonth > 12)
    {
        miladmonth-=12;
        miladyear++;
    }
      setTextColor(LIGHT_AQUA);
     printf("you was born on %d - %d - %d in geogrian year.\n",miladyear,miladmonth,miladday);
     setTextColor(LIGHT_RED);
     printf("          *****          \n");
     tavalaod1=(1402*365)+(6*31)+(4*30)+7;
     tavalaod2=(1403*365)+day;
     if(month < 7)
    {
        tavalaod2+=((month-1)*31);
    }
    else if(month > 6 && month < 12)
    {
        tavalaod2+=(6*31)+((month-7)*30);
    }
    else if(month == 12)
    {
        tavalaod2+=(6*31)+(5*30);
    }
    tavalaod=tavalaod2-tavalaod1;
     setTextColor(LIGHT_AQUA);
    printf("%d days left until your birthday.\n",tavalaod);
     setTextColor(LIGHT_RED);
     printf("          *****          \n");
      setTextColor(LIGHT_PURPLE);
     printf("I am the first person say happy birthday to you:)");
       int b;
     scanf("%d",&b);
     menu();


}

void conversion()
{
    int year, month, day, miladyear, miladmonth, miladday, gamaryear, gamarmonth, gamarday, tafg;
     setTextColor(LIGHT_PURPLE);
    printf("welcome to conversion section\n");
    printf("----------\n");
    printf("please enter your year: ");
    scanf("%d",&year);
    if(year == 0)
    {
        menu();
    }
    if(year > 1498 || year < 1206)
    {
         printf("invalid input\n");
        menu();
    }
    printf("----------\n");
    printf("please enter your month: ");
    scanf("%d",&month);
    if(month == 0)
    {
        menu();
    }
    if(month > 12){
         printf("invalid input\n");
        menu();
    }
    printf("----------\n");
    printf("please enter your day: ");
    scanf("%d",&day);

    if(day == 0)
    {
        menu();
    }
    if(day > 31)
    {
         printf("invalid input\n");
        menu();
    }
    printf("----------");
    system("cls");
    miladyear=year + 621;
    miladmonth=month + 2;
    miladday=day + 20;
    if(miladday > 31)
    {
        miladday-=31;
        miladmonth++;
    } 
    if(miladmonth > 12)
    {
        miladmonth-=12;
        miladyear++;
    }
     setTextColor(LIGHT_YELLOW);
    printf("The result of convert solar year to gregorian is ");
     setTextColor(LIGHT_GREEN);
    printf("%d - %d - %d .\n",miladyear,miladmonth,miladday);
     setTextColor(LIGHT_RED);
    printf("                    *****                    \n");
    tafg=year / 33;
    gamaryear=year + tafg;
    gamarmonth=month + 7;
    gamarday=day + 28 ;
    if(gamarday >= 30)
    {
        gamarday-=30;
        gamarmonth++;
    }
    if(gamarmonth > 12)
    {
        gamarmonth-=12;
        gamaryear++;
    }
     setTextColor(LIGHT_YELLOW);
    printf("The result of convert solar year to lunar year is ");
     setTextColor(LIGHT_GREEN);

    printf(" %d - %d - %d .",gamaryear,gamarmonth,gamarday);
      int b;
     scanf("%d",&b);
     menu();
}

void period()
{
    int year1, month1, day1, year2, month2, day2, sum1, sum2 , sum,i, year, month , day;
     setTextColor(LIGHT_GREEN);
     printf("----------\n");
     printf("please enter your first year: ");
     scanf("%d",&year1);
     if(year1 == 0)
     {
       menu();
     }
     if(year1 > 1498 || year1 < 1206)
     {
         printf("invalid input\n");
        menu();
     }
     printf("----------\n");
     printf("please enter your first month: ");
     scanf("%d",&month1);
     if(month1 == 0)
     {
        menu();
     }
     if(month1 > 12)
     {
         printf("invalid input\n");
        menu();

     }
     printf("----------\n");
     printf("please enter your first day: ");
     scanf("%d",&day1);
      if(day1 == 0)
     {
        menu();
     }
     if( day1 > 31)
     {
        
         printf("invalid input\n");
        menu();

     }
     printf("----------\n");
     printf("please enter your second year: ");
     scanf("%d",&year2);
      if(year2 == 0)
     {
        menu();
     }
      if(year2 > 1498 || year2 < 1206)
     {
         printf("invalid input\n");
        menu();
     }
      printf("----------\n");
     printf("please enter your second month: ");
     scanf("%d",&month2);
      if(month2 == 0)
     {
        menu();
     }
      if(month2 > 12)
     {
         printf("invalid input\n");
        menu();

     }
     printf("----------\n");
     printf("please enter your second day: ");
     scanf("%d",&day2);
      if(day2 == 0)
     {
        menu();
     }
      if( day2 > 31)
     {
        
         printf("invalid input\n");
        menu();

     }
     printf("----------\n");
     system("cls");
     sum1=(year1*365)+day1;
      if(month1 < 7)
    {
        sum1+=((month1-1)*31);
    }
    else if(month1 > 6 && month1 < 12)
    {
        sum1+=(6*31)+((month1-7)*30);
    }
    else if(month1 == 12)
    {
        sum1+=(6*31)+(5*30);
    }
    for(i = 1; i <= year1; i++)
    {
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30) {
            sum1++;
        }
    }
    sum2=(year2*365)+day2;
     if(month2 < 7)
    {
        sum2+=((month2-1)*31);
    }
    else if(month2 > 6 && month2 < 12)
    {
        sum2+=(6*31)+((month2-7)*30);
    }
    else if(month2 == 12)
    {
        sum2+=(6*31)+(5*30);
    }
    for(i = 1; i <= year2; i++)
    {
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30) {
            sum2++;
        }
    }
    sum=abs(sum1-sum2);
     setTextColor(LIGHT_PURPLE);
    printf("The time invertal is included :\n");
    setTextColor(LIGHT_AQUA);
    printf(" %d days.\n",sum);
     setTextColor(LIGHT_PURPLE);
    printf("or in another point of view :\n");
    year= (sum / 365);
    month=(sum % 365) / 30;
    day=(sum % 365) % 30;
     setTextColor(LIGHT_AQUA);
    printf(" %d years & %d months & %d days.",year,month,day);
      int b;
     scanf("%d",&b);
     menu();

}


void menu() {
    int num;
      setTextColor(LIGHT_YELLOW);

    printf("----------\n");
    printf("[0]  quit\n");
    printf("----------\n");
    printf("[1]  calendar\n");
    printf("----------\n");
    printf("[2]  age\n");
    printf("----------\n");
    printf("[3]  conversion\n");
    printf("----------\n");
    printf("[4]  time period\n");
    printf("----------\n");
    printf("please select: ");
    scanf("%d", &num);

    if (num == 0) {
        system("cls");
        printf("bye!\n");
        printf("i hope to see you again\n");
        printf(":)");}
         else if (num == 1) {
        system("cls");
        calendar();
    } 
    else if(num==2){
        system("cls");
        age();
    }
    else if(num == 3){
        system("cls");
        conversion();
    }
    else if(num == 4)
    {
        system("cls");
        period();
    }
    else {
        printf("invalid input");
    }
}

int main() {
    menu();
    setTextColor(LIGHT_BLUE);
    setTextColor(LIGHT_GREEN);
    setTextColor(LIGHT_YELLOW);
    setTextColor(LIGHT_PURPLE);
    setTextColor(LIGHT_AQUA);
    setTextColor(LIGHT_RED);
    setTextColor(WHITE);
    return 0;
}