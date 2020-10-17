#include "option.h"

using namespace std;

// Initializer Method
void Option::init(){
    strike_price = 0.0;
    current_price = 0.0;
    rate = 0.0;
    time_to_maturity = 0.0;
    volatility = 0.0;
}

// Default Constructor
Option::Option(){
    init();
}

// Parametrized Constructor
Option::Option(double rhs_strike_price, double rhs_current_price, double rhs_rate, double rhs_time_to_maturity, double rhs_volatility){
    strike_price = rhs_strike_price;   
    current_price = rhs_current_price;
    rate = rhs_rate;
    time_to_maturity = rhs_time_to_maturity;
    volatility = rhs_volatility;
}

// Copy Constructor
Option::Option(const Option &rhs){
    strike_price = rhs.strike_price;   
    current_price = rhs.current_price;
    rate = rhs.rate;
    time_to_maturity = rhs.time_to_maturity;
    volatility = rhs.volatility;
};

// Destructor
Option::~Option(){}; 


double Option::GetStrikePrice() {
    return strike_price;
};


double Option::GetCurrentPrice() {
    return current_price;
};


double Option::GetRate() {
    return rate;
};


double Option::GetTimeToMaturity() {
    return time_to_maturity;
};


double Option::GetVolatility() {
    return volatility;
};