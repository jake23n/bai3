//bài 3: Cho mảng 2 chiều số nguyên. Hãy xoá cột có nhiều số nguyên tố nhất.
// sau khi xoá xong, hãy biến ma trận thành ma trận vuônng bằng cách thêm dòng hoặc thêm cột với các giá trị ngẫu nhiên.

#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

void nhapmang(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl;
}
void xuatmang(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << endl;
}
void xuatmang(int a[][100], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
// mảng ngẫu nhiên
void songaunhien(int a[][100], int n, int m)
{
	random_device rd;
	mt19937 rng(rd());


	uniform_int_distribution<int> uni(1, 9);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			a[i][j] = uni(rng);
	}
}
// return giá trị ngẫu nhiên
int songaunhien(int a[][100], int n, int m, int x)
{
	random_device rd;
	mt19937 rng(rd());


	uniform_int_distribution<int> uni(1, 10);
	int kq = uni(rng);
	return kq;
}
// check số nguyên tố
int songuyento(int n)
{
	if (n <= 1) return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)  return 0;
	}
	return 1;
}
// xoá cột
void xoacot(int a[][100], int& n, int& m, int c)
{
	for (int i = 0; i < n; i++)
		for (int j = c; j <= m - 1; j++)
			a[i][j] = a[i][j + 1];
	m--;
}
void chendong(int a[][100], int& m, int n, int d)
{		
	// phải để d+1 vì nếu để n hay m thì nó bị trùng giá trị n hoặc m ở hàm kq
	// lí do vì sao chỉ để d+1 vì nó chỉ cần chạy 1 nghiệm thôi và khi cần chạy thêm hàm lại được gọi 
		for (int i = d; i < d+1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = songaunhien(a, m, n, 0);
			}
		}
		m++;
}
void chencot(int a[][100], int m, int& n, int c)
{
	for (int i = 0; i < m; i++)
	{
		// phải để c+1 vì nếu để n hay m thì nó bị trùng giá trị n hoặc m ở hàm kq
		// lí do vì sao chỉ để c+1 vì nó chỉ cần chạy 1 nghiệm thôi và khi cần chạy thêm hàm lại được gọi 
		for (int j = c; j < c+1; j++)
		{
			a[i][j] = songaunhien(a, m, n, 0);
		}
	}
		n++;

}
void kq(int a[][100], int& m, int& n)
{
	int count[100] = {0}, max = -1, d = 0;
	// chạy phép đếm
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (songuyento(a[i][j]) == 1)
				count[j]++;

	// tìm phép đếm lớn nhất của từng cột
	for (int j = 0; j < n; j++)
	{
		if (count[j] > max)
		{
			max = count[j];
		}
	}

	// cout số đếm max của số nguyên tố và mảng phụ bao gồm đếm số nguyên  tố từng cột
	cout << max << endl;
	xuatmang(count, n);

	int t[100] = { 0 }, dem = 0;
	for (int j = 0; j < n; j++)
	{
		if (count[j] == max)
		{
			t[j] = j;
			dem++;
		}
	}
	// xoá cột khi thoả có trường hợp dem = nhau
	for (int i = 0; i < dem; i++)
	{
		xoacot(a, m, n, i);
	}

	cout << "mang khi da xoa\n";
	xuatmang(a, m, n);

	// xuất nghiệm test
	cout << n << " " << m << endl;
	if (n > m)
	{
		for (int i = m; i < n ; i++)
			// nếu để nhu này thì i lúc đầu sẽ  = m và nếu hàm chencot i < m sẽ ko chạy được
			chendong(a, m , n,i);
	}
	else if (m > n)
	{
		for (int i = n; i < m ; i++)
			// nếu để nhu này thì i lúc đầu sẽ  = n và nếu hàm chencot j < n sẽ ko chạy được
			chencot(a, m, n,i);
	}
	// test nghiệm n m khi thay đổi
	cout << n << " " << m << endl;
	xuatmang(a, m, n);
}
int main()
{
	int a[100][100], n = 0, m = 0;
	cin >> m >> n;
	songaunhien(a, m, n);
	xuatmang(a, m, n);

	kq(a, m, n);
}