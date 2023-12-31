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
// 순차 정렬
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
// 선택 정렬 ( 작은 값을 찾아서 앞쪽에 정렬하는 것 -> Ranking에 의해서 정렬 되는 것 )
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
// 버블 정렬 ( 2개씩 묶어서 더 큰 값을 내보내는 것 )
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
// 삽입 정렬 ( 자신이 있을 위치에 찾아 들어가는 것, 나보다 작은 값 뒤에 서면 된다는데 이거 너무 어렵다...ㅠㅠ )
// TimeComplexity : O(n^2)
// SpaceComplexity : O(n)

void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++)
	{
		// j는 i 부터 시작
		int j = i;

		// temp용 swap하기 위함
		int target = input[i];

		while (--j >= 0 && target < input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Merge Sort
// 병합 정렬 / 합병 정렬
// Time Complexity : O(n log n)
// Space Complexity : O(n)
void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else 
		{
			temp[tempIndex++] = input[j++];
		}
	}

	// 남아 있는 것 병합
	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	// 임시 배열 -> 원래 배열로 복사
	tempIndex = 0;
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];
	}
}

void MergeSort(int input[], int start, int end, int temp[])
{
	// Base case
	if (start >= end)
	{
		return;
	}

	// 배열의 절반을 찾을 때는 전체 길이에서 반으로 나눠야한다.
	int half = (start + end) / 2;

	// Recursive case
	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	//Merge
	Merge(input, start, half, end, temp);
}

// Quick Sort
// 빠른 정렬 - MergeSort는 임시 배열이 함께 가야한다는 단점이 있음. 그것을 보완하고자 만들어진 정렬 알고리즘
// 전체 배열에서 임의의 하나의 값을 Pivot으로 지정
// Pivot을 기준으로 좌우로 분할
// Pivot보다 작은 값을 Pivot의 왼쪽에  Pivot보다 큰 값을 Pivot의 오른쪽에 정렬하는 것

// TimeComplexity : O(n log n)
// SpaceComplexity : O(n)
void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (left < j)
	{
		QuickSort(input, left, j);
	}
	if (i < right)
	{
		QuickSort(input, i, right);
	}
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//BubbleSort(array, ARRAY_SIZE);
	//InsertionSort(array, ARRAY_SIZE);

	/*int tempArray[ARRAY_SIZE]{};
	MergeSort(array, 0, ARRAY_SIZE - 1, tempArray);*/
	
	QuickSort(array, 0, ARRAY_SIZE - 1);

	Print(array, ARRAY_SIZE);
	
}

// 위 재귀 함수의 시간 복잡도는 n
// 공간 복잡도 또한, n

// 호출 스택에 쌓여서 출력하기 때문에
// 재귀 함수의 시간 복잡도는 호출 스택에 몇번 쌓였는가
// 재귀 함수의 공간 복잡도는 호출 스택에 몇번 선언되었는가


/*<가장 빠른 BigO패턴 알고리즘>

1. O(1) - Constant Pattern O의 1패턴 상수식 패턴

	   int Sum(int x, int y)
				{
					int total{};
					total = x + y;
					return total;
				}

2. O(log n) - Logarithmic Pattern  EX. log2 n 이면 n을 2로 몇번 나눌 수 있느냐

만약 n = 30이라면
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

<느린 BigO패턴 알고리즘>

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

<사용하면 안되는 BigO 패턴>

O(n!) - Factorial Pattern


*/

/*
Linear 1차 방정식
x = 1

Quadratic 2차 방정식
x^2 = 1

Cubic 3차 방정식
x^3 = 1
*/

