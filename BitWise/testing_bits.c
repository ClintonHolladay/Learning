/*
 * main_2.c
 *
 *  Created on: Nov 22, 2022
 *      Author: Clinton Holladay
 */


#include<stdio.h>
#include<stdint.h>


void wait_for_user();

int main(void)
{
	for(;;)
	{
		int32_t a;
		int32_t MASK = 0b0001;
		printf("Enter a number.\n");
		scanf("%d",&a);
		if(a & MASK)
		{
			printf("Your number is ODD.\n");
		}else printf("Your number is EVEN.\n");

		wait_for_user();
	}

}

void wait_for_user()//hang program to wait for user input
{
	printf("Press any key to EXIT\n");
	while(getchar()!= '\n'){}
	getchar();
}
