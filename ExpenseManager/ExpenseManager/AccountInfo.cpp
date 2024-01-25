#include "AccountInfo.h"

AccountInfo::AccountInfo() : id(0), saldo(nullptr) {}

AccountInfo::AccountInfo(int newId, double newSaldo) : id(newId), saldo(new double(newSaldo)) {}

AccountInfo::~AccountInfo() {
    delete saldo;
}

void AccountInfo::setSaldo(double newSaldo) {
    delete saldo;
    saldo = new double(newSaldo);
}

void AccountInfo::saveData(const std::string& fileName, int newId) {
    std::ofstream file(fileName, std::ios::binary | std::ios::trunc);
    newId++;

    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&newId), sizeof(newId));
        file.close();
    }
    else {
        std::cerr << "Error: unable to save data to file." << std::endl;
    }
}

void AccountInfo::saveData(const std::string& fileName, double newSaldo, double boxValue) {
    std::ofstream file(fileName, std::ios::binary | std::ios::trunc);
    double valueToSave = newSaldo + boxValue;

    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&valueToSave), sizeof(valueToSave));
        file.close();
    }
    else {
        std::cerr << "Error: unable to save data to file." << std::endl;
    }
}

void AccountInfo::loadData(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    int newId;

    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&newId), sizeof(newId));
        setId(newId);
        file.close();
    }
    else {
        std::cerr << "Error: unable to load data from file." << std::endl;
    }
}

void AccountInfo::loadData(const std::string& fileName, bool isDouble) {
    std::ifstream file(fileName);
    double newSaldo;

    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&newSaldo), sizeof(newSaldo));
        setSaldo(newSaldo);
        file.close();
    }
    else {
        std::cerr << "Error: unable to load data from file." << std::endl;
    }
}
