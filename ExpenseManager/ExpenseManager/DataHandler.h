#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
* @brief Klasa przetwarzaj�ca wpisywane dane
* s�u�y r�wnie� do ich zapisu
* @param id - unikalny identyfikator wpisu
* @param name - nazwa wpisu
* @param date - data dodania wpisu
* @param amount - warto�� wpisu
*/

class DataHandler {
private:
	int id;
	std::string name;
	std::string date;
	double amount;

public:

	/**
	* @brief Konstruktor klasy przyjmuj�ce bazowe warto�ci na 0
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
	* @brief Getter warto�ci
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
	* @brief Setter warto�ci
	*/

	void setAmount(double newAmount) { amount = newAmount; }
	
	/**
	* @brief Zapis obiekt�w klasy do pliku txt
	* @param fileName - �cieszka do pliku
	*/

	void saveDate(const std::string& fileName);

	/**
	* @brief Odczyt obiekt�w klasy z pliku txt
	* @param fileName - �cieszka do pliku
	*/

	void loadDate(const std::string& fileName);

	/**
	* @brief Przeci��ony operator <<
	* @param os - strumie� wyj�ciowy
	* @param data - obiekt �utowany na strumie�
	*/

	friend std::ostream& operator<<(std::ostream& os, const DataHandler& data);

	/**
	* @brief Przeci��ony operator >>
	* @param is - strumie� wej�ciowy
	* @param data - obiekt �utowany na strumie�
	*/

	friend std::istream& operator>>(std::istream& is, DataHandler& data);

	/**
	 * @brief Funckja wirtualna wy�wietlaj�ca kkomunikat z informacj�
	*/

	virtual void DisplayAnnouncement();
};

