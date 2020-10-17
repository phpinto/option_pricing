#include "option.h"

using namespace std;

// Parametrized Constructor
OptionPrice::OptionPrice(char rhs_flag, double rhs_strike_price, double rhs_current_price, double rhs_rate, double rhs_time_to_maturity, double rhs_volatility) : 
Option(rhs_strike_price, rhs_current_price, rhs_rate, rhs_time_to_maturity, rhs_volatility) {
    flag = rhs_flag;
}

// Helper Function to calculate the Gaussian Cumuliative Distribution Function (CDF)

double GaussianCDF(double d) {
    return 0.5 * erfc(-1 * d * sqrt(0.5));
}

// Black Scholes Pricing Function
double OptionPrice::Black_Scholes_Option_Price(){
    //return strike_price + current_price + rate + time_to_maturity + volatility;
    
    // Calculating d1:
    double num1 = log(current_price/strike_price);
    double num2 = ((0.5 * pow(volatility,2)) + rate) * time_to_maturity; 
    double den = volatility * sqrt(time_to_maturity);
    double d1 = (num1 + num2) / den;

    // Calculating d2:
    double d2 = d1 - den;

    // Final Black-Scholes Formula:

    double nd1, nd2;
    double nd2_coeff = strike_price * exp(-1 * rate * time_to_maturity);
    if (flag == 'c') {
        nd1 = GaussianCDF(d1);
        nd2 = GaussianCDF(d2);
        return (current_price * nd1) - (nd2_coeff * nd2);
    }
    else if (flag == 'p') {
        nd1 = GaussianCDF(-1 * d1);
        nd2 = GaussianCDF(-1 * d2);
        return (nd2_coeff * nd2) - (current_price * nd1);
    }
    else return 0;
}

// Binomial Pricing Function
double OptionPrice::Binomial_Option_Price(){

    // Computing the up and down factors
    double u = exp(volatility * sqrt(time_to_maturity));
    double d = 1/u;

    // Computing the risk neutral probabilities
    double piu = (exp(rate * time_to_maturity) - d)/(u - d);
    double pid = 1 - piu;

    // Computing the expected prices
    double price_u = u * strike_price;
    double price_d = d * strike_price;

    // Computing upward and downward movements
    double mu, md;
    if (flag == 'c') {
        mu = max(0.0, (price_u - strike_price));
        md = max(0.0, (price_d - strike_price));
    }
    else if (flag == 'p') {
        mu = max(0.0, (strike_price - price_u));
        md = max(0.0, (strike_price - price_d));
    }
     
    // Compute the expected price:
    double value =  (mu * piu) + (md * pid);
    return  value * exp(-1 * rate * time_to_maturity);
}