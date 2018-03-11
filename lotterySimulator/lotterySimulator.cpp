// lotterySimulator
// author: Krzysztof Gruca

/* Pseudocode:

   Import ctime and cstdlib for random number generation.

   Create two array: a one-dimensional to hold the winning numbers 
   and a multidimensional to hold the numbers chosen by user on
   each of the stubs they buy (user defines how many stubs they 
   wish to purchase).

   For loop 
   {
      - Generate the random winning number (with value from 1 - 70).
      - Nested for loop will check whether each chosen number is unique compared to
        previous numbers.
	}

	Generate random number for the 6th winnining number (between 1 - 25).

   Ask user how many stubs they wish to purchase; this will equal the number of rows
   in the multidimensional array.

   For each stub, ask user whether they would like to fill it out 
   themselves or take advantage of the quickplay option.
   {
	  - While loop as choice validation.

	  - If user wants to fill stub out manually:
	  {
	     - For loop to get user input to get each of the first 5 nums.
		 - While loop to make sure the numbers are within appropriate range (1 - 70).
		 - Nested for loop will check whether each chosen number is unique compared to
           previous numbers.

		 - Ask for 6th number
		 - While loop to make sure the number is within appropriate range (1 - 25).
	  }	 
	  - Else user chooses quickplay for the stub:   
	  {
	     - For loop 
         {
            - Generate the first 5 random numbers (with value from 1 - 70).
            - Nested for loop will check whether each chosen number is unique compared to
              previous numbers.
	     }

	     - Generate random number for the 6th choice (value between 1 - 25).
	  }

   Compare each of the user's stubs with the winning numbers.

   Display the winning numbers.

   Display results. If user got any numbers correct on any of the stubs then display the stub 
   number, the chosen numbers, and amount of correct choices, along with the winnings for the 
   stub.

   Display the total winnings.

   End.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

const int NUMELEMS = 6;

int main() {
	int winningNumbers[NUMELEMS];
	int numStubs;
	int stubsChoice;
	unsigned seed = time(0);
	
	srand(seed);

	for (int i = 0; i < 5; i++) {
		winningNumbers[i] = 1 + rand() % 70;
		for (int j = 0; j < i; j++) {
			while (winningNumbers[i] == winningNumbers[j]) {
				winningNumbers[i] = 1 + rand() % 70;
			}
		}
	}
	winningNumbers[NUMELEMS - 1] = 1 + rand() % 25;

	

	std::cout << "How many stubs do you wish to purchase? Please note that we carrry a maximum of 100 stubs: ";
	std::cin >> numStubs;
	int playerStubs[100][NUMELEMS];

	for (int m = 0; m < numStubs; m++) {
		std::cout << "Would like you like to fill this stub by hand, or use the quickplay option? ";
		std::cout << "Please choose 1 if by hand, or 2 if by quickplay: ";
		std::cin >> stubsChoice;

		while (stubsChoice != 1 && stubsChoice != 2) {
			std::cout << "Please make a valid selection: ";
			std::cin >> stubsChoice;
		}

		if (stubsChoice == 1) {
			for (int n = 0; n < numStubs; n++) {
				for (int o = 0; o < 5; o++) {
					std::cout << "Please choose number " << o + 1 << ": ";
					std::cin >> playerStubs[n][o];
				}
				std::cout << "Now choose between 1 - 25 for the final Mega Millions number: ";
				std::cin >> playerStubs[n][5];
				
			}
		}

		for (int k = 0; k < numStubs; k++) {
			for (int p = 0; p < NUMELEMS; p++) {
				std::cout << playerStubs[k][p] << " ";
			}
			std::cout << std::endl;
		}

	}

	system("pause");
	return 0;
}
