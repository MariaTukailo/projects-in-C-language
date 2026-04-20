# 📚 Laboratory Works — Semester 2

---

## 📂 Laboratory Work No. 1 — Binary Files

The purpose of the work is to consider the basic techniques of working with binary files.

The essence of all tasks is to process one-dimensional arrays of arbitrary length stored in a binary file. That is, it works with an array, but the operations of obtaining the value of an element and changing the value of an element are replaced by operations of reading from a file and writing to a file.

All tasks should be implemented within the looped menu of a single main. Before performing calculations, each task should be given the opportunity to enter an array from the keyboard or output it to the console.

The file path should be passed as a command line argument. The arguments required within the task algorithms are read from the console.

Entering an array consists of writing its elements to a file. Modification of the array consists of editing the contents of the corresponding file.

If one of the tasks assumes a specific structure for filling the array, the implemented input must guarantee such a structure. If different tasks involve different file structures, select several appropriate files and functions to fill them in.

Files in the input/output function and functions that directly implement the task condition should be passed as a string containing the path to the file. That is, inside such functions, the file must be "opened" and "closed" again.

Input, calculations, and output, of course, as before, must be implemented in separate functions. Except for wrappers containing function calls of all 3 types. Functions should contain no more than 25 lines with an adequate (about 1) number of instructions.

Functions, as before, should be grouped by files, depending on their roles in the laboratory. It is advisable to put declarations of only those functions in header files that are used when implementing functions from other files.

To demonstrate the laboratory, provide for the presence of files filled in such a way as to allow you to evaluate the performance of the code without having to enter it through the console.

### 📝 Tasks

**1.1** Calculate the maximum length of a continuous sequence of elements, the sum of which does not exceed the specified value.

**1.2** Delete all elements that are multiples of the specified value.

**1.3** Swap elements with even values in pairs (within the positions of such elements), equally distant from the central one.

---

## 📄 Laboratory Work No. 2 — Text Files

The purpose of the work is to consider the basic techniques of working with text files.

The essence of all tasks is to analyze individual words of a text file. Working with files should be done in text mode.

If the opposite is not explicitly stated in the condition of a specific task, the processed files are assumed to be filled in an arbitrary way.

The requirements for code organization are similar to those for the previous laboratory: a looped menu, a file path via the command line, and arguments for algorithms to read from the console. Console input/output functions for the contents of the file are not necessary to implement: as an input, it is enough to change the text passed as an argument in the text editor.txt, to display the content, open the file in the editor.

To demonstrate the laboratory, you should provide for the presence of files filled in such a way as to allow you to evaluate the operability of the code. There is no alternative to starting protection by manually filling in a file.

You should try to organize the reading of the file in an optimal way. One-time storage of a piece of data in the application's memory, obviously representing the contents of the entire file is prohibited.

Working with a text file by reading its contents exclusively character–by-character is ugly. The use of additional files in the implementation of the main algorithm is a 2–point penalty for laboratory work.

A word is a set of characters between delimiters. Every letter is a symbol, but not every symbol is a letter.

A number is a word consisting of digits and, if negative, a sign.

When deleting a word, it is better not to forget about 1 of its separators. Punctuation marks when deleting/hyphenating the word "stick" to a word are ugly.

### 📝 Tasks

**2.1** Calculate the number of words in the longest sequence of repeated words in the file.

**2.2** Replace all the maximum numbers in the file with the minimum ones, and all the minimum ones with the maximum ones.

---

## 🧬 Laboratory Work No. 3 — Custom Data Types

The purpose of this paper is to consider the basic techniques for working with user–defined data types.

All tasks should be implemented within the looped menu of a single main.

The solution to the first problem is supposed to be implemented using bit fields and joins.

The second task involves working with arrays of structures, some of which use enumerations as fields. In addition to the functions directly mentioned in the formulation of the task variant, it is required to implement the functions of adding records to an array of structures via the console, deleting records by index in the array and output an array of structures to the console.

For the second task, you should provide logic that allows you not to lose the existing state of the array of structures when the application is shut down, so that after restarting the application, you can continue working with the same array of structures. For example, write the contents of an array to a file.

When demonstrating the second task, in order to avoid the mandatory lengthy process of manually entering data through the console, it should be possible to initialize an array of structures with pre–prepared values. The most appropriate way to do this is with the corresponding file.

Input, analysis, and output, of course, as before, must be implemented in separate functions. Except for "wrappers" containing function calls of all 3 types. Functions should contain no more than 25 lines with an adequate (about 1) number of instructions.

For each task, one function should be allocated that accepts exclusively (no more and no less) the arguments mentioned in the task condition and generates (without accompanying input and output, unless their specific form is explicitly specified in the task condition) the result.

Functions, as before, should be grouped by files depending on their role in the laboratory. It is advisable to put declarations of only those functions in header files that are used when implementing functions in other source code files.

### 📝 Tasks

**3.1** Find the integer part of a floating point number (float).

**3.2** Book Structure:

| Field | Type |
| :--- | :--- |
| Book title | dynamic string |
| Full name of the book's authors | array of dynamic strings |
| Readers of the book | array of structures Reader |

**Reader Structure:**

| Field | Type |
| :--- | :--- |
| Full name | dynamic string |
| Year of birth | date |
| The year of the beginning of reading the book | date |

**Implement:**

- Formation of a list of distinct authors, sorted in descending order of the average age of the reader of books written with their participation;
- Deleting the least popular books.

---

## 🔗 Laboratory Work No. 4 — Linked Lists

The purpose of the work is to consider the structure of linked lists, to consider their advantages and disadvantages in comparison with arrays.

All tasks should be implemented within the looped menu of a single main. The requirements for code organization are similar to those for previous labs.

The solution to the first problem is supposed to be implemented using a stack.

The second task of this laboratory work is based on the second task from the previous laboratory. You need to implement all the same things, but instead of arrays of values, use connected queues of values. Besides saving the old logic's working properly with the new data storage structure, it is also necessary to implement 1 new option according to the condition of the present laboratory version.

The solution to each of the tasks should be implemented based on the specified dynamic data structure. In particular, writing the contents of lists to arrays for processing and writing back is prohibited.

### 📝 Tasks

**4.1** Implement a function that calculates the value of an infixed arithmetic expression. If the expression format is incorrect, indicate the position with the incorrect character.

**4.2** Book Structure:

| Field | Type |
| :--- | :--- |
| Book title | dynamic string |
| Full name of the book's authors | array of dynamic strings |
| Readers of the book | array of structures Reader |

**Reader Structure:**

| Field | Type |
| :--- | :--- |
| Full name | dynamic string |
| Year of birth | date |
| The year of the beginning of reading the book | date |

**Implement:**

- Creation of a list of authors sorted in descending order of the average age of readers of books written with their participation;
- Deleting the least popular books;
- Forming a list of readers of books written with the participation of a given author.

---

## 🔍 Laboratory Work No. 5 — Search Algorithms

The purpose of the work is to consider the use of binary trees and hash tables in search optimization algorithms.

It is performed based on part 2 of the previous laboratory work. It is necessary to write 2 alternative implementations of it: in the first one, you need to replace the main queue of structures with a binary tree, in the second – with a hash table. In addition to maintaining the operability of all previously implemented functionality, each of the implementations involves adding one new record search option. At the same time, filling in the appropriate data structure should be dictated by necessity of maximum optimization of the added search option.

In the laboratory, using "search algorithms", searching with a deliberately complete bypass of the collection is, of course, prohibited. It is absolutely necessary to provide collision handling.

Depending on the task, one tree/table may not be enough.

### 📝 Task 5.1 — Book Structure

| Field | Type |
| :--- | :--- |
| Book title | dynamic string |
| Full name of the book's authors | array of dynamic strings |
| Readers of the book | array of structures Reader |

**Reader Structure:**

| Field | Type |
| :--- | :--- |
| Full name | dynamic string |
| Year of birth | date |
| The year of the beginning of reading the book | date |

**Implement:**

- Creation of a list of authors sorted in descending order of the average age of readers of books written with their participation;
- Deleting the least popular books;
- Creating a list of readers of books written with the participation of a given author;
- **For the tree:** search for books by name;
- **For the hash table:** search for books by author name.
