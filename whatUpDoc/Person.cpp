#include "Person.h"
#include "Measurement.h"
#include <fstream>

Person::Person(std::string _name) : name{_name}
{
}

Person::~Person()
{
	for (auto m : this->measures)
		delete m;
}

std::string Person::getName()
{
	return this->name;
}

void Person::add5Measurements()
{
	Measurement* m1 = new BMI("2021.04.26", 19.6);
	Measurement* m2 = new BMI("2021.05.26", 20.5);
	Measurement* m3 = new BP("2021.05.26", 20, 18);
	Measurement* m4 = new BMI("2021.12.26", 14.9);
	Measurement* m5 = new BP("2021.01.26", 95, 65);

	this->addMeasurement(m1);
	this->addMeasurement(m2);
	this->addMeasurement(m3);
	this->addMeasurement(m4);
	this->addMeasurement(m5);
}

void Person::addMeasurement(Measurement* m)
{
	this->measures.push_back(m);
}

std::vector<Measurement*> Person::getAllMeasurements()
{
	return this->measures;
}

std::vector<Measurement*> Person::getMeasurementsByMonth(int month)
{
	std::vector<Measurement*> measurementsTBR;

	for (auto m : this->measures)
		if (m->getMonth() == month)
			measurementsTBR.push_back(m);

	return measurementsTBR;
}

bool Person::isHealthy(int month)
{
	std::vector<Measurement*> pastMonthMeasures;
	std::vector<Measurement*> monthBeforeMeasures;

	if (month == 1)
	{
		pastMonthMeasures = this->getMeasurementsByMonth(1);

		for (auto m : pastMonthMeasures)
			if (!m->isNormalValue())
				return false;
	}
	else
	{
		pastMonthMeasures = this->getMeasurementsByMonth(month);
		monthBeforeMeasures = this->getMeasurementsByMonth(month - 1);

		for (auto m : pastMonthMeasures)
			if (!m->isNormalValue())
				return false;

		for (auto m : monthBeforeMeasures)
			if (!m->isNormalValue())
				return false;
	}

	return true;
}

std::vector<Measurement*> Person::getMeasurementsNewerThan(std::string date)
{
	std::vector<Measurement*> measuresTBR;

	int month = date[1] - '0' + (date[0] - '0') * 10;

	for (auto m : this->measures)
		if (m->getMonth() > month)
			measuresTBR.push_back(m);

	return measuresTBR;
}

void Person::writeToFile(std::string filename, std::string date)
{
	filename += ".txt";

	std::ofstream fout(filename);

	for (auto m : this->getMeasurementsNewerThan(date))
		fout << m->toString() << '\n';
}
