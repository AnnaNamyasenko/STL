#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Bill
{
protected:
	string user_name;
	double payed_sum;

public:

	Bill() :user_name(" "), payed_sum(0)
	{

	}
	virtual void input(ifstream& in)
	{
		in >> user_name;
	}
	virtual int get_type_of_bill() = 0;
	virtual void output(ofstream& out) = 0;
	virtual double get_sum() = 0;

};

class Gas: public Bill
{
private:
	int amount_of_people;

public:
	void input(ifstream& in)
	{
		Bill::input(in);
		in >> amount_of_people >> payed_sum;
	}
	double get_sum()
	{
		return payed_sum;
	}
	void output(ofstream& out)
	{
		out<< user_name << " people: " << amount_of_people << " payed sum: " <<payed_sum <<  endl;
	}
	void output()
	{
		cout << user_name <<" people: " << amount_of_people <<" payed sum: " << payed_sum <<  endl;;
	}
	int get_type_of_bill()
	{
		return 1;
	}
	bool operator<(Gas& obj)
	{
		return (this->amount_of_people< obj.amount_of_people);
	}
	bool operator>(Gas& obj)
	{
		return (this->amount_of_people> obj.amount_of_people);
	}
};

class Water: public Bill
{
private:
	int payed_lit;
	double last_showed;

public:
	void input(ifstream& in)
	{
		Bill::input(in);
		in >>  last_showed  >>payed_lit>> payed_sum;
	}
	double get_sum()
	{
		return payed_sum;
	}
	
	int get_type_of_bill()
	{
		return 2;
	}
	void output(ofstream& out)
	{
		out << user_name << ";" << " last showed : " << last_showed << " payed liters : ";
		out << payed_lit << " payed sum : " << payed_sum << endl;
	}
	void output()
	{
		cout << user_name << ";" << " last showed : " << last_showed << " payed liters : ";
		cout << payed_lit << " payed sum : " << payed_sum << endl;
	}
	bool operator<(Water& obj)
	{
		return (this->user_name < obj.user_name);
	}
	bool operator>(Water& obj)
	{
		return (this->user_name > obj.user_name);
	}

};
