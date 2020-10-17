#ifndef _OPTION_GUARD
#define _OPTION_GUARD
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


class Option {
    protected:
        void init();
        double strike_price;
        double current_price;
        double rate;
        double time_to_maturity;
        double volatility;
    public:
        Option();
        Option(double rhs_strike_price, double rhs_current_price, double rhs_rate, double rhs_time_to_maturity, double rhs_volatility);
        Option(const Option &rhs);
        ~Option();

        double GetStrikePrice();
        double GetCurrentPrice();
        double GetRate();
        double GetTimeToMaturity();
        double GetVolatility();
};

#endif