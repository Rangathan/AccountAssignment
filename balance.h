#pragma once
#include <string>
#include <iostream>

typedef  long long  int64_t;

class DollarAmount {

public:
	// constructor
	DollarAmount(int64_t value = 0)
	{
		amount = value;
	}

	void add(DollarAmount val)
	{
		amount += val.amount;
	}

	//TODO
	void add(unsigned int dollar, unsigned int cents)
	{
		amount += (static_cast<long long>(dollar) * 100) + cents;
	}
	void subtract(DollarAmount val)
	{
		amount -= val.amount;
	}
	//TODO
	void subtract(unsigned int dollar, unsigned int cents)
	{
		amount -= (static_cast<long long>(dollar) * 100) + cents;
	}

	// returns a string representing the dollar amount of this object
	std::string toString() const
	{
		std::string dollarStr = std::to_string(amount / 100);  // to_string does this: 19  --> "19"
		std::string centStr = std::to_string(amount % 100);     // 220 cents -----> 2 dollars and 20 cents
		return dollarStr + "." + (centStr.size() == 1 ? "0" : "") + centStr;
	}

	/*
	*  (centStr.size() == 1 ? "0" : "") is the same as following:
	* if(centStr.size() == 1)
	*	"0"
	* else
	*    ""
	*
	*/
	/* add interest using int rate. It means for example for rate of
	* 2.345 % we should call addInterest(2345, 1000), and for 2.45 % we call addInterest(245, 100)
	*/
	void addInterest(long double rate, int divisor)
	{
		//added round it
		// Had to change the formaula as it would give the interest in thousands not the proper 
		// first compute the interest. Then add the interest to mount
		DollarAmount interest(round((amount * rate + divisor / 2) / (divisor * 100)));
		add(interest);  // amount = amount + interest.amount
	}

private:
	int64_t amount;   // max bit integer. This is the balance on an account. It is in pennies.

};
