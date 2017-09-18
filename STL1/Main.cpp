#include <iostream>
#include <list>
#include <algorithm>
#include "Bill.h"

using namespace std;


bool cmp(Water obj1, Water obj2)
{
	return obj1.get_sum() < obj2.get_sum();
}

void main()
{
	ifstream in("bills.txt");
	list<Bill*> bills;
	list<Water> water;
	list<Gas> gas;
	int amount;
	in >> amount;
	int type;
	Bill* bill;
	for (int i = 0; i < amount; i++)
	{
		in >> type;
		if (type == 1)
		{
			bill = new Gas();
			bill->input(in);
			bills.push_back(bill);
		}
		else if (type == 2)
		{
			bill = new Water();
			bill->input(in);
			bills.push_back(bill);
		}
	}
	in.close();
	list<Bill*>::iterator it;
	
	for (it = bills.begin(); it != bills.end(); ++it) 
	{
		if ((*it)->get_type_of_bill() == 1)
		{
			gas.push_back(*dynamic_cast<Gas*>(*it));
		}
		if ((*it)->get_type_of_bill() == 2)
		{
			water.push_back(*dynamic_cast<Water*>(*it));
		}
	}
	list<Gas>::iterator it_gas;
	list<Water>::iterator it_water;
	gas.sort();
	gas.reverse();
	water.sort();
	ofstream out_gas("gas.txt");
	ofstream out_water("water.txt");
	ofstream out_res("result.txt");
	out_gas << "Gas bills: " << endl;
	out_water << "Water bills: " << endl;
	cout << "Gas bills: " << endl;
	cout << "Water bills: " << endl;
	for (it_gas = gas.begin(); it_gas != gas.end(); ++it_gas)
	{   
		it_gas->output(out_gas);
		it_gas->output();
	}
	for (it_water = water.begin(); it_water != water.end(); ++it_water)
	{
		it_water->output(out_water);
		it_water->output();
	}
	
	sort(water.begin(), water.end(), cmp);

	for (it_water = water.begin(); it_water != water.end(); ++it_water)
	{
		it_water->output(out_res);
	}
	system("pause");
}