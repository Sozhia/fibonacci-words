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

#include "../include/fibonacci_words.cc"

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
	/// Making seed with only 2 'words'
	for (unsigned int auxiliar =0; auxiliar < 2; auxiliar ++) {
		FibonacciWord object;
		FillFibonacciHolder(input_holder, fibonacci_holder, auxiliar, object);
	}
	WriteData(f_output,fibonacci_holder,input_holder);
  return 0;
}
