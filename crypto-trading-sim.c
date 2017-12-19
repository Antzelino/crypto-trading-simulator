#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	double fee1 = 0.001; // fee for currency1 -> currency2
	double fee2 = 0.001; // fee for currency2 -> currency1

	if (argc > 1){
		sscanf(argv[1], "%lf", &fee1);
		sscanf(argv[2], "%lf", &fee2);
	}
	else {
		printf("You can run %s with 2 floats for the fees. Default is 0.001 (0.1%%)\n\n", argv[0]);
	}

	double fees_mult = (1.0 - fee1) * (1.0 - fee2);

	printf("First currency: ");
	char currency1[20];
	scanf("%s", currency1);

	printf("Second currency: ");
	char currency2[20];
	scanf("%s", currency2);

	printf("\nRate when bought: ");
	double buyrate;
	scanf("%lf", &buyrate);

	double j = buyrate / fees_mult;

	printf("Amount of %s spent to buy %s: ", currency1, currency2);
	double coin1;
	scanf("%lf", &coin1);

	printf("You can profit if you sell at rate \t> %lf (x%.4lf)\n", j, j/buyrate);
	printf("What %% profit do you want: ");
	double percentage_profit;
	scanf("%lf", &percentage_profit);
	printf("For >=%.2lf%% profit you sell at rate  \t>= %lf (x%.4lf)\n\n\n", percentage_profit, buyrate*1.02 / fees_mult, (100.0+percentage_profit)/(100.0*fees_mult));
	while (1) {
		printf("Current rate: ");
		double sellrate;
		scanf("%lf", &sellrate);


		double factor = fees_mult*sellrate / buyrate;
		double coin3 = factor*coin1;
		double profit = coin3 - coin1;
		printf("Profit by factor of %lf\nFrom\t\t%lf%s\nto\t\t%lf%s\nProfit\t\t%lf%s\n\n", factor, coin1, currency1, coin3, currency1, profit, currency1);
	}

	return 0;
}
