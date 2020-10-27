/**
 * @file fibonacci_words.h
 * @author Miqueas (Sozhia) García González (sozhia.business@gmail.com)
 * @brief This program check from a document if a word is a Fibonacci word
 * @version 1.3.2
 * @date 2020-10-25
 * @web http://www.github.com/Sozhia
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>

 /**
  * @brief Fibonacci word class
  * 
  */
class FibonacciWord{
 private:
  std::string word_; /// Word itself
  unsigned int size_; /// Length of word 
 public:
  FibonacciWord(); /// Default constructor
  FibonacciWord(std::string, unsigned int); /// Constructor with parameters
	/**
	 * @brief Set `word` to an object
	 * 
	 * @param word  `word` content itself
	 */
  void SetWord(std::string word);
	/**
	 * @brief Set the size of `word`
	 * 
	 * @param value length of `word`
	 */
	void SetSize(unsigned int value);
	/**
	 * @brief Get `word's` object
	 * 
	 * @return std::string content of `word's` object 
	 */
  std::string GetWord();
	/**
	 * @brief Get length of `word's object`
	 * 
	 * @return unsigned int `word's` object length
	 */
  unsigned int GetSize();
};

FibonacciWord::FibonacciWord();
FibonacciWord::FibonacciWord(std::string word, unsigned int value); 
void FibonacciWord::SetWord(std::string word);
void FibonacciWord::SetSize(unsigned int value);
std::string FibonacciWord::GetWord();
unsigned int FibonacciWord::GetSize();

/**
 * @brief Prints helpfull use information about the program to the user
 * 
 */
void PrintHelp();

/**
 * @brief Check if a word is a Fibonacci word as the result of concating a seed 
 * 
 * @param word Word itself
 * @param seed Fibonacci Words generator itself
 * @param counter Number of iterations to get content of word
 * @return true If word is Fibonacci word
 * @return false If word is not a Fibonacci word
 */
bool CheckFibonacci(std::string word, std::vector<FibonacciWord> seed, unsigned int &counter);

/**
 * @brief Load data from an input file and its dumped into a vector called holder
 * 
 * @param holder Vector with data
 * @param finput File itself
 */
void LoadData(std::vector<std::string> &holder, std::string finput); 

/**
 * @brief Writes checked as fibonacci data into an output file 
 * 
 * @param f_output File itself
 * @param seed Fibonacci Words generator
 * @param input_holder Vector with info to checkout 
 */
void WriteData(std::string f_output, std::vector<FibonacciWord> seed, 
				std::vector<std::string> input_holder);

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
						unsigned int aux, FibonacciWord object);