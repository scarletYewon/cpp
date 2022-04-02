#include <iostream>

using namespace std;

void DPYee(int cnt)
{
	int arr[100][100];
	int num = 1;
	int i, j;

	for (i = 0; i<(cnt / 2) + 1; i++)
	{
		for (j = i; j<cnt - i; j++)   //왼쪽에서 오른쪽으로 값을 넣는 부분이다.
			arr[i][j] = num++;
		for (j = i + 1; j<cnt - i; j++)  //위에서 아래로 값을 넣는 부분이다
			arr[j][cnt - i - 1] = num++;
		for (j = cnt - i - 2; j >= i; j--)  //오른쪽에서 왼쪽으로 값을 넣는 부분이다.
			arr[cnt - i - 1][j] = num++;
		for (j = cnt - i - 2; j >= i + 1; j--)  //밑에서 위로 값을 넣는 부분이다.
			arr[j][i] = num++;
	}

	for (i = 0; i<cnt; i++)
	{
		for (j = 0; j<cnt; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int n;
	while (1)
	{
		cout << "달팽이 배열 만들기 (1 ~ 10 까지 원하는 수를 입력하세요.).? ";
		cin >> n;
		DPYee(n);
	}

	return 0;
}