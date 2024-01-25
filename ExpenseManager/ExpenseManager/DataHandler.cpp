#include "DataHandler.h"

using namespace System::Windows::Forms;

DataHandler::DataHandler(int id, const std::string& name, const std::string& date, double amount)
	: id(id), name(name), date(date), amount(amount) {}

void DataHandler::saveDate(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    std::ostringstream existingData;

    if (inputFile.is_open()) {
        existingData << inputFile.rdbuf();
        inputFile.close();
    }
    
    std::ofstream file(fileName, std::ios::trunc);

    if (file.is_open()) {
        file << id << "," << date << "," << name << "," << amount << '\n';
        file << existingData.str();
        file.close();
    }
    else {
        std::cerr << "Error: unable to save data to file." << std::endl;
    }
}

void DataHandler::loadDate(const std::string& fileName) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        DataHandler data;

        while (file >> data) {
            std::cout << data << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Error: unable to load data from file." << std::endl;
    }
}

void DataHandler::DisplayAnnouncement() {
    MessageBox::Show("In this section you can loook for some usefull info!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

std::ostream& operator<<(std::ostream& os, const DataHandler& data) {
    os << data.id << "," << data.date << "," << data.name << "," << data.amount;
    return os;
}

std::istream& operator>>(std::istream& is, DataHandler& data) {
    char comma;
    is >> data.id >> comma >> data.date >> comma >> data.name >> comma >> data.amount;
    return is;
}
