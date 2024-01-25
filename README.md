# Expense Manager

Windows forms application that simulates a virtual wallet into which we can enter information about incomes and expenses. With the help of this app you can perform some basic adding, editing, deleting and showing operations.

## Installation

This project was created in Visual Studio 2022 with the help of .NET framework. In order to run the application first install .NET Framework 4.8 SDK and C++/CLI support for v143 build tools in Visual studio Installer. 

## Usage

Executing our application opens main window in which we can find title, saldo and id information, some basic operations section with buttons, statistics button and big section for adding incomes and expenses.

Saldo and ID:
In this section you can check your current account saldo which should display updated information after adding new income/expense and after deleting/editing data ( in this case you should reload app first).
ID number is the unique value that is assigned to each new addition which helps you editing and deleting data.

Basic operations:
In this section you can select one of three basic operations od wallet data: displaying, editing, deleting. By clicking on the appropriate buttons you should see a newly opened window:
- in the show button you can display all your opperations on the screen or select a specific period in time,
- in the edit button you can enter new data information and save assign it into existing ID number,
- in the delete button you can remove data based on ID number

## Future development

- Make windows responsive,
- Add more account analisys,
- Add more expense/income data info for saving,
- Make better layout

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate. 

## License

This project is licensed under the [MIT](https://choosealicense.com/licenses/mit/) license, feel free to use it.