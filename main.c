#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char stat[256];
	char i = 0;
	float operand1, operand2, out;

	while (1) 
	{
		printf("\nselect which sabr metric to calculate\n");
		printf("available choices are: \n");
		printf("exit by typing 'done'\n");

		fgets(stat, sizeof(stat), stdin);
		printf("You input: %s\n", stat);
		printf("calculating...");

		while ((getchar()) != '\n');
		switch (char) 
		{
			case 'h9':
				printf("Input a pitcher's hits allowed\n");
				scanf("%f", &operand1);
		  		printf("Input the same pitcher's innings pitched");
				scanf("%f", &operand2);
				out = (operand1 / operand2) * 9;
				printf("This pitcher's H/9 is: %f\n", out);
				break;
		}

		break;

		exit(0);
	}

	return 0;
}
