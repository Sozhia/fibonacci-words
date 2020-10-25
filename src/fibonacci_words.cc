/**
 * @file fibonacci_words.cc
 * @author Miqueas (Sozhia) García González (sozhia.business@gmail.com)
 * @brief This program check from a document if a word is an Fibonacci word
 * @version 0.1
 * @date 2020-10-22
 * @web http://www.github.com/Sozhia
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>

class FibonacciWord{
 private:
  std::string word_;
  unsigned int size_;
 public:
  FibonacciWord();
  FibonacciWord(std::string, unsigned int);
  void SetWord(std::string word);
	void SetSize(unsigned int value);
  std::string GetWord();
  unsigned int GetSize();
};

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
void PrintHelp() {
	std::cout << "A Fibonacci word is a specific sequence of binary digits";
	std::cout << "(or symbols from any two-letter alphabet). The Fibonacci word is formed by";
	std::cout << "repeated concatenation in the same way that the Fibonacci numbers are formed";
	std::cout << " by repeated addition." << std::endl;
	std::cout << "F1 = a, F2 = b, F3 = ab, F4 = bab, F5 = abbab "<< std::endl;
	std::cout << "Use example: $> ./fibonacci_words input.txt output.txt" << std::endl;
}
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

int main(int argc, char** argv) {
	std::string f_input, f_output;
  std::vector<std::string> input_holder;
	std::vector<FibonacciWord> fibonacci_holder;
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
		PrintHelp();
		exit(1);
	}
  if (argc != 3) {
		PrintHelp();
		exit(1);
	}
	f_input = argv[1];
	f_output = argv[2];
	LoadData(input_holder,f_input);
	for (unsigned int auxiliar =0; auxiliar < 2; auxiliar ++) {
		FibonacciWord object;
		FillFibonacciHolder(input_holder, fibonacci_holder, auxiliar, object);
	}
	WriteData(f_output,fibonacci_holder,input_holder);
  return 0;
}
