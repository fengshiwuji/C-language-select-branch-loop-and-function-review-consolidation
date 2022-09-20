#include <stdio.h>
#include <assert.h>

#define Is_NoZero(NUM)			{NUM!=0;}

/*函数功能：求n的阶乘*/
unsigned int Test01(unsigned int n)
{
	unsigned int i = 0,result = 1;
	for (i = 1; i < n + 1; i++)
	{
		result *= i;
	}
	return result;
}
/*函数功能：计算1!+2!+3!+.....+n!*/
unsigned int Test02(unsigned int n)
{
	unsigned int sum = 0,i=0;
	for (i=1;i<=n;i++)
	{
		sum += Test01(i);
	}
	return sum;
}
/*函数功能: 在一个有序数组中查找一个数，找到了返回下标，找不到返回-1*/
int Test03(unsigned int* arr,unsigned int size,unsigned int num)
{
	unsigned int left = 0;
	unsigned int right = size - 1;
	while (left < right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else if(arr[mid]<num)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
/*函数功能：判断某个年份是否是闰年，是的话返回1，否则返回0*/
unsigned int Test04(unsigned int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

/*辗转相除法求最大公约数和最小公倍数*/
void Test05(unsigned int num1,unsigned int num2,unsigned int* Multiple,unsigned int* Divisor)
{
	int mod = 0,temp1 =0 ,temp2=0;
	/*num1做被除数，num2做除数*/
	temp1 = (num1 > num2) ? num1 : num2;
	temp2 = (num1 > num2) ? num2 : num1;
	mod = temp1 % temp2;
	while (mod)
	{
		temp1 = temp2;
		temp2 = mod;
		if (temp1 <  temp2)
		{
			temp1 = temp1 ^ temp2;
			temp2 = temp1 ^ temp2;
			temp1 = temp1 ^ temp2;
		}
		mod = temp1 % temp2;
	}
	*Divisor = temp2;
	*Multiple = num1*num2/temp2;
}

/*更相减损术求最大公约数和最小公倍数*/
void Test06(unsigned int num1, unsigned int num2, unsigned int* Multiple, unsigned int* Divisor)
{
	int sub = 0, temp1, temp2;
	/*num1做被除数，num2做除数*/
	temp1 = (num1 > num2) ? num1 : num2;
	temp2 = (num1 > num2) ? num2 : num1;
	sub = temp1 - temp2;
	while (sub)
	{
		temp1 = temp2;
		temp2 = sub;
		if (temp1 < temp2)
		{
			temp1 = temp1 ^ temp2;
			temp2 = temp1 ^ temp2;
			temp1 = temp1 ^ temp2;
		}
		sub = temp1 - temp2;
	}
	*Divisor = temp2;
	*Multiple = num1 * num2 / temp2;
}
/*判断一个数是否是素数，是的话返回1，否则返回0*/
unsigned int Test07(unsigned int num)
{
	unsigned int i = 0;
	for (i = 2; i < num; i++)
	{
		if ((num % i) == 0)
		{
			return 0;
		}
	}
	return 1;
}

/*递归实现打印某个数字的每一位*/
void Test08(unsigned int num)
{
	if (num>9)
	{
		Test08(num / 10);
	}
	printf("%d", num%10);
}
/*不允许创建临时变量，求字符串长度*/
int Test09(unsigned char* str)
{
	if ((*str)=='\0')
	{
		return 0;
	}
	return 1+Test09(str+1);
}
/*不允许创建临时变量，求n的阶乘,不考虑溢出*/
int Test10(unsigned int num)
{
	if (num==0)
	{
		return 1;
	}
	return num * Test10(num - 1);
}
int cnt = 0;
/*求第n个斐波那契切数*/
int Test11(unsigned int num)
{
	assert(num);
	cnt++;
	if (num <= 2)
	{
		return 1;
	}
	return Test11(num - 1)+ Test11(num - 2);
}

int main(void)
{
	unsigned int input = 0;
	printf("请输入：> ");
	scanf_s("%u",&input);
	
	printf("%u的阶乘是%u\n",input, Test01(input));

	printf("%u的阶乘和是%u\n", input, Test02(input));

	unsigned int arr[] = {1,3,5,7,8,9,10,12,45,65,98,99};
	unsigned int size = sizeof(arr) / sizeof(arr[0]);

	printf("请输入：> ");
	scanf_s("%u", &input);

	if (Test03(arr, size, input) == -1)
	{
		printf("未找到该数字\n");
	}
	else
	{
		printf("找到了，下标是%d\n", Test03(arr, size, input));
	}
	int i = 0;
	for (input = 1000; input < 2023; input++)
	{
		if (Test04(input))
		{
			i++;
			printf("第%d个：%d是闰年\n", i,input);
		}
	}

	unsigned int num1 = 0,num2 = 0;
	unsigned int Multiple, Divisor;

	printf("请输入两个数:> ");
	scanf_s("%d %d", &num1, &num2);

	Test05(num1, num2, &Multiple, &Divisor);

	printf("Test05:%d和%d的最大公约数:%d 最小公倍数:%d\n", num1, num2,Divisor, Multiple);

	Test06(num1, num2, &Multiple, &Divisor);
	printf("Test06:%d和%d的最大公约数:%d 最小公倍数:%d\n", num1, num2, Divisor, Multiple);

	for (i = 0; i < 100; i++)
	{
		if(Test07(i))
		printf("%d是素数\n", i);
	}

	Test08(123456);

	printf("strlen = %d\n", Test09("abcdef"));

	printf("%d的阶乘%d\n", 5, Test10(5));

	printf("第%d斐波那契数为%d   %d次\n", 10, Test11(10),cnt);

	return 0;
}