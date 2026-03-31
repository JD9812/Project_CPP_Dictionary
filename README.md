#Dictionary System (C++)

Is a C++ application that loads and searches dictionary data from a structured text file, using object-oriented design, file parsing and dynamic memory management.

#Features
- Loads dictionary data from CSV file
- Supports multiple definitions per word
- Optional verbose mode to display part of speech
- Word search with formatted output
- Demostrates Rule of Five

#Concepts
- C++
- Object-Oriented Programming
- Dynamic Memory Management
- Rule of Five
- ifstream
- String parsing
- Enums and Structured data

#Data
-Each Line in input file must follow this format: 
  word,part_of_spech,definitions
-Example:
  Abduction,n.,The act of abducing or abducting; a drawing apart; a carrying away.

#How to run
  - Visual Studio
    1. Open .sln file
    2. Build solution (Ctrl + Shift + B)
    3. Run program (F5)
  - Command Line
      - g++ -std=c++ -Wall -o dictionary dictionaryMain.cpp dictionary.cpp english_large.csv english_small.csv

#Output Example
  - Germanize - (verb) "To make German, or like what is distinctively German; as, to Germanize a province, a language, a society."
              - (verb) To reason or write after the manner of the Germans.

#Implementation
  - The dictionary is stored as a collection of Word objects
  - Each Word struct contains:
    - word
    - definition
    - part of speech
  - The input file is processed in two time:
    1. Count entries
    2. Load data into memory

#Future Improvements
  - Case-insensitive search
  - Refactor dynamicallly allocated array to use std::vector to simplify memory management
  - Implement unit testing
  - Optimize search performance
  - Add interactive mode to allow multiple searches without restarting program
  - Add unit testing

#Author
Juan Diego Correa Noy
