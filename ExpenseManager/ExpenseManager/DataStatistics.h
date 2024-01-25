#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include "DataHandler.h"

/**
 * @brief Klasa dziedziczna od DataHandler obliczaj�ca miesi�czny przych�d, wydatki oraz bilans
 * @param totalEarned - warto�� ��cznego miesi�cznego przychodu
 * @param totalLost - warto�� ��cznych miesi�cznych wydatk�w
 * @param totalChange - r�nica warto�ci ��cznych przychod�w i wydatk�w
*/

class DataStatistics : public DataHandler {
private:
	double totalEarned;
	double totalLost;
	double totalChange;
public:

	/**
	 * @brief Getter warto�ci totalEarned
	*/

	double getTotalEarnings() { return totalEarned; }

	/**
	 * @brief Getter warto�ci totalLost
	*/

	double getTotalLosses() { return totalLost; }

	/**
	 * @brief Getter warto�ci totalChange
	*/

	double getTotalChange() { return totalChange; }

	/**
	 * @brief Analizuje plik z danymi i zlicza przychody oraz wydatki z bie��cego miesi�ca
	*/

	void calculateEarningsAndLosses();

	/**
	 * @brief Wy�wietla okno informacyjne
	*/
	
	void DisplayAnnouncement() override;
};

