#include "Console.h"
#include <iostream>
#include <fstream>

void Console::printMenu()
{
	std::cout << "1. Add a measurement.\n"
		<< "2. Display the list of recorded measurements.\n"
		<< "3. Show if the person is healthy.\n"
		<< "4. Save the measurements into a text file.\n";
}

void Console::runConsole()
{
	std::string command;
	this->p.add5Measurements();

	while (true)
	{
		try
		{ 
			this->printMenu();

			std::cin >> command;

			if (command == "1")
			{
				Measurement* m = nullptr;

				std::string measurementType;
				std::string date;

				std::cout << "Measurement type: ";
				std::cin >> measurementType;
				std::cout << "Measurement date: ";
				std::cin >> date;

				if (measurementType != "BMI" && measurementType != "BP")
					throw(std::exception("Type must be BMI or BP!\n"));
				if (date.size() != 10)
					throw(std::exception("Incorrect date!\n"));

				if (measurementType == "BMI")
				{
					double value;
					std::cout << "BMI value: ";
					std::cin >> value;

					m = new BMI{ date, value };
				}
				else if (measurementType == "BP")
				{
					int systolic, diastolic;
					std::cout << "Systolic value: ";
					std::cin >> systolic;

					std::cout << "Diastolic value: ";
					std::cin >> diastolic;

					m = new BP{ date, systolic, diastolic };
				}

				this->p.addMeasurement(m);

				if (m->isNormalValue())
					std::cout << "The measurement is within normal bounds.\n";
				else
					std::cout << "The measurement is not within normal bounds.\n";
			}
			else if (command == "2")
			{
				std::vector<Measurement*> measures;
				measures = p.getAllMeasurements();

				std::cout << "Name: " << this->p.getName() << '\n';

				for (auto m : measures)
					std::cout << m->toString() << '\n';

				std::cout << '\n';
			}
			else if (command == "3")
			{
				int month;

				std::cout << "Current month: ";
				std::cin >> month;

				if (p.isHealthy(month))
					std::cout << "The person is healthy!\n";
				else
					std::cout << "The person is not healthy!\n";
			}
			else if (command == "4")
			{
				std::string filename;
				std::string date;

				std::cout << "Name of the file: ";
				std::cin >> filename;
				std::cout << "Date: ";
				std::cin >> date;

				filename += ".txt";

				std::ofstream fout(filename);

				for(auto m : p.getMeasurementsNewerThan(date))
					fout << m->toString() << '\n';
			}
		} catch (std::exception e)
		{
			std::cout << e.what();
		}
	}
}
