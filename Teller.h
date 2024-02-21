#pragma once
#include <iostream>
#include <cstdlib>
#include <queue>
#include<cmath> 
#include "Customer.h"
#include <list>
#include<string>
#include<queue>
using namespace std;
class Teller
{
private:
	int ID;
	bool Free;
	int BusyTime=0;
	int CurrentTime;
	int ServedCustomer = 0;
	int TotalWait = 0;
	float AverageService=0;
	float AverageWait=0;
	float Efficiency;

public:
	Teller( )
	{
		ID = Count++;
		Free = true;
	}
	static int Count;

	void SetFree(bool b)
	{
		this->Free = b;
	}
	bool GetFree()
	{
		return this->Free;
	}

	void SetID(int id)
	{
		this->ID = id;
	}
	int GetID()
	{
		return this->ID;
	}

	void SetBusyTime(int busy)
	{
		this->BusyTime = busy;
	}
	int GetBusyTime()
	{
		return this->BusyTime;
	}
	void SetCurrentTime(int CT)
	{
		this->CurrentTime = CT;
	}
	int GetCurrentTime()
	{
		return this->CurrentTime;
	}
	void SetServedCustomer(int SC)
	{
		this->ServedCustomer = SC;
	}
	int GetServedCustomer()
	{
		return this->ServedCustomer;
	}

	
	void SetEfficiency(float eff)
	{
		this->Efficiency = eff;
	}
	int GetEfficiency()
	{
		return this->Efficiency;
	}
	void SetAvgService(float avgserv)
	{
		this->AverageService = avgserv;
	}
	int GetAvgService()
	{
		return this->AverageService;
	}
	void SetAvgWait(float avgwat)
	{
		this->AverageWait = avgwat;
	}
	int GetAvgWait()
	{
		return this->AverageWait;
	}

	void SetTotalWait(float ToTWait)
	{
		this->TotalWait = ToTWait;
	}
	int GetTotalWait()
	{
		return this->TotalWait;
	}
};

