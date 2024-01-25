#pragma once

#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Klasa zapisuj¹ca i wyœwietlaj¹ca informacje o stanie salda i aktualnego numberu wpisu
 * @param id - iloœæ dodanych wpisów
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
	 * @param newId - nowa wartoœæ Id
	 * @param newSaldo  - nowa wartoœæ saldo
	*/

	AccountInfo(int newId, double newSaldo);

	/**
	* @brief Destruktor klasy
	*/

	~AccountInfo();

	/**
	 * @brief Getter wartoœci Id
	*/

	int getId() { return id; }

	/**
	 * @brief Getter wartoœci salda
	*/

	double getSaldo() const { return *saldo; }

	/**
	 * @brief Setter wartoœci Id
	 * @param newId - nowa wartoœæ Id
	*/

	void setId(int newId) { id = newId; }

	/**
	 * @brief Setter wartoœci saldo
	 * @param newSaldo - nowa wartoœæ saldo
	*/

	void setSaldo(double newSaldo);

	/**
	 * @brief Zapis wartoœci Id do pliku binarnego
	 * @param fileName - œcieszka do pliku bin
	 * @param newId - wartoœæ do zapisu
	*/

	void saveData(const std::string& fileName, int newId);

	/**
	 * @brief Zapis wartoœci saldo do pliku binarnego
	 * @param fileName - œcieszka do pliku
	 * @param newSaldo - wartoœæ do zapisu
	 * @param boxValue - wartoœæ okreœlaj¹ca jak zmieni³o siê saldo
	*/

	void saveData(const std::string& fileName, double newSaldo, double boxValue);

	/**
	* @brief Odczyt wartoœci Id z pliku binarnego
	* @param filename - scieszka do pliku
	*/

	void loadData(const std::string& fileName);

	/**
	 * @brief Odczyt wartoœci salda z pliku binarnego
	 * @param fileName - œcieszka do pliku
	 * @param isDouble - parametr odró¿niaj¹cy przeci¹¿one modu³y
	*/

	void loadData(const std::string& fileName, bool isDouble);
};

