#ifndef _OPTION_PRICE_GUARD
#define _OPTION_PRICE_GUARD

#include "option.h"
#include "pricing_method.h"

class OptionPrice: public Option, public PricingMethod {
    public:
        char flag;

        OptionPrice(char rhs_flag, double rhs_strike_price, double rhs_current_price, double rhs_rate, double rhs_time_to_maturity, double rhs_volatility);
        
        double Black_Scholes_Option_Price();
        double Binomial_Option_Price();
};

#endif