// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include"Bank.h"
#include"Comparer.h"
#include <iomanip> 

using namespace std;
int Teller::Count = 1;

int main()
{
   

    Bank *bank = new Bank();
    bank->ReadCustomersFromFile("test.txt");
    bank->MainMenu();


   
    

    return 0;
}
