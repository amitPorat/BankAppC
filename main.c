/*
 * main.c
 *
 *  Created on: 21 Nov 2019
 *      Author: amit
 */
void display_options();

#include <stdio.h>
#include "myBank.h"

int main(){
	char option;
	double amount = 0.0;
	int acc_counter = 0;
	int acc_number=0;
	int iteratorOn = 1;

	while (iteratorOn){
		printf("welcome to bank account system: \n");
		display_options();
		printf("please enter any option: \n");
		scanf(" %c" , &option);
		switch (option) {

		case 'O':
			if ( acc_counter < 50){
				printf("enter amount: \n");
				scanf("%lf", &amount);
				open_new_account(amount);
				acc_counter ++;
			}
			else {
				printf("bank is full\n");
			}
			break;

		case 'B':
			printf("enter account number: \n");
			scanf("%d", &acc_number);
			if (acc_number < 951 && acc_number >= 900)
				check_balance(acc_number);
			else
				printf("wrong number");
			break;

		case 'D':
			printf("enter amount to deposit: \n");
			scanf("%lf", &amount);
			printf("enter account number: \n");
			scanf("%d", &acc_number);
			if (acc_number < 951 && acc_number >= 900)
				deposit(acc_number,amount);
			else
				printf("wrong number\n");
			break;

		case 'W':
			printf("enter amount to pull: \n");
			scanf("%lf", &amount);
			printf("enter account number: \n");
			scanf("%d", &acc_number);
				if (acc_number < 951 && acc_number >= 900)
					pull_money(acc_number,amount);
				else
					printf("wrong number\n");
			break;

		case 'C':
			printf("enter account number: \n");
			scanf("%d", &acc_number);
			close_account(acc_number);
			acc_counter --;
		break;

		case 'I':
			printf("enter Ribit to add to the accounts: \n");
			scanf("%lf", &amount);
			add_RIBIT(amount);
			break;

		case 'P':
			print_all();
			break;

		case 'E':
			printf("closing program\n");
			iteratorOn = 0;
			close_program();
			acc_counter = 0;
			break;
		default:
			printf("not a valid input\n");
			break;

		}
	}
	return 0;
}


void display_options(){
	printf("\n1. init new account - press O \n");
	//print the new account number, possible iff less then 50 accounts are opened
	//O , amount
	printf("\n2. check balance - press B\n");
	//gets account number and print the balance. allowed iff the account is open
	//B , account_number
	printf("\n3. Deposit - press D\n");
	//gets the account number and print the new! balance. allowed iff the account is open
	//D, account_number, amount
	printf("\n4. pull money from the account - press W\n");
	//gets account number and print the new balance . this method allowed if there is enough money&its opened.
	//W, account_number, amount
	printf("\n5. close account - press C \n");
	//close an account- allowed iff the account was open
	//C, account_number
	printf ("\n6. add RIBIT - press I\n");
	//adds RIBIT to all opened account
	//I,insert_rate
	printf ("\n7. print all the opened accounts and its balanced - press P\n");
	//P
	printf ("\n8. close all the account and exit the program - press E\n");
	//E

}
