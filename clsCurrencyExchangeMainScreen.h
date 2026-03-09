#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsCurreciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeMenueOptions {eListCurrencies = 1, eFindCurrency = 2, 
		eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5};

	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter number between 1 to 5? ");
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen will be here.\n";
		clsCurreciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen will be here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate Screen will be here.\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calaculator Screen will be here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeMainScreen();
	}

	static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
	{
		switch (CurrencyExchangeMenueOption)
		{
		case enCurrencyExchangeMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eMainMenue:
		{
			//do nothing here the main screen wil handle it :-)
		}
		}
	}

public:

	static void ShowCurrencyExchangeMainScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("    Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Mennue\n";
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================================\n";

		_PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
	}
};

