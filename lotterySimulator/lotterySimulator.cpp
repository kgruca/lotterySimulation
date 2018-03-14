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

   Display results. Display the total winnings.

   End.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

const int NUMELEMS = 6;
const int FINALNUM = 5;

void timeSeed();
void lotteryNumbersPick(int[], int);
void intro();
int numberOfStubs();
int fillOutChoice();
void stubsChoiceValidation(int);
void numberChoiceValidation(int [][NUMELEMS], int, int);
void finalNumValidation(int [][NUMELEMS], int, int);
void numberChoiceChosen(int[][NUMELEMS], int, int);
void playerSelfPick(int[][NUMELEMS], int);
void quickplayPick(int[][NUMELEMS], int);
void playerAllChoices(int[][NUMELEMS], int);
void displayWinningNums(int [], int);
int displayPlayerNums(int[][NUMELEMS], int[], int, int);
bool finalNumEqual(int[][NUMELEMS], int[], int);
int totalCalculator(int, bool);
void totalWinnings(int); 


int main() {
	int winningNumbers[NUMELEMS];
	int playerStubs[100][NUMELEMS];
	int numStubs;
	int stubNumber;
	int numberChoice;
	int counter = 0;
	int finalCounter;
	int total;
	bool finalNumber;
	
	timeSeed();

	lotteryNumbersPick(winningNumbers, NUMELEMS);
	
	intro();

	numStubs = numberOfStubs();

	playerAllChoices(playerStubs, numStubs);

	displayWinningNums(winningNumbers, NUMELEMS);

	for (stubNumber = 0; stubNumber < numStubs; stubNumber++) {
		
		finalCounter = displayPlayerNums(playerStubs, winningNumbers, stubNumber, counter);

		finalNumber = finalNumEqual(playerStubs, winningNumbers, stubNumber);

		total = totalCalculator(finalCounter, finalNumber);
	}

	totalWinnings(total);

	system("pause");
	return 0;
}

void timeSeed() {
	unsigned seed = time(0);
	srand(seed);
}

void lotteryNumbersPick(int arr[], int elems) {
	for (int numberChoice = 0; numberChoice < elems - 1; numberChoice++) {
		arr[numberChoice] = 1 + rand() % 70;
		for (int count = 0; count < numberChoice; count++) {
			if (arr[count] == arr[numberChoice]) {
				arr[numberChoice] = 1 + rand() % 70;
			}
		}
	}
	arr[FINALNUM] = 1 + rand() % 25;
}

void intro() {
	std::cout << "\tWelcome to this Mega Millions simulator! I have generated winning" << std::endl;
	std::cout << "\tlottery numbers, and now it's up to you to win! The grand prize" << std::endl;
	std::cout << "\tis a whopping $1,000,000,000! Please bear in mind that the first" << std::endl;
	std::cout << "\tfive numbers you choose must be between 1 - 70 and cannot repeat," << std::endl;
	std::cout << "\twhile the last number must be between 1 - 25." << std::endl << std::endl;
}

int numberOfStubs() {
	int num;

	std::cout << "\tHow many stubs do you wish to purchase? Please note that we carry" << std::endl;
	std::cout << "\ta maximum of 100 stubs: ";
	std::cin >> num;

	std::cout << std::endl << std::endl;

	return num;
}

int fillOutChoice() {
	int stubsChoice;

	std::cout << "\tWould like you like to fill this stub by hand, or use the" << std::endl;
	std::cout << "\tquickplay option? Please choose 1 if by hand, or 2 if by" << std::endl;
	std::cout << "\tquickplay: ";
	std::cin >> stubsChoice;

	std::cout << std::endl << std::endl;

	return stubsChoice;
}

void stubsChoiceValidation(int stubsChoice) {
	while (stubsChoice != 1 && stubsChoice != 2) {
		std::cout << "\tPlease make a valid selection: ";
		std::cin >> stubsChoice;

		std::cout << std::endl;
	}
}

void numberChoiceValidation(int arr[][NUMELEMS], int stubNumber, int numberChoice) {
	while (arr[stubNumber][numberChoice] < 1 || arr[stubNumber][numberChoice] > 70) {
		std::cout << "\tPlease make a valid selection: ";
		std::cin >> arr[stubNumber][numberChoice];
	}
}

void finalNumValidation(int arr[][NUMELEMS], int stubNumber, int numberChoice) {
	while (arr[stubNumber][numberChoice] < 1 || arr[stubNumber][numberChoice] > 25) {
		std::cout << "\tPlease make a valid selection: ";
		std::cin >> arr[stubNumber][numberChoice];
	}
}

void numberChoiceChosen(int arr[][NUMELEMS], int stubNumber, int numberChoice) {
	for (int count = 0; count < numberChoice; count++) {
		while (arr[stubNumber][count] == arr[stubNumber][numberChoice]) {
			std::cout << "\tYou have already chosen this number!" << std::endl;
			std::cout << "\tPlease choose another: ";
			std::cin >> arr[stubNumber][numberChoice];
			numberChoiceValidation(arr, stubNumber, numberChoice);
			count = 0;
		}
	}
}

void playerSelfPick(int arr[][NUMELEMS], int stubNumber) {
	for (int numberChoice = 0; numberChoice < NUMELEMS - 1; numberChoice++) {
		std::cout << "\tThis is stub " << stubNumber + 1 << ". Please choose number " << numberChoice + 1 << ": ";
		std::cin >> arr[stubNumber][numberChoice];

		numberChoiceValidation(arr, stubNumber, numberChoice);

		numberChoiceChosen(arr, stubNumber, numberChoice);
	}
	std::cout << "\tNow choose between 1 - 25 for the final Mega Millions" << std::endl;
	std::cout << "\tnumber: ";
	std::cin >> arr[stubNumber][FINALNUM];

	finalNumValidation(arr, stubNumber, FINALNUM);

	std::cout << std::endl << std::endl;
}

void quickplayPick(int arr[][NUMELEMS], int stubNumber) {
	for (int numberChoice = 0; numberChoice < NUMELEMS - 1; numberChoice++) {
		arr[stubNumber][numberChoice] = 1 + rand() % 70;

		for (int count = 0; count < numberChoice; count++) {
			if (arr[stubNumber][count] == arr[stubNumber][numberChoice]) {
				arr[stubNumber][numberChoice] = 1 + rand() % 70;
			}
		}
	}
	arr[stubNumber][FINALNUM] = 1 + rand() % 25;

	std::cout << std::endl;
}

void playerAllChoices(int arr[][NUMELEMS], int numStubs) {
	for (int stubNumber = 0; stubNumber < numStubs; stubNumber++) {

		int stubsChoice = fillOutChoice();

		stubsChoiceValidation(stubsChoice);

		if (stubsChoice == 1) {
			playerSelfPick(arr, stubNumber);
		}
		else {
			quickplayPick(arr, stubNumber);
		}
	}
}

void displayWinningNums(int arr[], int elems) {
	std::cout << "\tThank you for playing! I am now going to compare your numbers" << std::endl;
	std::cout << "\tto the winning lottery numbers!" << std::endl << std::endl << std::endl << std::endl << std::endl;

	std::cout << "\t********************************" << std::endl;
	std::cout << "\tThe winning lottery numbers are:" << std::endl << std::endl;

	std::cout << "\t";
	for (int count = 0; count < NUMELEMS; count++) {
		std::cout << std::setw(3) << std::right << arr[count] << " ";
	}
	std::cout << "\n\t********************************" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

int displayPlayerNums(int arr1[][NUMELEMS], int arr2[], int stubNumber, int counter) {
	std::cout << "\t----------------------------------------" << std::endl;
	std::cout << "\tThis is what you have chosen for stub " << stubNumber + 1 << ":" << std::endl << std::endl;

	std::cout << "\t";
	for (int numberChoice = 0; numberChoice < NUMELEMS; numberChoice++) {
		std::cout << std::setw(3) << std::right << arr1[stubNumber][numberChoice] << " ";

		if (arr1[stubNumber][numberChoice] == arr2[numberChoice]) {
			counter += 1;
		}
	}
	std::cout << "\n\t----------------------------------------" << std::endl;
	std::cout << std::endl;

	return counter;
}

bool finalNumEqual(int arr1[][NUMELEMS], int arr2[], int stubNumber) {
	bool finalNumber = false;

	if (arr1[stubNumber][FINALNUM] == arr2[FINALNUM]) {
		finalNumber = true;
	}

	return finalNumber;
}

int totalCalculator(int finalCounter, bool num) {
	int total = 0;

	switch (finalCounter) {
	case 0:
		if (num) {
			std::cout << "\tYou won $2!" << std::endl << std::endl;
			total += 2;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tI'm sorry, you didn't win anything..." << std::endl << std::endl;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	case 1:
		if (num) {
			std::cout << "\tYou won $4!" << std::endl << std::endl;
			total += 4;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tI'm sorry, you didn't win anything..." << std::endl << std::endl;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	case 2:
		if (num) {
			std::cout << "\tYou won $10!" << std::endl << std::endl;
			total += 10;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tI'm sorry, you didn't win anything..." << std::endl << std::endl;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	case 3:
		if (num) {
			std::cout << "\tYou won $200!" << std::endl << std::endl;
			total += 200;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tYou won $10!" << std::endl << std::endl;
			total += 10;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	case 4:
		if (num) {
			std::cout << "\tYou won $10,000!" << std::endl << std::endl;
			total += 10000;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tYou won $500!" << std::endl << std::endl;
			total += 500;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	case 5:
		if (num) {
			std::cout << "\tYOU WON THE JACKPOT!!!!!!" << std::endl << std::endl;
			total += 1000000000;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
		else {
			std::cout << "\tYou won $1,000,000!" << std::endl << std::endl;
			total += 1000000;
			std::cout << std::endl << std::endl << std::endl;
			break;
		}
	}

	return total;
}

void totalWinnings(int num) {
	std::cout << "\tYou won a grand total of $" << num << "! We hope you play again soon!";
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
}