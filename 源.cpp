#include <iostream>
#include "HanNuoTa.h"

using namespace std;

int main()
{
	int N;
    cin >> N;
	HanNuoTa* H = new HanNuoTa(N);

	for (int i = N; i >= 1; i--)
	{
		H->push(i);
	}
	//H->show_HanNuoTa();
	HanNuoTa* node = H->Next();
	HanNuoTa* pre = H;
	int data = 0;
	int here = 0;
	int there = 0;
	int time = 0;
	for (; !(pre->IsEmpty()&&node->IsEmpty()); node = node->Next())
	{
		if (node == pre)
		{
			node = node->Next();
			pre = pre->Next();
			continue;
		}
		if (pre->IsEmpty())
		{
			pre = pre->Next();
		}
		else if (node->IsEmpty() || pre->IsLarge(node)) {
			data = pre->Pop(node);
			node->push(data);
			here = pre->type_HanNuoTa();
			there = node->type_HanNuoTa();
			time++;
			cout << "µÚ" << time << "´Î";
			cout << here << "->" << there << " " << data << endl;
			node = node->Next();
			pre = node;
		}
	}
	//cout << time << endl;
	return 0;
}