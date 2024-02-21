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
#include<vector>
#include"Comparer.h"
#include <iomanip> 
#include<fstream>
class Bank
{
	Teller tellers[3];
	priority_queue <Customer*, vector <Customer*>, Comparer> BankCustomers;

public:

	Bank()
	{
	}
	void MainMenu()
	{
		int key;

		do
		{
			cout << "***********************************************************\n";
			cout << "\n";
			cout << "\t\tPress 1 to Add Customer :\n";
			cout << "\n";
			cout << "\n";
			cout << "\t\tPress 2 to Show the report of Served Customers :\n";
			cout << "\n";
			cout << "\t\tPress 3 to Show the report of Tellers statistics  :\n";
			cout << "\n";
			cout << "***********************************************************\n";
			cin >> key;
			system("cls");
			Customer* C;
			switch (key)
			{
			case 1:
				C = Customer::AddCustomer();
				BankCustomers.push(C);
				system("cls");
				break;
			case 2:
				DisplayCustomer();
				cin >> key;
				break;
			case 3:
				CalcAvgServiceTime();
				CalcAvgWaitTime();
				DisplayTellerInfo();
				cin >> key;
				break;
			}


		} while (key != '0');

	}


	void AssigneCustomerToTell()
	{

		priority_queue <Customer*, vector <Customer*>, Comparer> TempQueue;
		TempQueue = BankCustomers;
		SearchTeller(TempQueue);
	}
	void SearchTeller(priority_queue <Customer*, vector <Customer*>, Comparer>& TempQueue)
	{
		while (!TempQueue.empty())
		{
			bool flag = true;
			for (int i = 0; i < 3; i++)
			{
				Customer* waiting = TempQueue.top();

				if (tellers[i].GetFree())
				{
					flag = false;
					tellers[i].SetFree(false);
					waiting->SetCusTell(tellers[i].GetID());
					waiting->SetCusWait(0);

					TempQueue.pop();
					tellers[i].SetServedCustomer(tellers[i].GetServedCustomer() + 1);
					tellers[i].SetCurrentTime(waiting->GetCusService());
					if (tellers[i].GetBusyTime() == 0)
					{
						waiting->SetCusWait(0);

						tellers[i].SetBusyTime(waiting->GetCusArrival() + waiting->GetCusService());

					}
					else
					{
						if (tellers[i].GetBusyTime() < waiting->GetCusArrival())
						{
							waiting->SetCusWait(0);

						}
						else
						{

							waiting->SetCusWait(tellers[i].GetBusyTime() - waiting->GetCusArrival());

						}

						int PreData = tellers[i].GetBusyTime();
						tellers[i].SetBusyTime(PreData + waiting->GetCusService());

					}
					waiting->SetCusTell(tellers[i].GetID());


					waiting->SetCusLeave(waiting->GetCusArrival() + waiting->GetCusService() + waiting->GetCusWait());
				}
				if (TempQueue.empty())
					i = 3;

			}

			if (flag)
			{
				DecreaseBusyTime();
				SearchTeller(TempQueue);

			}
		}
	}

	void  DecreaseBusyTime()
	{
		bool check = true;
		while (check)
		{
			for (int i = 0; i < 3; i++)
			{
				if (tellers[i].GetCurrentTime() > 0)
				{
					tellers[i].SetCurrentTime(tellers[i].GetCurrentTime() - 1);
				}
				if (tellers[i].GetCurrentTime() == 0)
				{
					tellers[i].SetFree(true);
					check = false;
					i = 3;
				}
			}
		}
	}



	
	void CalcAvgServiceTime()
	{
		for (int i = 0; i < 3; i++)
		{
			tellers[i].SetAvgService(tellers[i].GetBusyTime() / tellers[i].GetServedCustomer());
		}

	}

	void CalcAvgWaitTime()
	{
		priority_queue <Customer*, vector <Customer*>, Comparer> calcwaitqueue;
		calcwaitqueue = BankCustomers;

		while (!calcwaitqueue.empty())
		{
			Customer* Cus = calcwaitqueue.top();
			calcwaitqueue.pop();
			for (int i = 0; i < 3; i++)
			{
				if (Cus->GetCusTell() == tellers[i].GetID())
				{
					tellers[i].SetTotalWait(tellers[i].GetTotalWait() + Cus->GetCusWait());
				}

			}
			if (calcwaitqueue.empty())
			{
				
				for (int i = 0; i < 3; i++)
				{
					tellers[i].SetAvgWait(tellers[i].GetTotalWait()/tellers[i].GetServedCustomer());
				}
			}
		}
	}

	 

	void ReadCustomersFromFile(const string& filename)
	{
		ifstream file(filename);
		if (!file.is_open())
		{
			cerr << "Error: Unable to open file " << filename << endl;
			return;
		}

		int id, arrivalTime, serviceTime;
		while (file >> id >> arrivalTime >> serviceTime)
		{
			Customer* newCustomer = new Customer(id, arrivalTime, serviceTime);
			BankCustomers.push(newCustomer);
		}

		file.close();
	}

	void DisplayCustomer()
	{
		AssigneCustomerToTell();
		priority_queue<Customer*, vector<Customer*>, Comparer> DisQueue;
		DisQueue = BankCustomers;

		// Header
		cout << left << setw(20) << "Customer ID"
			<< setw(20) << "Arrival Time"
			<< setw(20) << "Waiting Time"
			<< setw(20) << "Service Time"
			<< setw(20) << "Leaving Time"
			<< setw(20) << "Teller Number" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------\n";

		// Data
		while (!DisQueue.empty())
		{
			Customer* DisCus = DisQueue.top();
			DisQueue.pop();
			cout << left << setw(20) << DisCus->GetCusID()
				<< setw(20) << DisCus->GetCusArrival()
				<< setw(20) << DisCus->GetCusWait()
				<< setw(20) << DisCus->GetCusService()
				<< setw(20) << DisCus->GetCusLeave()
				<< setw(20) << DisCus->GetCusTell() << endl;
		}
	}

	void DisplayTellerInfo()
	{
		cout << left << setw(20) << "Teller ID"
			<< setw(20) << "Busy Time"
			<< setw(20) << "Total Wait Time"
			<< setw(20) << "Average Wait Time"
			<< setw(20) << "Average Busy Time" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------\n";

		for (int i = 0; i < 3; i++)
		{
			cout << left << setw(20) << tellers[i].GetID()
				<< setw(20) << tellers[i].GetBusyTime()
				<< setw(20) << tellers[i].GetTotalWait()
				<< setw(20) << tellers[i].GetAvgWait()
				<< setw(20) << tellers[i].GetAvgService() << endl;
		}


	}

};

