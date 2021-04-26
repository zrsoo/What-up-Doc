#include "Measurement.h"
#include <sstream>

Measurement::Measurement(std::string _date) : date{_date}
{
}

Measurement::~Measurement()
{
}

int Measurement::getMonth()
{
	int month;
	month = this->date[6] - '0' + (this->date[5] - '0') * 10;

	return month;
}

BMI::BMI(std::string _date, double _value) : Measurement{ _date }, value{ _value }
{
}

BMI::~BMI()
{
}

bool BMI::isNormalValue()
{
	return(this->value >= 18.5 && this->value <= 25);
}

std::string BMI::toString()
{
	std::stringstream buffer;
	buffer << "Type: BMI" << "	Date: " << this->date << "	Value: " << this->value;

	return buffer.str();
}

BP::BP(std::string _date, int _systolicValue, int _diastolicValue) : Measurement{_date}, systolicValue{_systolicValue}, diastolicValue{_diastolicValue}
{
}

BP::~BP()
{
}

bool BP::isNormalValue()
{
	return(this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79);
}

std::string BP::toString()
{
	std::stringstream buffer;
	buffer << "Type: BP" << "	Date: " << this->date << "	Systolic value: " << this->systolicValue << "	Diastolic value: " << this->diastolicValue;

	return buffer.str();
}
