/*
 *  Created on: Nov 22, 2022
 *  Author: Clinton Holladay
 */

#include<stdio.h>
#include<stdint.h>


void wait_for_user();

int main(void)
{
	uint32_t a, b;
	printf("Enter 2 numbers.\n");
	scanf("%d %d", &a, &b);
	printf("BITWISE (&): %d\n",(a & b));
	printf("BITWISE (|): %d\n",(a | b));
	printf("BITWISE (~): %d\n",(~a));
	printf("BITWISE (^): %d\n",(a ^ b));
	wait_for_user();
}

void wait_for_user()//hang program to wait for user input
{
	printf("Press any key to EXIT\n");
	while(getchar()!= '\n'){}
	getchar();
}
