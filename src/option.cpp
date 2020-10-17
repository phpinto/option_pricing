#include "option.h"
#include "option_class.cpp"
#include "pricing_method.h"
#include "option_price.h"
#include "option_price_class.cpp"

using namespace std;

// Currency string helper class found at https://stackoverflow.com/questions/22104371/currency-format-using-double-values
class currency_string: public numpunct<char>
{
    char do_decimal_point() const { return '.'; }
    char do_thousands_sep() const { return ','; }
    string do_grouping() const { return "\03"; }
};


int main()
{
    double strike_price, current_price, rate, time_to_maturity, volatility;
    string flag_input;
    char flag;

    cout << endl << "Welcome to the ISYE 6767 Option Pricing Machine:" << endl;

    while (true) {
        cout << endl << "Insert the parameters for your option: " << endl;

        cout << endl << "Insert the current price of the underlying asset in US $: ";
        while(!(cin >> current_price)){
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << "Please insert a numeric current price: ";
	    }

        cout << "Insert the strike price in US $: ";
        while(!(cin >> strike_price)){
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << "Please insert a numeric strike price: ";
	    }
    
        cout << "Insert the time to maturity in years: ";
        while(!(cin >> time_to_maturity)){
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << "Please insert a numeric time to maturity (in years): ";
	    }
    
        cout << "Insert the risk free rate (as a decimal number): ";
        while(!(cin >> rate)){
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << "Please insert a numeric risk free rate: ";
	    }
    
        cout << "Insert Volatility parameter of the asset price model (sigma): ";
        while(!(cin >> volatility)){
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cout << "Please insert a numeric volatility (sigma): ";
	    }
    
        cout << "Choose the option type: Call (C) or Put (P): ";
    
        while(true){
            if (!(cin >> flag_input)) {
                cin.clear();
	    	    cout << "Please insert a valid option type (C for Call and P Put): ";
            }
            else {
                flag = tolower(flag_input[0]);
                if (flag != 'c' && flag != 'p') {
	    	        cin.clear();
	    	        cout << "Please insert a valid option type (C for Call and P Put): ";
	            }
                else break;
            }
	    }
    
        OptionPrice option_price = OptionPrice(flag, strike_price, current_price, rate, time_to_maturity, volatility);
    
        cout << endl << "Estimated Option Price:" << endl << endl;
    
        cout.imbue(locale(cout.getloc(), new currency_string));
        cout << fixed << setprecision(2);
        cout << "Black-Scholes Model: $ " << option_price.Black_Scholes_Option_Price() << endl;
        cout << "Binomial Model: $ " << option_price.Binomial_Option_Price() << endl;
    }
    
    return 0;
}