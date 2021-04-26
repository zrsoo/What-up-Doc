#pragma once
#include <vector>
#include <string>
#include "Measurement.h"

class Person
{
private:
	std::string name;
	std::vector<Measurement*> measures;

public:
	Person(std::string _name);
	~Person();

	std::string getName();
	void add5Measurements();
	void addMeasurement(Measurement* m);
	std::vector<Measurement*> getAllMeasurements();
	std::vector<Measurement*> getMeasurementsByMonth(int month);
	bool isHealthy(int month);
	std::vector<Measurement*> getMeasurementsNewerThan(std::string date);
	void writeToFile(std::string filename, std::string date);
};