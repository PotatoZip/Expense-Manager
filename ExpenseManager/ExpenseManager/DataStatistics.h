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
 * @brief Klasa dziedziczna od DataHandler obliczaj¹ca miesiêczny przychód, wydatki oraz bilans
 * @param totalEarned - wartoœæ ³¹cznego miesiêcznego przychodu
 * @param totalLost - wartoœæ ³¹cznych miesiêcznych wydatków
 * @param totalChange - ró¿nica wartoœci ³¹cznych przychodów i wydatków
*/

class DataStatistics : public DataHandler {
private:
	double totalEarned;
	double totalLost;
	double totalChange;
public:

	/**
	 * @brief Getter wartoœci totalEarned
	*/

	double getTotalEarnings() { return totalEarned; }

	/**
	 * @brief Getter wartoœci totalLost
	*/

	double getTotalLosses() { return totalLost; }

	/**
	 * @brief Getter wartoœci totalChange
	*/

	double getTotalChange() { return totalChange; }

	/**
	 * @brief Analizuje plik z danymi i zlicza przychody oraz wydatki z bie¿¹cego miesi¹ca
	*/

	void calculateEarningsAndLosses();

	/**
	 * @brief Wyœwietla okno informacyjne
	*/
	
	void DisplayAnnouncement() override;
};

