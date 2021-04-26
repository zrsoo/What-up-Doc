#pragma once
#include <string>

// Base abstract class for BMI and BP...
class Measurement
{
protected:
	std::string date;
public:
	Measurement(std::string _date);
	virtual ~Measurement();

	int getMonth();
	virtual bool isNormalValue() = 0;
	virtual std::string toString() = 0;
};

class BMI : public Measurement
{
private:
	double value;
public:
	BMI(std::string _date, double _value);
	~BMI();

	bool isNormalValue();
	std::string toString();
};

class BP : public Measurement
{
private:
	int systolicValue;
	int diastolicValue;

public:
	BP(std::string _date, int _systolicValue, int _diastolicValue);
	~BP();

	bool isNormalValue();
	std::string toString();
};