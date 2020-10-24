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

class FibonacciWord{
 private:
  std::string word_;
  unsigned int size_;
 public:
  FibonacciWord(std::string, unsigned int);
	~FibonacciWord();
  void SetWord(std::string word);
  void SetSize(unsigned int value);
  std::string GetWord();
  unsigned int GetSize();
};

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

bool unsigned int CheckFibonacci(std::string word, std::vector<FibonacciWord> seed,
																															unsigned int counter) {
	std::string first, second, tmp;
	first = seed[0].GetWord;
	second = seed[1].GetWord;
	tmp = ;
	do {
		tmp = second;
		second = first + second;
		first = tmp;
		counter ++;
	} while (second.length() <= word.length());

	if (second == word){
		return true;
	} else {
		return false;
	}
}

void FillInHolder(std::vector<std::string> holder, std::ifstream file) {
	unsigned int counter = 0;
	std::string foo;
	while(!file.eof()) {
		getline(file, foo);
		holder.push_back(foo);
		counter ++;
	}
	file.close();
}

void StartFibonacciHolder(std::vector<std::string> input_holder,
  												std::vector<FibonacciWord> fibonacci_holder) {
	fibonacci_holder[0].SetSize(input_holder[0].size());
	fibonacci_holder[0].SetWord(input_holder[0]);
	fibonacci_holder[1].SetSize(input_holder[1].size());
	fibonacci_holder[1].SetWord(input_holder[1]);
}
void WriteOutFile(std::vector<std::string> input_holder, std::ofstream output, 
									std::vector<FibonacciWord> seed) {
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

void PrintHelp() {
	std::cout << "A Fibonacci word is a specific sequence of binary digits";
	std::cout << "(or symbols from any two-letter alphabet). The Fibonacci word is formed by";
	std::cout << "repeated concatenation in the same way that the Fibonacci numbers are formed";
	std::cout << " by repeated addition." << std::endl;
	std::cout << "F1 = a, F2 = b, F3 = ab, F4 = bab, F5 = abbab "<< std::endl;
	std::cout << "Use example: $> ./fibonacci_words input.txt output.txt" << std::endl;
}

int main(int argc, char** argv) {
  if (argc == 2 && strcmp(argv[1], "--help")==0)
		PrintHelp();
  if (argc != 3)
		PrintHelp();
	std::string f_input, f_output;
  std::vector<std::string> input_holder;
	std::ifstream input;
	std::vector<FibonacciWord> fibonacci_holder;
	std::ofstream ouput;
	input.open(f_input, std::ios::in);
	if (input.fail()) {
		std::cout << "Cannot open file "<< f_input <<" ... exiting program."  << std::endl;
		exit(1);
	}
	FillInHolder(input_holder, input);
	StartFibonacciHolder(input_holder, fibonacci_holder);
	CheckFibonacci(input_holder);
	ouput.open(f_output,std::ios::out);
	if (output.fail()) {
		std::cout << "Cannot open file " << f_output << " ... exiting program."  << std::endl;
		exit(1);
	}
	WriteOutFile(input_holder, f_output, fibonacci_holder);
  return 0;
}