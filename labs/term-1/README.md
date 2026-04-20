# 📚 Laboratory Works — Term 1

---

## 🧪 Laboratory Work No. 1

The lab is dedicated to branching operators and I/O functions. Cycles are not supposed to be used to write code for algorithms of tasks.

### 📝 Tasks

**1.1** Find the sum of the terms of the arithmetic progression a, a+d, ..., a+(n—1)d by the entered values a, d, n.

**1.2** A ticket with a six-digit number is "lucky" if the amount is the first three digits are equal to the sum of its last three digits. Create an algorithm to determine whether a ticket number is "happy" or not.

**1.3** Create an algorithm for solving the inequality ax²+bx+c<0.

**1.4** The list of subjects studied at BSUIR and the semester number when they are studied is given. To create a program that would give out a list of subjects studied according to the semester number.

| Subject | Semester |
| :--- | :--- |
| Computer Science | 2.1 |
| Cultural Studies | 3.4 |
| Mathematics | 4.3 |
| English | 4, 1, 2, 3 |

---

## 🔁 Laboratory Work No. 2 — Loop Operators

### 📝 Tasks

**2.1** Given a natural number n. Find out if it is possible to represent n! = 1 ⋅ 2 ⋅ 3 ⋅...⋅ n as a product of three consecutive integers.

**2.2** Point A is located at a distance of 20 km from point B. Pedestrian P1 left point A at a speed of 2 km/h, and pedestrian P2 left point B at a speed of 3 km/h at the same time. A bumblebee flies between pedestrians at a speed of 5 km/h. The flight of the bumblebee is subject to the following rules:
- The bumblebee took off from point A at the same time as the start of the pedestrians;
- Having reached the pedestrian, the bumblebee immediately turns around and flies in the opposite direction.

In this way, the bumblebee runs between pedestrians until they meet. We will assume that a meeting has occurred if there is less than 1 cm left between pedestrians. Determine the lengths of all the segments that make up the bumblebee's path. We will call the segment the path that the bumblebee traveled from one U-turn to another.

**2.3** An integer N > 1 is given, which is the Fibonacci number. Find the previous and subsequent Fibonacci numbers.

---

## 📊 Laboratory Work No. 3 — One-Dimensional Arrays

The purpose of the work is to learn how to develop algorithms for working with static one–dimensional arrays and write code in C using the compiled algorithm.

Use static arrays in all tasks. When declaring, allocate space for 100 items, and then use as many as the user specifies. By default, arrays should be initialized with conscious test data (constructive creativity in this direction is welcome). Provide for the possibility of filling in arrays by the user using the keyboard.

The logic of filling arrays with data, processing arrays, and outputting processing results should be implemented in different functions. Functions that need to calculate a value or generate a new array must return the corresponding value. Functions that should modify the array passed to them should be declared as void.

### 📝 Tasks

**3.1** In a one–dimensional array consisting of n real elements, calculate:
- The product of the negative elements of the array;
- The sum of the positive elements of the array located up to the first maximum element.

**3.2** From an array of n elements, remove every element smaller than both of its neighbors.

**3.3** There are two arrays of integers: The first one is filled in ascending order (n elements), the second one (k elements) is filled in descending order. Copy all the elements from the second to the first, without disturbing its original order.

---

## 🧮 Laboratory Work No. 4 — Multidimensional Arrays

The purpose of the work is to learn how to develop algorithms for working with static multidimensional arrays and write code in C using the compiled algorithm.

Use static arrays in all tasks. When declaring, allocate space for 100 lines per 100 elements, and then use as much as the user specifies. By default, arrays should be initialized with conscious test data (constructive creativity in this direction is welcome). Provide for the possibility of filling in arrays by the user using the keyboard.

The logic of filling arrays with data, processing arrays, and outputting processing results should be implemented in different functions. Functions that need to calculate a value or generate a new array must return the corresponding value. Functions that should modify the array passed to them should be declared as void.

### 📝 Tasks

**4.1** In a square matrix, find the minimum element in the 2nd region.

**4.2** Find the minimum element in the 2nd region in the matrix.

---

## 💾 Laboratory Work No. 5 — Dynamic Memory Allocation

The purpose of the work is to learn how to dynamically allocate memory for working with one–dimensional and two-dimensional arrays.

The memory for the arrays mentioned in the task statements should be allocated dynamically. Deleting and adding items must be accompanied by over-allocation of memory. Unused memory should be released.

By default, arrays should be initialized with conscious test data (reference results should also be prepared). Provide for the possibility of filling in arrays by the user using the keyboard.

The logic of filling arrays with data, processing arrays, and outputting processing results should be implemented in different functions. Functions that need to calculate a value or generate a new array must return the corresponding value. Functions that should modify the array passed to them should be declared as void.

Function declarations (except, obviously, main) should be placed in separate header (.h) files, the implementation in source code files (.c). Organize the division it should be done in such a way that the code of the function body takes up no more than 25 lines without taking into account the lines-delimiters. The lines must contain an adequate (tends to 1) number of instructions.

### 📝 Tasks

**5.1** Find all the primes less than n using the sieve of Eratosthenes method.

**5.2** For a rectangular matrix, determine the maximum length of a continuous (adjacent to the rightmost element of the row is the leftmost element of the row below) sequence of positive numbers. Delete all rows containing the calculated value.

**5.3** In a two-dimensional array, insert a square after each even value. The array strings may differ from each other in length.

---

## 🔢 Laboratory Work No. 6 — Sorting Algorithms

The purpose of the work is to consider various sorting algorithms for elements applied to one–dimensional and two-dimensional arrays.

Use dynamic arrays in all tasks.

The requirements for breaking the code into functions are similar to those for the previous laboratory. In particular, for each task, the function "sort the array according to the task condition" should be provided, which specifies the full sequence of necessary actions.

To check the operability of the code, you need to create test arrays, allowing you to simulate his behavior in all key situations. For test arrays, calculate the expected results of their processing.

To demonstrate the functionality of the functions, it is necessary to compare the results obtained as a result of their invocation with the test data with the expected results.

When performing the 1st task, it is necessary to measure the sorting time of a randomly filled array of large (for example, 10,000 elements) and compare it with the sorting time in another way (for example, by "bubble"). For this we need to write 1 more sorting function, completely similar in its result and list of arguments to the main one, but using a different sorting algorithm. You also need to compare the sorting time for the cases of an array initially sorted (in terms of the task condition) and an array sorted in reverse order.

The items that are not being sorted should remain in their original places. You only need to sort the elements of the category described in the task condition within the positions of such elements.

The use of additional arrays to simplify your life is not encouraged.

### 📝 Tasks

**6.1** In a one-dimensional array, sort the even positive elements using the Shell method.

**6.2** In a rectangular matrix, sort the columns in descending order of the size of the longest series of repeating elements using the Hoare method.

---

## 🔤 Laboratory Work No. 7 — Working with Strings. Pointers to Functions. The Command Line

The purpose of the work is to consider the basic techniques of working with strings.

As a result of this laboratory work, a program should be developed that accepts command-line arguments as input.

The program should pass the task number as the first argument, and the arguments required by the task condition should be used as the rest. According to the task number passed as the first argument, a function should be called that implements the logic of the selected task.

All tasks should be implemented within the framework of one common main. To select a function that contains the logic of the task specified as a command line argument, use the syntax with a function pointer.

The approaches to code splitting required in the implementation of past laboratory tests remain valid. At the same time, all functions related to the implementation of only one of the tasks should be declared in a single header file and implemented in a single source code file. Functions that are common to implementations of several tasks should be declared and implement in separate groups depending on the functional purpose.

Function declarations (except, obviously, main) should be placed in separate header (.h) files, and the implementation in source code files (.c).

The use of library functions for working with strings is, of course, prohibited. Processing strings as char arrays should be implemented strictly independently.

A word is a set of characters between delimiters. Every letter is a symbol, but not every symbol is a letter. When deleting a word, it is better not to forget about 1 of its separators.

A number is a word consisting of digits and, if negative, a sign.

Unless the opposite is specified directly in the task condition, an arbitrary set of characters is considered a string. Dynamic strings should be used.

As part of the third task, you should sort the dynamic array of copies of strings passed to the program as command-line arguments.

### 📝 Tasks

**7.1** Find the maximum number in a row.

**7.2** Replace all the numbers in the string with the specified word.
