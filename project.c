#include <stdio.h>
#include <string.h>

char A[20] = "Juice", B[20] = "Cola", C[20] = "Tea", D[20] = "Water", E[20] = "Coffee";
char new_A[20], new_B[20], new_C[20], new_D[20], new_E[20];
int amount[5] = {5, 1, 2, 1, 9};
char abutton = ' ', bbutton = ' ', cbutton = ' ', dbutton = ' ', ebutton = ' ';
char outputdrink = '=';
int coin_choice, initialmoney = 0, revenue = 0, coin[4] = {1, 2, 5, 10};
int Aprice = 10, Bprice = 6, Cprice = 5, Dprice = 8, Eprice = 7;
int menuchoice;
int service;

// variable for menuchoice 9
int password;
int access_code1 = 1110;
int access_code2 = 001110;

void button_update(void)
{
	if (initialmoney < Aprice)
	{
		abutton = ' ';
	}
	if (initialmoney < Bprice)
	{
		bbutton = ' ';
	}
	if (initialmoney < Cprice)
	{
		cbutton = ' ';
	}
	if (initialmoney < Dprice)
	{
		dbutton = ' ';
	}
	if (initialmoney < Eprice)
	{
		ebutton = ' ';
	}

	if (initialmoney >= Aprice)
	{
		abutton = 'O';
	}
	if (initialmoney >= Bprice)
	{
		bbutton = 'O';
	}
	if (initialmoney >= Cprice)
	{
		cbutton = 'O';
	}
	if (initialmoney >= Dprice)
	{
		dbutton = 'O';
	}
	if (initialmoney >= Eprice)
	{
		ebutton = 'O';
	}

	if (amount[0] == 0)
	{
		abutton = 'X';
	}
	if (amount[1] == 0)
	{
		bbutton = 'X';
	}
	if (amount[2] == 0)
	{
		cbutton = 'X';
	}
	if (amount[3] == 0)
	{
		dbutton = 'X';
	}
	if (amount[4] == 0)
	{
		ebutton = 'X';
	}
}

int machine(void)
{
	printf("*---------------------------*\n");
	printf("|      Vending Machine      |\n");
	printf("*---------------------------*\n");
	printf("|   A    B    C    D    E   |\n");
	printf("|  ");

	if (Aprice >= 10)
		printf("$%d  ", Aprice);
	else
		printf("$ %d  ", Aprice);

	if (Bprice >= 10)
		printf("$%d  ", Bprice);
	else
		printf("$ %d  ", Bprice);

	if (Cprice >= 10)
		printf("$%d  ", Cprice);
	else
		printf("$ %d  ", Cprice);

	if (Dprice >= 10)
		printf("$%d  ", Dprice);
	else
		printf("$ %d  ", Dprice);

	if (Eprice >= 10)
		printf("$%d ", Eprice);
	else
		printf("$ %d ", Eprice);

	if (Aprice >= 10 || Bprice >= 10 || Cprice >= 10 || Dprice >= 10 || Eprice >= 10)
	{
		printf(" |\n");
	}
	else if (Aprice < 10 && Bprice < 10 && Cprice < 10 && Dprice < 10 && Eprice < 10)
	{
		printf(" |\n");
	}

	else if (
		(Aprice >= 10 && Bprice >= 10) || (Aprice >= 10 && Cprice >= 10) ||
		(Aprice >= 10 && Dprice >= 10) || (Aprice >= 10 && Eprice >= 10) ||
		(Bprice >= 10 && Cprice >= 10) || (Bprice >= 10 && Dprice >= 10) ||
		(Bprice >= 10 && Eprice >= 10) || (Cprice >= 10 && Dprice >= 10) ||
		(Cprice >= 10 && Eprice >= 10) || (Dprice >= 10 && Eprice >= 10))
	{
		printf("|\n");
	}

	printf(
		"|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", abutton, bbutton, cbutton, dbutton, ebutton);
	printf("*---------------------------*\n");

	if (initialmoney < 10)
	{
		printf("|                    [$ %d]  |\n", initialmoney);
	}

	else
	{
		printf("|                    [$%d]  |\n", initialmoney);
	}

	printf("|                           |\n");
	printf("|           [=%c=]           |\n", outputdrink);
	printf("*---------------------------*\n");
	return 0;
}

void menu(void)
{
	printf("What would you like to do?\n");
	printf("1. Read product information\n");
	printf("2. Insert coin\n");
	printf("3. Press product button\n");
	printf("4. Press return button\n");
	printf("9. Open service menu (code required)\n");
	printf("0. Quit");
}

void coin_menu(void)
{
	printf("(2) Which coin would you like to insert?\n");
	printf("1. $1\n");
	printf("2. $2\n");
	printf("3. $5\n");
	printf("4. $10\n");
	printf("0. Go back\n");
}

int countmoney(int coin_choice)
{
	if (coin_choice > 4)
	{
		printf("Invalid choice!\n");
		printf("\n");
	}
	else
	{
		if (coin_choice == 1)
		{
			initialmoney = initialmoney + coin[0];
			printf("You have inserted $1.\n");
			printf("\n");
		}
		else if (coin_choice == 2)
		{
			initialmoney = initialmoney + coin[1];
			printf("You have inserted $2.\n");
			printf("\n");
		}
		else if (coin_choice == 3)
		{
			initialmoney = initialmoney + coin[2];
			printf("You have inserted $5.\n");
			printf("\n");
		}
		else if (coin_choice == 4)
		{
			initialmoney = initialmoney + coin[3];
			printf("You have inserted $10.\n");
			printf("\n");
		}
		else if (coin_choice == 0)
		{
			printf("Going back!\n");
			printf("\n");
		}
		if (coin_choice > 0 && coin_choice < 5)
		{
			button_update();
			machine();
			printf("\n");
		}
		return 0;
	}
}

int product_chosen(int productchoice)
{
	if (productchoice == 1)
	{
		printf("You have pressed button A.\n");
		if (initialmoney >= Aprice)
		{
			initialmoney = initialmoney - Aprice;
			revenue += Aprice;
			amount[0]--;
			outputdrink = 'A';
			printf("\n");
			button_update();
		}
		else
		{
			outputdrink = '=';
			printf("\n");
		}
	}

	if (productchoice == 2)
	{
		printf("You have pressed button B.\n");
		if (initialmoney >= Bprice)
		{
			initialmoney = initialmoney - Bprice;
			revenue += Bprice;
			amount[1]--;
			outputdrink = 'B';
			printf("\n");
			button_update();
		}
		else
		{
			outputdrink = '=';
			printf("\n");
		}
	}

	if (productchoice == 3)
	{
		printf("You have pressed button C.\n");
		if (initialmoney >= Cprice)
		{
			initialmoney = initialmoney - Cprice;
			revenue += Cprice;
			amount[2]--;
			outputdrink = 'C';
			printf("\n");
			button_update();
		}
		else
		{
			outputdrink = '=';
			printf("\n");
		}
	}

	if (productchoice == 4)
	{
		printf("You have pressed button D.\n");
		if (initialmoney > Dprice)
		{
			initialmoney = initialmoney - Dprice;
			revenue += Dprice;
			amount[3]--;
			outputdrink = 'D';
			printf("\n");
			button_update();
		}
		else
		{
			outputdrink = '=';
			printf("\n");
		}
	}

	if (productchoice == 5)
	{
		printf("You have pressed button E.\n");
		if (initialmoney >= Eprice)
		{
			initialmoney = initialmoney - Eprice;
			revenue += Eprice;
			amount[4]--;
			outputdrink = 'E';
			printf("\n");
			button_update();
		}
		else
		{
			outputdrink = '=';
			printf("\n");
		}
	}
	return 0;
}

int product_information(void)
{
	printf("(1) The displayed products are:\n");
	printf("A. %s ($%d)\n", A, Aprice);
	printf("B. %s ($%d)\n", B, Bprice);
	printf("C. %s ($%d)\n", C, Cprice);
	printf("D. %s ($%d)\n", D, Dprice);
	printf("E. %s ($%d)\n", E, Eprice);
	return 0;
}

void service_menu(void)
{
	printf("(9) What would you like to do?\n");
	printf("1. Inspect machine status\n");
	printf("2. Withdraw all money\n");
	printf("3. Refill product\n");
	printf("4. Change product\n");
	printf("0. Go back\n");
	printf("Your choice:");
}

int machine_state(void)
{
	printf("(9-1) Machine status \n");
	printf("Amount of revenue: $%d\n", revenue);
	printf("Amount of inserted coins: $%d\n", initialmoney);
	printf("Product information:\n");

	if (amount[0] == 0)
	{
		printf("A. %s ($%d) (sold out)\n", A, Aprice);
	}
	else
	{
		printf("A. %s ($%d) (%d left)\n", A, Aprice, amount[0]);
	}

	if (amount[1] == 0)
	{
		printf("B. %s ($%d) (sold out)\n", B, Bprice);
	}
	else
	{
		printf("B. %s ($%d) (%d left)\n", B, Bprice, amount[1]);
	}

	if (amount[2] == 0)
	{
		printf("C. %s ($%d) (sold out)\n", C, Cprice);
	}
	else
	{
		printf("C. %s ($%d) (%d left)\n", C, Cprice, amount[2]);
	}

	if (amount[3] == 0)
	{
		printf("D. %s ($%d) (sold out)\n", D, Dprice);
	}
	else
	{
		printf("D. %s ($%d) (%d left)\n", D, Dprice, amount[3]);
	}

	if (amount[4] == 0)
	{
		printf("E. %s ($%d) (sold out)\n", E, Eprice);
	}
	else
	{
		printf("E. %s ($%d) (%d left)\n", E, Eprice, amount[4]);
	}

	printf("\n");
	return 0;
}

int product_refill_table(int product_refill)
{
	if (product_refill == 1)
	{
		amount[0] = 10;
		printf("You have refilled product A to full.\n");
		printf("\n");
	}

	if (product_refill == 2)
	{
		amount[1] = 10;
		printf("You have refilled product B to full.\n");
		printf("\n");
	}

	if (product_refill == 3)
	{
		amount[2] = 10;
		printf("You have refilled product C to full.\n");
		printf("\n");
	}

	if (product_refill == 4)
	{
		amount[3] = 10;
		printf("You have refilled product D to full.\n");
		printf("\n");
	}

	if (product_refill == 5)
	{
		amount[4] = 10;
		printf("You have refilled product E to full.\n");
		printf("\n");
	}

	if (product_refill == 0)
	{
		printf("Going back!\n");
		printf("\n");
	}
	return 0;
}

int product_change_table(int product_change)
{
	if (product_change == 1)
	{
		printf("You are changing product A.\n\n");
		printf("Enter new product name:");
		scanf("%s", new_A);
		strcpy(A, new_A);
		printf("Enter new product price:");
		scanf("%d", &Aprice);
		printf("The new product A has been filled to full.\n");
		printf("\n");
		amount[0] = 10;
	}

	if (product_change == 2)
	{
		printf("You are changing product B.\n\n");
		printf("Enter new product name:");
		scanf("%s", new_B);
		strcpy(B, new_B);
		printf("Enter new product price:");
		scanf("%d", &Bprice);
		printf("The new product B has been filled to full.\n");
		printf("\n");
		amount[1] = 10;
	}

	if (product_change == 3)
	{
		printf("You are changing product C.\n\n");
		printf("Enter new product name:");
		scanf("%s", new_C);
		strcpy(C, new_C);
		printf("Enter new product price:");
		scanf("%d", &Cprice);
		printf("The new product C has been filled to full.\n");
		printf("\n");
		amount[2] = 10;
	}

	if (product_change == 4)
	{
		printf("You are changing product D.\n\n");
		printf("Enter new product name:");
		scanf("%s", new_D);
		strcpy(D, new_D);
		printf("Enter new product price:");
		scanf("%d", &Dprice);
		printf("The new product D has been filled to full.\n");
		printf("\n");
		amount[3] = 10;
	}

	if (product_change == 5)
	{
		printf("You are changing product E.\n\n");
		printf("Enter new product name:");
		scanf("%s", new_E);
		strcpy(E, new_E);
		printf("Enter new product price:");
		scanf("%d", &Eprice);
		printf("The new product E has been filled to full.\n");
		printf("\n");
		amount[4] = 10;
	}
	return 0;
}

int main(void)
{
	while (1)
	{
		button_update();
		machine();
		outputdrink = '=';
		printf("\n");
		menu();
		printf("\nYour choice:");
		scanf("%d", &menuchoice);
		printf("\n");
		if ((menuchoice > 4 && menuchoice < 9) || menuchoice > 9 || menuchoice < 0)
		{
			printf("Invalid choice!\n\n");
			menu();
			printf("\nYour choice:");
			scanf("%d", &menuchoice);
		}
		else if (menuchoice == 0)
			break;
		else if (menuchoice == 1)
		{
			product_information();
			printf("\n");
		}
		else if (menuchoice == 2)
		{
			while (1)
			{
				coin_menu();
				printf("Your choice:");
				scanf("%d", &coin_choice);
				countmoney(coin_choice);
				if (coin_choice == 0)
				{
					break;
				}
			}
		}
		else if (menuchoice == 3)
		{
			int productchoice;
			while (1)
			{
				printf("(3) Which product button would you like to press?");
				printf("\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
				printf("Your choice:");
				scanf("%d", &productchoice);

				if (productchoice > 5 || productchoice < 0)
					printf("Invalid choice!\n\n");
				else
					break;
			}
			product_chosen(productchoice);
			if (productchoice == 0)
				printf("Going back!\n\n");
		}
		else if (menuchoice == 4)
		{
			printf("(4) Return button is pressed.\n");
			printf("$%d has been returned.\n\n", initialmoney);
			initialmoney = 0;
			abutton = bbutton = cbutton = dbutton = ebutton = ' ';
		}
		else if (menuchoice == 9)
		{
			printf("(9) Opening service menu. Access code is required.\nEnter access code:");
			scanf("%d", &password);

			if (access_code1 != password && access_code2 != password)
				printf("Incorrect code!\n\n");
			else
			{
				printf("Correct code!\n\n");

				while (1)
				{
					service_menu();
					scanf("%d", &service);

					if (service == 0)
					{
						printf("Going back!\n\n");
						break;
					}
					else if (service == 1)
					{
						printf("\n");
						machine_state();
					}
					else if (service == 2)
					{
						printf("\n(9-2) All money is being withdrawn.\n ");
						printf("$%d is withdrawn.\n", (initialmoney + revenue));
						initialmoney = 0;
						revenue = 0;
						abutton = bbutton = cbutton = dbutton = ebutton = ' ';
						printf("\n");
					}
					else if (service == 3)
					{
						int product_refill;
						while (1)
						{
							printf("\n(9-3) Which product would you like to refill?");
							printf("\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
							printf("Your choice:");
							scanf("%d", &product_refill);

							if (product_refill > 5)
							{
								printf("Invalid choice!\n\n");
							}
							else
								break;
						}
						product_refill_table(product_refill);
					}
					else if (service == 4)
					{
						int product_change;
						while (1)
						{
							printf("\n(9-4) Which product would you like to change?");
							printf("\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
							printf("Your choice:");
							scanf("%d", &product_change);

							if (product_change > 5 || product_change < 0)
							{
								printf("Invalid choice!\n");
							}
							else if (product_change == 0)
							{
								printf("Going back!\n\n");
								break;
							}
							else
							{
								product_change_table(product_change);
								break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}