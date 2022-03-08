#include<iostream>
using namespace std;
void Enter(int* p, int n);
void show(int* p, int n);
void Add(int*& p, int& n);
void Delete(int*& p, int& n);
void Change_memory(int*& p, int old, int new_memory);
int main()
{
	int n; cout << "\n Enter n : "; cin >> n;
	// enter and show 
	int* p = new int[n];// gọi biến con trỏ
	Enter(p, n);
	show(p, 10);
	Add(p, n);
	show(p, 10);
	Delete(p, n);
	show(p, 10);
}
void Enter(int* p, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the value " << i << " : " << endl ;
		cin >> p[i];
	}
}
void show(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "The value  " << i << " : " << p[i] << endl ;
	}
}
void Change_memory(int*& p, int old, int new_memory)
{
	int *temp = p; // khai bám tạm 
	p = new int(new_memory);// nhà mới
			for (int i = 0; i < old; i++) // dịch theo nhà cũ 
			{
				p[i] = temp[i];
			}
			if (new_memory < old)
			{
				for (int i = 0; i < new_memory; i++) // dịch theo nhà cũ 
				{
					p[i] = temp[i];
				}
			}
	delete[] temp; // xóa nhà cũ đi 
}
void Add(int*& p, int& n)
{
	Change_memory(p, n, n = n + 1);
	int location ; cout << "\nEnter the location to add: "; cin >> location;
	int value; cout << "\nEnter the value to add: "; cin >> value;
	for (int i = n - 1; i >= location; i--)
	{
		p[i + 1] = p[i];
	}
	p[location] = value;
	cout << "========  " << n << "  ========" << endl; 
}
void Delete(int*& p, int &n)
{
	int location; cout << "\n Enter location to delete: "; cin >> location;// Khai báo biến vị trí xóa
	for (int i = location; i <= n-1; i++) 
	{
		p[i] = p[i + 1];
	}
	Change_memory(p, n, n--);
}
