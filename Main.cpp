#include <iostream>

using namespace std;

//void CountDown(int n)
//{
//	if (n == 0)
//	{
//		cout << "Fire!" << endl;
//		return;
//	}
//	
//
//	CountDown(n - 1);
//
//}

void Print(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << input[i] << " ";

	}
	cout << endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;

	value1 = value2;
	value2 = temp;
}


// Sequential Sort
// ���� ����
// Time Complexity : O(n^2)
// Space Complexity : O(1) / O(n)

void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

// Selection Sort
// ���� ���� ( ���� ���� ã�Ƽ� ���ʿ� �����ϴ� �� -> Ranking�� ���ؼ� ���� �Ǵ� �� )
// TimeComplexity : O(n^2)
// SpaceComplexity : 0(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int minIndex = i;
		for (int j = i; j < size; j++)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}
		Swap(input[i], input[minIndex]);
	}
	
}


// Bubble Sort
// ���� ���� ( 2���� ��� �� ū ���� �������� �� )
// TimeComplexity : O(n^2)
// SpaceComplexity : O(n)
void BubbleSort(int input[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				Swap(input[j], input[j + 1]);
			}
		}
	}
}


// Insertion Sort
// ���� ���� ( �ڽ��� ���� ��ġ�� ã�� ���� ��, ������ ���� �� �ڿ� ���� �ȴٴµ� �̰� �ʹ� ��ƴ�...�Ф� )
// TimeComplexity :
// SpaceComplexity :

void InsertionSort(int input[], int size)
{
	
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//BubbleSort(array, ARRAY_SIZE);
	Print(array, ARRAY_SIZE);
	
}

// �� ��� �Լ��� �ð� ���⵵�� n
// ���� ���⵵ ����, n

// ȣ�� ���ÿ� �׿��� ����ϱ� ������
// ��� �Լ��� �ð� ���⵵�� ȣ�� ���ÿ� ��� �׿��°�
// ��� �Լ��� ���� ���⵵�� ȣ�� ���ÿ� ��� ����Ǿ��°�


/*<���� ���� BigO���� �˰���>

1. O(1) - Constant Pattern O�� 1���� ����� ����

	   int Sum(int x, int y)
				{
					int total{};
					total = x + y;
					return total;
				}

2. O(log n) - Logarithmic Pattern  EX. log2 n �̸� n�� 2�� ��� ���� �� �ִ���

���� n = 30�̶��
void log (int n )
{
	int x = n;

	while ( x >= 1)
		{	
			x /= 2;
		}
}
void log ( int n )
{

	for(int i = 1; i <=n; i* =2)
	{ 
			
	}

}

void log ( int n )
{
	if ( n < 1)
	{
		return;
	}
	log (n /2 );
}

3. O(n) - Livear Pattern

4. O(n * log n ) - Livear Logarithmic Pattern

--------------------------------------------

<���� BigO���� �˰���>

O(n^2) - Quadratic Polynomial

O(2^n) - Exponential Pattern

void f(int n )
{
	if(n <= 0)
	{
		return;
	}

	f(n-1);
	f(n-1);
}

--------------------------------------------

<����ϸ� �ȵǴ� BigO ����>

O(n!) - Factorial Pattern


*/

/*
Linear 1�� ������
x = 1

Quadratic 2�� ������
x^2 = 1

Cubic 3�� ������
x^3 = 1
*/

