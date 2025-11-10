#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main()
{ 
	srand(time(0));
	int number = rand()%100+1;
	int count=0;
	int a=0;
	
	printf("我已经想好了一个1到100之间的数。");
	do{
		printf("请猜这个1到100之间数：");
		scanf("%d",&a);
		count ++;
		if(a>number){
			printf("您猜的数大了。");
		}else if(a<number){
			printf("您猜的数字小了");
		}
	} while(a!= number);
	printf("太好了您用了%d次猜中了这个数字！\n",count);
	
	printf("%d\n",a%100);
	
	return 0;
}
