#pragma once

#include <iostream>

/**
 * @brief Szablon klasy konwertuj�ca parametry na tryb int oraz double
 * @param totalIncome - warto�� ��cznego miesi�cznego przychodu
 * @param totalExpense - warto�� ��cznych miesi�cznych wydatk�w
 * @param totalChange - warto�� r�nicy miesi�cznego przychodu i wydatk�w
*/

template<typename T>
class ConvertStatistics {
private:
    T totalIncome;
    T totalExpense;
    T totalChange;

public:

    /**
     * @brief Konstruktor klasy
    */

    ConvertStatistics(T newTotalIncome, T newTotalExpense, T newTotalChange) : totalIncome(newTotalIncome), totalExpense(newTotalExpense), totalChange(newTotalChange) {}

    /**
     * @brief Zwracanie warto�ci totalIncome w formacie int
    */

    int getIntegerIncome() const {
        return static_cast<int>(totalIncome);
    }

    /**
    * @brief Zwracanie warto�ci totalExpense w formacie int
    */

    int getIntegerExpense() const {
        return static_cast<int>(totalExpense);
    }

    /**
     * @brief Zwracanie warto�ci totalChange w formacie int
    */

    int getIntegerChange() const {
        return static_cast<int>(totalChange);
    }

    /**
     * @brief Zwracanie warto�ci totalIncome w formacie double
    */

    double getDoubleIncome() const {
        return static_cast<double>(totalIncome);
    }

    /**
     * @brief Zwracanie warto�ci totalExpense w formacie double
    */

    double getDoubleExpense() const {
        return static_cast<double>(totalExpense);
    }

    /**
     * @brief Zwracanie warto�ci totalChange w formacie double
    */

    double getDoubleChange() const {
        return static_cast<double>(totalChange);
    }
};