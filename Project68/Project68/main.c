#include <stdio.h>
#include <assert.h>

#define Is_NoZero(NUM)			{NUM!=0;}

/*�������ܣ���n�Ľ׳�*/
unsigned int Test01(unsigned int n)
{
	unsigned int i = 0,result = 1;
	for (i = 1; i < n + 1; i++)
	{
		result *= i;
	}
	return result;
}
/*�������ܣ�����1!+2!+3!+.....+n!*/
unsigned int Test02(unsigned int n)
{
	unsigned int sum = 0,i=0;
	for (i=1;i<=n;i++)
	{
		sum += Test01(i);
	}
	return sum;
}
/*��������: ��һ�����������в���һ�������ҵ��˷����±꣬�Ҳ�������-1*/
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
/*�������ܣ��ж�ĳ������Ƿ������꣬�ǵĻ�����1�����򷵻�0*/
unsigned int Test04(unsigned int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

/*շת����������Լ������С������*/
void Test05(unsigned int num1,unsigned int num2,unsigned int* Multiple,unsigned int* Divisor)
{
	int mod = 0,temp1 =0 ,temp2=0;
	/*num1����������num2������*/
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

/*��������������Լ������С������*/
void Test06(unsigned int num1, unsigned int num2, unsigned int* Multiple, unsigned int* Divisor)
{
	int sub = 0, temp1, temp2;
	/*num1����������num2������*/
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
/*�ж�һ�����Ƿ����������ǵĻ�����1�����򷵻�0*/
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

/*�ݹ�ʵ�ִ�ӡĳ�����ֵ�ÿһλ*/
void Test08(unsigned int num)
{
	if (num>9)
	{
		Test08(num / 10);
	}
	printf("%d", num%10);
}
/*����������ʱ���������ַ�������*/
int Test09(unsigned char* str)
{
	if ((*str)=='\0')
	{
		return 0;
	}
	return 1+Test09(str+1);
}
/*����������ʱ��������n�Ľ׳�,���������*/
int Test10(unsigned int num)
{
	if (num==0)
	{
		return 1;
	}
	return num * Test10(num - 1);
}
int cnt = 0;
/*���n��쳲���������*/
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
	printf("�����룺> ");
	scanf_s("%u",&input);
	
	printf("%u�Ľ׳���%u\n",input, Test01(input));

	printf("%u�Ľ׳˺���%u\n", input, Test02(input));

	unsigned int arr[] = {1,3,5,7,8,9,10,12,45,65,98,99};
	unsigned int size = sizeof(arr) / sizeof(arr[0]);

	printf("�����룺> ");
	scanf_s("%u", &input);

	if (Test03(arr, size, input) == -1)
	{
		printf("δ�ҵ�������\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���%d\n", Test03(arr, size, input));
	}
	int i = 0;
	for (input = 1000; input < 2023; input++)
	{
		if (Test04(input))
		{
			i++;
			printf("��%d����%d������\n", i,input);
		}
	}

	unsigned int num1 = 0,num2 = 0;
	unsigned int Multiple, Divisor;

	printf("������������:> ");
	scanf_s("%d %d", &num1, &num2);

	Test05(num1, num2, &Multiple, &Divisor);

	printf("Test05:%d��%d�����Լ��:%d ��С������:%d\n", num1, num2,Divisor, Multiple);

	Test06(num1, num2, &Multiple, &Divisor);
	printf("Test06:%d��%d�����Լ��:%d ��С������:%d\n", num1, num2, Divisor, Multiple);

	for (i = 0; i < 100; i++)
	{
		if(Test07(i))
		printf("%d������\n", i);
	}

	Test08(123456);

	printf("strlen = %d\n", Test09("abcdef"));

	printf("%d�Ľ׳�%d\n", 5, Test10(5));

	printf("��%d쳲�������Ϊ%d   %d��\n", 10, Test11(10),cnt);

	return 0;
}