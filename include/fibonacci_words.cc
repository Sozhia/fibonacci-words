/**
 * @file fibonacci_words.cc
 * @author Miqueas (Sozhia) García González (sozhia.business@gmail.com)
 * @brief This program check from a document if a word is a Fibonacci word
 * @version 1.3.2
 * @date 2020-10-25
 * @web http://www.github.com/Sozhia
 * @copyright Copyright (c) 2020
 * 
 */

#include "./fibonacci_words.h"

FibonacciWord::FibonacciWord() {
	word_ = "";
	size_ = word_.length();
}

FibonacciWord::FibonacciWord(std::string word, unsigned int value) {
	word_ = word;
	size_ = value;
}

void FibonacciWord::SetWord(std::string word) {
	word_ = word;
}

void FibonacciWord::SetSize(unsigned int value) {
	size_ = value;
}
std::string FibonacciWord::GetWord() {
	return word_;
}
unsigned int FibonacciWord::GetSize() {
	return size_;
}

/**
 * @brief Prints helpfull use information about the program to the user
 * 
 */
void PrintHelp() {
	std::cout << "A Fibonacci word is a specific sequence of binary digits";
	std::cout << "(or symbols from any two-letter alphabet). The Fibonacci word is formed by";
	std::cout << "repeated concatenation in the same way that the Fibonacci numbers are formed";
	std::cout << " by repeated addition." << std::endl;
	std::cout << "F1 = a, F2 = b, F3 = ab, F4 = bab, F5 = abbab "<< std::endl;
	std::cout << "Use example: $> ./fibonacci_words input.txt output.txt" << std::endl;
}

/**
 * @brief Check if a word is a Fibonacci word as the result of concating a seed 
 * 
 * @param word Word itself
 * @param seed Fibonacci Words generator itself
 * @param counter Number of iterations to get content of word
 * @return true If word is Fibonacci word
 * @return false If word is not a Fibonacci word
 */
bool CheckFibonacci(std::string word, std::vector<FibonacciWord> seed, unsigned int &counter) {
	std::string first, second, tmp;
	first = seed[0].GetWord();
	second = seed[1].GetWord();
	if (first == word) {
		counter = 1;
		return true; 
	}
	if (second == word) {
		counter = 2;
		return true; 
	}
	counter = 2;
	do {
		tmp = second;
		second = first + second;
		first = tmp;
		counter ++;
	} while (second.length() < word.length());
	if (second == word){
		return true;
	} else {
		return false;
	}
}

/**
 * @brief Load data from an input file and its dumped into a vector called holder
 * 
 * @param holder Vector with data
 * @param finput File itself
 */
void LoadData(std::vector<std::string> &holder, std::string finput) {
	std::ifstream input;
	input.open(finput, std::ios::in);
	if (input.fail()) {
		std::cout << "Cannot open file to load data ... exiting program."  << std::endl;
		exit(1);
	}
	unsigned int counter = 0;
	std::string foo;
	while(!input.eof()) {
		getline(input, foo);
		if (!foo.empty() ) {
			holder.push_back(foo);
			counter ++;
		}
	}
	input.close();
}

/**
 * @brief Writes checked as fibonacci data into an output file 
 * 
 * @param f_output File itself
 * @param seed Fibonacci Words generator
 * @param input_holder Vector with info to checkout 
 */
void WriteData(std::string f_output, std::vector<FibonacciWord> seed, 
															 std::vector<std::string> input_holder) {
	std::ofstream output;
	output.open(f_output,std::ios::out);
	if (output.fail()) {
		std::cout << "Cannot open file to write data ... exiting program."  << std::endl;
		exit(1);
	}
	unsigned int word_value;
	for (unsigned int pointer = 0; pointer < input_holder.size(); pointer++) {
		if (CheckFibonacci(input_holder[pointer], seed, word_value)) {
			output << input_holder[pointer] << " is the word number " << word_value << "\n";
		} else {
			output << input_holder[pointer] << " is not a Fibonacci word. \n";
		}
		word_value = 0;
	}
	output.close();
}

/**
 * @brief Fill a vector as Fibonacci word seed container
 * 
 * @param input_holder Vector that contains info
 * @param fibonacci_holder FibonacciWord objects container
 * @param aux Vector position
 * @param object Fibonacci Word object itself
 */
void FillFibonacciHolder(std::vector<std::string> input_holder, 
									 std::vector<FibonacciWord> &fibonacci_holder,
									 			unsigned int aux, FibonacciWord object) {
	unsigned int size;
	std::string word;
	word = input_holder[aux];
	size = word.length();
	object.SetSize(size);
	object.SetWord(word);
	fibonacci_holder.push_back(object);
}