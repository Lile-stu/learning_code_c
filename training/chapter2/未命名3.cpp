#include<stdio.h>

int main(void)
{
	int age;
	
	printf("请输入年龄：");
	
	scanf("%d",&age);
	
	printf("\n你已经存在了 %f 秒",age * 3.156e7 );
	
	return 0;	
	
}
