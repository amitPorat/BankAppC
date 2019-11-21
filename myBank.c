/*
 * myBank.c
 *
 *  Created on: 21 Nov 2019
 *      Author: amit
 */
#include <stdio.h>
#define number_of_accounts 50
#define FEATURES 2    // stand for account features:  1. balance 2. status (open or not)
#define this_account_number 901
#define OPEN 1 //1 = open account
#define CLOSE 0// 0 = closed account
double bank[number_of_accounts][FEATURES] = { { 0 } };

void open_new_account(double amount) {
	for (int i = 0; i <= number_of_accounts; i++) {
		if (bank[i][1] == CLOSE) {
			bank[i][1] = OPEN;
			bank[i][2] = amount;
			int temp = this_account_number + i;
			printf("the new account successfully opened. It's number is: %d \n",
					temp);
			break;
		}
	}
}

void check_balance(int account_number) {
	account_number -= this_account_number;
	if (bank[account_number][1] == OPEN) {
		printf("Your balance is: %0.2lf \n", bank[account_number][2]);
	} else
		printf("this account number does not exist\n");
}

void deposit(int account_number, double amount) {
	account_number -= this_account_number;
	if (bank[account_number][1] == OPEN) {
		bank[account_number][2] += amount;
		printf("the new balance is: %0.2lf \n", bank[account_number][2]);
	} else
		printf("this account number does not exist\n");

}

void pull_money(int account_number, double amount) {
	account_number -= this_account_number;
	if (bank[account_number][1] == OPEN && bank[account_number][2] >= amount) {
		bank[account_number][2] -= amount;
		printf("the new balance is: %0.2lf\n", bank[account_number][2]);
	} else
		printf(
				"this account number does not exist or you dont have money. Either way check yourself\n");

}

void close_account(int account_number) {
	account_number -= this_account_number;
	if (bank[account_number][1] == OPEN) {
		bank[account_number][1] = CLOSE;
		bank[account_number][2] = CLOSE;
		printf("The account successfully closed\n");
	} else
		printf("this account number does not exist\n");

}

void add_RIBIT(double RIBIT) {
	for (int i = 0; i <= number_of_accounts; i++) {
		if (bank[i][1] == OPEN) {
			double temp = (bank[i][2] * RIBIT / 100);
			bank[i][2] += temp;
			continue;
		} else
			continue;
	}
}

void print_all() {
	for (int i = 0; i <= number_of_accounts; i++) {
		if (bank[i][1] == OPEN) {
			int temp = this_account_number + i;
			printf("account number is : %d\n",  temp);
			printf("the amount  is : %0.2lf\n\n ", bank[i][2]);
			continue;
		} else
			continue;
	}
}
	void close_program() {
		for (int i = 0; i <= number_of_accounts; i++) {
			if (bank[i][1] == OPEN) {
				bank[i][1] = CLOSE;
				bank[i][1] = CLOSE;
			}
		}
	}






