#pragma once

#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Klasa zapisuj�ca i wy�wietlaj�ca informacje o stanie salda i aktualnego numberu wpisu
 * @param id - ilo�� dodanych wpis�w
 * @param saldo - aktualny stan konta
*/

class AccountInfo {
private:
	int id;
	double* saldo;
public:

	/**
	 * @brief Konstruktor bezparametryczny
	*/

	AccountInfo();

	/**
	 * @brief Konstruktor parametryczny
	 * @param newId - nowa warto�� Id
	 * @param newSaldo  - nowa warto�� saldo
	*/

	AccountInfo(int newId, double newSaldo);

	/**
	* @brief Destruktor klasy
	*/

	~AccountInfo();

	/**
	 * @brief Getter warto�ci Id
	*/

	int getId() { return id; }

	/**
	 * @brief Getter warto�ci salda
	*/

	double getSaldo() const { return *saldo; }

	/**
	 * @brief Setter warto�ci Id
	 * @param newId - nowa warto�� Id
	*/

	void setId(int newId) { id = newId; }

	/**
	 * @brief Setter warto�ci saldo
	 * @param newSaldo - nowa warto�� saldo
	*/

	void setSaldo(double newSaldo);

	/**
	 * @brief Zapis warto�ci Id do pliku binarnego
	 * @param fileName - �cieszka do pliku bin
	 * @param newId - warto�� do zapisu
	*/

	void saveData(const std::string& fileName, int newId);

	/**
	 * @brief Zapis warto�ci saldo do pliku binarnego
	 * @param fileName - �cieszka do pliku
	 * @param newSaldo - warto�� do zapisu
	 * @param boxValue - warto�� okre�laj�ca jak zmieni�o si� saldo
	*/

	void saveData(const std::string& fileName, double newSaldo, double boxValue);

	/**
	* @brief Odczyt warto�ci Id z pliku binarnego
	* @param filename - scieszka do pliku
	*/

	void loadData(const std::string& fileName);

	/**
	 * @brief Odczyt warto�ci salda z pliku binarnego
	 * @param fileName - �cieszka do pliku
	 * @param isDouble - parametr odr�niaj�cy przeci��one modu�y
	*/

	void loadData(const std::string& fileName, bool isDouble);
};

