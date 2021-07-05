#include<stdio.h>

int get_firstday_year(int year)
{
    int day = (year*365 +((year-1)/4)-((year-1)/100)+((year-1)/400))%7;
    return day;
}

int main()
{
    char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int days_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,j,total_days,week_day=0, space_counter=0, year;

    printf("Enter your favorite year : ");
    scanf("%d", &year);
    printf("\n\n************* Welcome To %d *************\n\n", year);

    if(year%4==0 && year%100!=0 || (year%400==0))
    {
        days_month[1]=29;
    }

    week_day=get_firstday_year(year);

    for(i=0; i<12; i++)
    {
        printf("\n\n\n---------------------%s-------------------\n",month[i]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

        for(space_counter=1; space_counter<=week_day; space_counter++)
        {
            printf("     ");
        }

        total_days=days_month[i];
        for(j=1; j<=total_days; j++)
        {
            printf("%5d", j);

            week_day++;

            if(week_day>6)
            {
                printf("\n");
                week_day=0;
            }
        }
    }


    return 0;
}
