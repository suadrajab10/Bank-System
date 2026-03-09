#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterListScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include <iomanip>

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOption {eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eShowTransactionsMenue = 6, eManageUsers = 7, eLoginRegister = 8, 
		eCurrencyExchange = 9, eExit = 10};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClient List Screen will be here...\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "\nAdd New Client Screen will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screeen will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		//cout << "\nTransactions Menue will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		//cout << "\nUsers Menue will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	/*static void _ShowEndScreen()
	{
		cout << "\nEnd Screen wil be here...\n";
	}*/

	static void _ShowLogInRegisterList()
	{
		clsLoginRegisterListScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchange()
	{
		clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMainScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//then it will go back to main function.
	}

	static void _PerformMainMenueOption(enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOption::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eLoginRegister:
		{
			system("cls");
			_ShowLogInRegisterList();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchange();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOption::eExit:
		{
			system("cls");
			//_ShowEndScreen();
			_Logout();
			break;
		}
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		
		_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
	}
};

