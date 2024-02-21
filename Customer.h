#pragma once
#include <iostream>
#include <cstdlib>
#include <queue>
#include<cmath> 
#include "Customer.h"
#include "Teller.h"
#include <list>
#include<string>
#include<queue>
using namespace std;
class Customer
{
private:
	string Name;
	int ID;
	int ArrivalTime;
	int ServiceTime;
	int WaitTime;
	int LeaveTime;
	int TellerNumber;
	
public:
	Customer(  int CusID, int CusArrival, int CusService)
	{
		ID = CusID;
		ArrivalTime = CusArrival;
		ServiceTime = CusService;
	}
	void SetCusArrival(int arr)
	{
		this->ArrivalTime = arr;
	}
	int GetCusArrival()
	{
		return this->ArrivalTime;
	}

	void SetCusService(int service)
	{
		this->ServiceTime = service;
	}
	int GetCusService()
	{
		return this->ServiceTime;
	}

	void SetCusWait(int wait)
	{
		this->WaitTime = wait;
	}
	int GetCusWait()
	{
		return this->WaitTime;
	}

	void SetCusLeave(int leave)
	{
		this->LeaveTime = leave;
	}
	int GetCusLeave()
	{
		return this->LeaveTime;
	}

	void SetCusTell(int TellNum)
	{
		this->TellerNumber = TellNum;
	}
	int GetCusTell()
	{
		return this->TellerNumber;
	}

	void SetCusID(int id)
	{
		this->ID = id;
	}
	int GetCusID()
	{
		return this->ID;
	}


	static Customer* AddCustomer()
	{
		int id;
		int arrTime;
		int serTime;

		cout << "Please Enter Your ID ";
		cin >> id;

		cout << "Please Enter Your ArrivalTime ";
		cin >> arrTime;

		cout << "Please Enter Your ServiceTime ";
		cin >> serTime;
	


		Customer* C = new Customer( id,  arrTime, serTime );
		return C;
	}
	
	

};

