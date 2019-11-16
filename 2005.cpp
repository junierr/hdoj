#include<stdio.h>
int main()
{
	int year,day,sum,month=0;
	while(~scanf("%d/%d/%d",&year,&month,&day))
	{
		sum=day;
		while(month>1)
		{
			month=month-1;
			switch(month)
			{
				case 1:sum=sum+31;break;
				case 3:sum=sum+31;break;
				case 5:sum=sum+31;break;
				case 7:sum=sum+31;break;
				case 8:sum=sum+31;break;
				case 10:sum=sum+31;break;
				case 4:sum=sum+30;break;
				case 6:sum=sum+30;break;
				case 9:sum=sum+30;break;
				case 11:sum=sum+30;break;
				default: if ((year % 400 == 0)||((year % 100 != 0)&&(year % 4 == 0)))
				{
					sum=sum+29;
				}
				         else
				         {
				         	sum=sum+28;
						 }
					break;
				}
				
			}
			printf("%d\n",sum);
		}
		return 0;
	}
