#pragma once

#include "Customer.h"

class Comparer
{
public:
    bool operator()( Customer * c1, Customer* c2)
    {
        
        return c1->GetCusArrival() > c2->GetCusArrival();
    }
};

