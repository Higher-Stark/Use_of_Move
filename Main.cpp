#include <iostream>
#include "MemoryBlock.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
MemoryBlock f();
int main()
{
	vector<MemoryBlock> mbvec(15);
	cout << "1-------------------------------------" << endl;
	mbvec.push_back(MemoryBlock(10));
	cout << "2-------------------------------------" << endl;
	mbvec.push_back(MemoryBlock(22));
	cout << "3-------------------------------------" << endl;
	MemoryBlock mb1(3);
	cout << "4-------------------------------------" << endl;
	mbvec.push_back(mb1);
	cout << "5-------------------------------------" << endl;
	MemoryBlock mb2(mb1);
	cout << "6-------------------------------------" << endl;
	vector<MemoryBlock> mbvec2(8, MemoryBlock(4));
	cout << "7-------------------------------------" << endl;
	MemoryBlock mb3 = MemoryBlock(5);
	cout << "8-------------------------------------" << endl;
	MemoryBlock mb4 = mb2;
	cout << "9-------------------------------------" << endl;
	MemoryBlock mb5(7);
	cout << "10------------------------------------" << endl;
	mb4 = mb5;
	cout << "11------------------------------------" << endl;
	MemoryBlock mb7 = f();
	cout << "12------------------------------------" << endl;
	mb1 = std::move(mb7);
	cout << "13------------------------------------" << endl;
	cout << "Do these make any sense?" << endl;
	cout << "**************************************" << endl;
	return 0;
}

MemoryBlock f()
{
	MemoryBlock mb6(66);
	return mb6;
}