# Fibonacci words on C++
Fibonacci word is a specific sequence of binary digits (or symbols from any two-letter alphabet). The Fibonacci word is formed by repeated concatenation in the same way that the Fibonacci numbers are formed by repeated addition. But unlike the fibonacci number, Fibonacci word has its first two terms different from each other.

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
Use example: 
```bash
$> ./fibonacci_words input.txt output.txt
```
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






