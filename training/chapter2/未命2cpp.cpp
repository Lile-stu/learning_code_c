#include<stdio.h>

int main(void)
{
	printf("Enter a floating-point value:");
	
	float numnum;
	
	scanf("%f", &numnum);
	
	printf("\nfixed-point notation: %f \nexponential notation: %e \np notation: %a",numnum,numnum,numnum);
	
	return 0;
}

