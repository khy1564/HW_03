#include "HW_03.h"


int main()
{
	// 힙 메모리 누수 감지 코드
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	SimpleVector<int> sim(3);

	sim.push_back(5);
	sim.push_back(12);
	sim.push_back(2);
	sim.push_back(30);
	sim.push_back(20);
	sim.push_back(33);

	cout << "생성자" << endl;
	cout << "Szie : " << sim.size() << endl;
	cout << "Capacity : " << sim.capacity() << endl;
	
	sim.pop_back();
	cout << "Szie : " << sim.size() << endl;

	SimpleVector<int> sim2 = sim;

	sim2.push_back(334);

	cout << "\n복사생성자" << endl;
	cout << "Szie : " << sim2.size() << endl;
	cout << "Capacity : " << sim2.capacity() << endl;

	cout << "\n정렬" << endl;
	cout << "sim : ";
	sim.sortData();
	cout << "\nsim2 : ";
	sim2.sortData();
	

}

