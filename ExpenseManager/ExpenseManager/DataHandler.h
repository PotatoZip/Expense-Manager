#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
* @brief Klasa przetwarzaj¹ca wpisywane dane
* s³u¿y równie¿ do ich zapisu
* @param id - unikalny identyfikator wpisu
* @param name - nazwa wpisu
* @param date - data dodania wpisu
* @param amount - wartoœæ wpisu
*/

class DataHandler {
private:
	int id;
	std::string name;
	std::string date;
	double amount;

public:

	/**
	* @brief Konstruktor klasy przyjmuj¹ce bazowe wartoœci na 0
	*/

	DataHandler() : id(0), amount(0.0) {}
	
	/**
	* @brief Konstruktor parametryczny klasy
	*/

	DataHandler(int id, const std::string& name, const std::string& date, double amount);

	/**
	* @brief Getter identyfikatora
	*/

	int getId() { return id; }

	/**
	* @brief Getter nazwy
	*/

	std::string getName() { return name; }

	/**
	* @brief Getter daty
	*/

	std::string getDate() { return date; }

	/**
	* @brief Getter wartoœci
	*/

	double getAmount() { return amount; }
	
	/**
	* @brief Setter identyfikatora
	*/

	void setId(int newId) { id = newId; }

	/**
	* @brief Setter nazwy
	*/

	void setName(const std::string newName) { name = newName; }

	/**
	* @brief Setter daty
	*/

	void setDate(const std::string newDate) { date = newDate; }

	/**
	* @brief Setter wartoœci
	*/

	void setAmount(double newAmount) { amount = newAmount; }
	
	/**
	* @brief Zapis obiektów klasy do pliku txt
	* @param fileName - œcieszka do pliku
	*/

	void saveDate(const std::string& fileName);

	/**
	* @brief Odczyt obiektów klasy z pliku txt
	* @param fileName - œcieszka do pliku
	*/

	void loadDate(const std::string& fileName);

	/**
	* @brief Przeci¹¿ony operator <<
	* @param os - strumieñ wyjœciowy
	* @param data - obiekt ¿utowany na strumieñ
	*/

	friend std::ostream& operator<<(std::ostream& os, const DataHandler& data);

	/**
	* @brief Przeci¹¿ony operator >>
	* @param is - strumieñ wejœciowy
	* @param data - obiekt ¿utowany na strumieñ
	*/

	friend std::istream& operator>>(std::istream& is, DataHandler& data);

	/**
	 * @brief Funckja wirtualna wyœwietlaj¹ca kkomunikat z informacj¹
	*/

	virtual void DisplayAnnouncement();
};

