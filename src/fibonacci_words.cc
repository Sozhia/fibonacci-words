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
  std::string GetWord ();
  unsigned int GetSize();

};

FibonacciWord::FibonacciWord(std::string word, unsigned int value) {
	word_ = word;
	size_ = value;
}

FibonacciWord::SetWord(std::string word) {
	word_ = word;
}

FibonacciWord::SetSize(unsigned int value) {
	size_ = value;
}

void InsertWord(std::vector<FibonacciWord> holder, std::string word, unsigned int index){
	holder[index].SetSize = word.size();
	holder[index].SetWord = word;
}

bool CheckFibonacci(std::string word, std::vector<FibonacciWord> seed) {
	unsigned int counter ;
	std::string first, second, tmp;
	first = seed[0].GetWord;
	second = seed[1].GetWord;
	temp = first + second;
	do {


	} while ();
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
	for (unsigned int pointer = 0; pointer < input_holder.size(); pointer++) {
		if (CheckFibonacci(input_holder[pointer], seed)) {
			output << input_holder << ;
		} else {

		}
		




}

void PrintHelp() {
	std::cout << "A Fibonacci word is a specific sequence of binary digits 
	(or symbols from any two-letter alphabet). The Fibonacci word is formed by 
	repeated concatenation in the same way that the Fibonacci numbers are formed by repeated 
	addition."
	<< std::endl;
	std::cout << "F1 = a
	,F2 = b
	,F3 = ab
	,F4 = bab
	,F5 = abbab "<< std::endl;
	std::cout << "Use example: $> ./fibonacci_words input.txt output.txt" << std::endl;
}

int main(int argc, char** argv) {
  if(argc == 2 && strcmp(argv[1], "--help")==0)
		PrintHelp();

  std::vector<std::string> input_holder;
	std::ifstream input;
	std::vector<FibonacciWord> fibonacci_holder;
	std::ofstream ouput;
	
	input.open("input.txt", std::ios::in);
	if (input.fail()){
		std::cout << "Cannot open file input.txt ... exiting program."  << std::endl;
		exit(1);
	}

	FillInHolder(input_holder, input);
	StartFibonacciHolder(input_holder, fibonacci_holder);
	CheckFibonacci(input_holder);

	ouput.open("output.txt",std::ios::out);

	if (output.fail()){
		std::cout << "Cannot open file output.txt ... exiting program."  << std::endl;
		exit(1);
	}
	

	
  return 0;
}