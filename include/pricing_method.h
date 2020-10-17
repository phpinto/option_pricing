#ifndef _PRICING_GUARD
#define _PRICING_GUARD
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <unordered_map>


class PricingMethod {
    public:
        virtual double Black_Scholes_Option_Price() = 0;
        virtual double Binomial_Option_Price() = 0;
};

#endif