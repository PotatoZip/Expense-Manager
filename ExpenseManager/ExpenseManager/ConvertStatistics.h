#pragma once

#include <iostream>

/**
 * @brief Szablon klasy konwertuj¹ca parametry na tryb int oraz double
 * @param totalIncome - wartoœæ ³¹cznego miesiêcznego przychodu
 * @param totalExpense - wartoœæ ³¹cznych miesiêcznych wydatków
 * @param totalChange - wartoœæ ró¿nicy miesiêcznego przychodu i wydatków
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
     * @brief Zwracanie wartoœci totalIncome w formacie int
    */

    int getIntegerIncome() const {
        return static_cast<int>(totalIncome);
    }

    /**
    * @brief Zwracanie wartoœci totalExpense w formacie int
    */

    int getIntegerExpense() const {
        return static_cast<int>(totalExpense);
    }

    /**
     * @brief Zwracanie wartoœci totalChange w formacie int
    */

    int getIntegerChange() const {
        return static_cast<int>(totalChange);
    }

    /**
     * @brief Zwracanie wartoœci totalIncome w formacie double
    */

    double getDoubleIncome() const {
        return static_cast<double>(totalIncome);
    }

    /**
     * @brief Zwracanie wartoœci totalExpense w formacie double
    */

    double getDoubleExpense() const {
        return static_cast<double>(totalExpense);
    }

    /**
     * @brief Zwracanie wartoœci totalChange w formacie double
    */

    double getDoubleChange() const {
        return static_cast<double>(totalChange);
    }
};