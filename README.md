# Fibonacci words on C++
## 0.- Definition 
A Fibonacci word is a specific sequence of binary digits (or symbols from any two-letter alphabet). The Fibonacci word is formed by repeated concatenation in the same way that the Fibonacci numbers are formed by repeated addition. But unlike the fibonacci number, Fibonacci word has its first two terms different from each other.
Example:
```
In Fibonacci word,
  F1 = "a",
  F2 = "b",
  F3 = "ab",
  F4 = "bab",
  F5 = "abbab",
  F6 = "bababbab", 
  F7 = "abbabbababbab".
   ..... 
```
where F(n) = F(n-2) + F(n-1) and + represents the concatenation of strings.\n
## 1.- Use example
Use example: 
```bash
$> ./fibonacci_words input.txt output.txt
```
Get info from a file input.txt and dumping it parsed into an output.txt file.
```
input.txt

a
b
ba
aaa
bb
bababbab
```
```
output.txt

a is the word number 1
b is the word number 2
ba is not a Fibonacci word
aaa is not a Fibonacci word
bb is not a Fibonacci word
bababbab is the word number 6
```
## 2.- Programming thougth process
We are gonna use a `fibonacci-word.cc` file that contains our program (check [Google Style](https://google.github.io/styleguide/cppguide.html), a `string vector` that cointains all data from the input file and a `seed vector` that contains our info to generate Fibonaccis words. The programm should check all data from the `string vector` and write the process into an ouput file where the program will write if a `word` is or not a `Fibonacci word` and how many iteratotions we needed to generate that world.






