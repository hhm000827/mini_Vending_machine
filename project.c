#include <stdio.h>
#include <string.h>

// variable for product information
char name[5][20] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
int amount[5] = {5, 1, 2, 1, 9};
char button[5][5] = {" ", " ", " ", " ", " "};
int price[5] = {10, 9, 5, 8, 7};

char outputdrink[] = "=";
int coin_choice, initialmoney = 0, revenue = 0, coin[4] = {1, 2, 5, 10};

int menuchoice;
int service;

// variable for menuchoice 9
int password;
int access_code[2] = {1110, 001110};

void button_update(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (amount[i] == 0)
		{
			strcpy(button[i], "X");
			continue;
		}

		if (initialmoney < price[i])
			strcpy(button[i], " ");
		else if (initialmoney >= price[i])
			strcpy(button[i], "O");
	}
}

void machine(void)
{
	int i;
	printf("*---------------------------*\n");
	printf("|      Vending Machine      |\n");
	printf("*---------------------------*\n");
	printf("|   A    B    C    D    E   |\n");
	printf("|  ");

	for (i = 0; i < 5; i++)
	{
		if (price[i] >= 10)
			printf("$%d  ", price[i]);
		else
			printf("$ %d  ", price[i]);
	}
	printf("|\n");

	printf("|  [%s]  [%s]  [%s]  [%s]  [%s]  |\n", button[0], button[1], button[2], button[3], button[4]);
	printf("*---------------------------*\n");

	if (initialmoney < 10)
		printf("|                    [$ %d]  |\n", initialmoney);
	else
		printf("|                    [$%d]  |\n", initialmoney);

	printf("|                           |\n");
	printf("|           [=%s=]           |\n", outputdrink);
	printf("*---------------------------*\n");
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

void countmoney(int coin_choice)
{
	int i;
	if (coin_choice > 4)
	{
		printf("Invalid choice!\n");
		printf("\n");
	}
	else if (coin_choice == 0)
	{
		printf("Going back!\n\n");
	}
	else
	{
		for (i = 1; i < 5; i++)
		{
			if (coin_choice == i)
			{
				initialmoney += coin[i - 1];
				printf("You have inserted $%d.\n\n", coin[i - 1]);
			}
		}

		if (coin_choice > 0 && coin_choice < 5)
		{
			button_update();
			machine();
			printf("\n");
		}
	}
}

void product_chosen(int productchoice)
{
	int i;
	char letter[5][5] = {"A", "B", "C", "D", "E"};
	for (i = 1; i <= 5; i++)
	{
		if (productchoice == i)
		{
			printf("You have pressed button %s.\n", letter[i - 1]);
			if (initialmoney >= price[i - 1])
			{
				initialmoney = initialmoney - price[i - 1];
				revenue += price[i - 1];
				amount[i - 1]--;
				strcpy(outputdrink, letter[i - 1]);
				printf("\n");
				button_update();
			}
			else
			{
				strcpy(outputdrink, "=");
				printf("\n");
			}
		}
	}
}

void product_information(void)
{
	char letter[5][5] = {"A", "B", "C", "D", "E"};
	printf("(1) The displayed products are:\n");
	for (int i = 0; i < 5; i++)
		printf("%s. %s ($%d)\n", letter[i], name[i], price[i]);
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

void machine_state(void)
{
	char letter[5][5] = {"A", "B", "C", "D", "E"};
	int i;

	printf("(9-1) Machine status \n");
	printf("Amount of revenue: $%d\n", revenue);
	printf("Amount of inserted coins: $%d\n", initialmoney);
	printf("Product information:\n");

	for (i = 0; i < 5; i++)
	{
		if (amount[i] == 0)
			printf("%s. %s ($%d) (sold out)\n", letter[i], name[i], price[i]);
		else
			printf("%s. %s ($%d) (%d left)\n", letter[i], name[i], price[i], amount[i]);
	}

	printf("\n");
}

void product_refill_table(int product_refill)
{
	char letter[5][5] = {"A", "B", "C", "D", "E"};
	int i;
	for (i = 0; i <= 5; i++)
	{
		if (product_refill == 0 && i == 0)
		{
			printf("Going back!\n");
			printf("\n");
			break;
		}
		else
		{
			if (product_refill == i)
			{
				amount[i - 1] = 10;
				printf("You have refilled product %s to full.\n", letter[i - 1]);
				printf("\n");
				break;
			}
		}
	}
}

void product_change_table(int product_change)
{
	char letter[5][5] = {"A", "B", "C", "D", "E"};
	int i;
	for (i = 1; i <= 5; i++)
	{
		if (product_change == i)
		{
			printf("You are changing product %s.\n\n", letter[i - 1]);
			printf("Enter new product name:");
			scanf("%s", name[i - 1]);
			printf("Enter new product price:");
			scanf("%d", &price[i - 1]);
			printf("The new product %s has been filled to full.\n", letter[i - 1]);
			printf("\n");
			amount[i - 1] = 10;
			break;
		}
	}
}

int main(void)
{
	while (1)
	{
		button_update();
		machine();
		strcpy(outputdrink, "=");
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
			for (int i = 0; i < 5; i++)
				strcpy(button[i], " ");
		}
		else if (menuchoice == 9)
		{
			printf("(9) Opening service menu. Access code is required.\nEnter access code:");
			scanf("%d", &password);

			if (access_code[0] != password && access_code[1] != password)
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
						for (int i = 0; i < 5; i++)
							strcpy(button[i], " ");
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