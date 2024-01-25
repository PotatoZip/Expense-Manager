#include "DataStatistics.h"

using namespace System::Windows::Forms;


void DataStatistics::calculateEarningsAndLosses() {
    totalEarned = 0;
    totalLost = 0;

    std::ifstream file("expenses.txt");

    if (file.is_open()) {
        DataHandler data;

        time_t now = time(0);
        tm* currentDate = localtime(&now);

        int monthNum = currentDate->tm_mon;
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string id, date, name, value;

            std::getline(lineStream, id, ',');
            std::getline(lineStream, date, ',');
            std::getline(lineStream, name, ',');
            std::getline(lineStream, value, ',');

            double doubleValue = std::stod(value);
            data.setAmount(doubleValue);
            

            std::istringstream dateStream(date);

            int day;
            std::string month;
            int year;

            dateStream >> day >> month >> year;

            std::unordered_map<std::string, int> monthMap = {
                {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
                {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
                {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
            };

            int monthNumber = monthMap[month];

            if (monthNumber == monthNum + 1) {
                if (data.getAmount() >= 0) {
                    totalEarned += data.getAmount();
                }
                else {
                    totalLost += data.getAmount();
                }
            }
            
        }
        totalChange = totalEarned + totalLost;

        file.close();
    }
    else {
        std::cerr << "Error: unable to load data from file." << std::endl;
    }
}

void DataStatistics::DisplayAnnouncement() {
    MessageBox::Show("In this section you can loook at your monthly summary!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
