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