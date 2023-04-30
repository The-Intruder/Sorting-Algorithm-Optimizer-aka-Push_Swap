<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap">
    <img src="https://is5-ssl.mzstatic.com/image/thumb/Purple113/v4/3d/9f/ec/3d9fec92-dc0c-9cb9-f335-f398a570ad72/source/512x512bb.jpg" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Sorting Algorithm Optimizer <em>(push_swap)</em></h3>

  <p align="center">
    <a href="https://github.com/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap/issues">Request Feature</a>
  </p>
</p>

![License](https://img.shields.io/github/license/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap) 

## Table Of Contents

- [Table Of Contents](#table-of-contents)
- [About The Project](#about-the-project)
- [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
      - [Example](#example)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
  - [Creating A Pull Request](#creating-a-pull-request)
- [License](#license)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

## About The Project

![Screen Shot](images/screenshot.png)

The Push_swap project is a sorting algorithm implementation that aims to sort a stack of integers using a limited set of predefined operations. The project focuses on finding an optimal solution to sort the stack with the fewest possible operations.

The main objective of the Push_swap algorithm is to sort the given stack in ascending order. To achieve this, the algorithm utilizes two stacks, named "Stack A" and "Stack B." The operations available to manipulate the stacks include:

- `sa`: Swap the top two elements of Stack A.
- `sb`: Swap the top two elements of Stack B.
- `ss`: Swap the top two elements of both Stack A and Stack B simultaneously.
- `pa`: Push the top element from Stack B to Stack A.
- `pb`: Push the top element from Stack A to Stack B.
- `ra`: Rotate Stack A in a circular manner (the top element becomes the bottom element).
- `rb`: Rotate Stack B in a circular manner.
- `rr`: Rotate both Stack A and Stack B simultaneously.
- `rra`: Reverse rotate Stack A (the bottom element becomes the top element).
- `rrb`: Reverse rotate Stack B.
- `rrr`: Reverse rotate both Stack A and Stack B simultaneously.

The Push_swap project requires implementing an algorithm that takes an unsorted stack of integers as input and outputs a sequence of operations that, when executed, will sort the stack in ascending order.

The challenge in this project lies in finding an optimal solution with the fewest number of operations to sort the stack efficiently. The project also involves considering edge cases, handling errors, and optimizing the algorithm's performance.

The Push_swap project serves as an opportunity to explore algorithmic problem-solving, data structures, and the efficient manipulation of stacks. It provides a practical application of sorting algorithms and requires careful consideration of time complexity and space complexity to ensure an efficient solution.



## Built With

The _Push\_swap_ project was implemented using the following technologies and tools:

- **Programming Language:** C
- **Version Control:** Git
- **Build System:** Make
- **Compiler:** GCC (GNU Compiler Collection)
- **Integrated Development Environment (IDE):** Visual Studio Code
- **Versioning:** GitHub

The project leveraged the C programming language for its implementation, providing a low-level and efficient approach to solving the problem. Git was used for version control, allowing for efficient collaboration and tracking changes throughout the development process. Make was chosen as the build system, facilitating the compilation and organization of the project's source code files.

The GCC compiler, a widely-used open-source compiler collection, was employed to compile the C code and generate the executable file. For development, Visual Studio Code was the preferred integrated development environments (IDEs) for writing, debugging, and testing the code.

## Getting Started

To get started with the Push_swap project, follow the steps below:

### Prerequisites

Before running the Push_swap program, ensure that you have the following prerequisites installed:

- **C Compiler**: Make sure you have a C compiler installed on your system. The recommended compiler is GCC (GNU Compiler Collection).

### Installation

To install and set up the Push_swap project, follow these steps:

1. Clone the repository:

```shell
git clone https://github.com/your-username/push_swap.git
```

2. Navigate to the project directory:

```shell
cd push_swap
```

3. Build the project using the provided Makefile:

```shell
make
```

The above step will generate the push_swap executable file.


## Usage

Once you have built the project, you can use the Push_swap program as follows:

```shell
./push_swap [list_of_integers]
```

Replace `[list_of_integers]` with the list of integers that you want to sort. The program will output a series of operations that will sort the given list using the fewest possible operations.

##### Example
Here's an example usage of the Push_swap program:

```shell
./push_swap 4 2 7 1 3
```

Output:

```shell
sa
pb
pb
sa
pa
pa
sa
```

The above command takes a list of integers `[4, 2, 7, 1, 3]` and generates a sequence of operations _(`sa`, `pb`, `pa`, etc.)_ that will sort the list.

## Roadmap

Here's a roadmap outlining the planned and completed tasks for the Push_swap project:

1. **Project Setup**
   - [x] Set up the project repository
   - [x] Initialize the Git version control system
   - [x] Create the basic directory structure
   - [x] Write the initial Makefile for building the project

2. **Stack Implementation**
   - [x] Define the stack data structure
   - [x] Implement stack-related functions, such as push, pop, and peek
   - [x] Write unit tests for the stack implementation

3. **Input Parsing**
   - [x] Implement a function to parse the command-line arguments
   - [x] Validate and extract the list of integers from the input
   - [x] Handle invalid input scenarios gracefully

4. **Sorting Algorithm**
   - [x] Design and implement the sorting algorithm using stack operations
   - [x] Optimize the algorithm for efficiency and minimum number of operations
   - [x] Test the algorithm with different input sizes and edge cases

5. **Command Generation**
   - [x] Implement a function to generate the sequence of operations
   - [x] Ensure the generated commands result in a sorted stack
   - [x] Handle special cases and edge scenarios during command generation

6. **Output and Validation**
   - [x] Print the generated sequence of operations
   - [x] Verify the correctness of the sorted stack
   - [x] Handle error cases and edge scenarios during output and validation

7. **Documentation and Refactoring**
   - [ ] Document the codebase, including function headers and comments
   - [ ] Generate Doxygen documentation for the project
   - [ ] Refactor the codebase for readability, modularity, and maintainability

8. **Testing and Quality Assurance**
   - [ ] Write comprehensive unit tests for different components
   - [ ] Perform integration testing to ensure correct functionality
   - [ ] Conduct code reviews and bug fixing
   - [ ] Optimize the codebase for performance and memory usage

9. **Finalizing the Project**
   - [x] Ensure the project adheres to the required specifications
   - [x] Double-check the codebase for any potential bugs or issues
   - [x] Clean up the repository and remove unnecessary files
   - [x] Prepare the project for submission or deployment

The above roadmap provides an overview of the planned tasks and their completion status for the Push_swap project. It serves as a guide to track progress and ensure that all necessary aspects of the project are addressed.


## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See [LICENSE](https://github.com/The-Intruder/Sorting-Algorithm-Optimizer-aka-Push_Swap/blob/main/LICENSE.md) for more information.

## Authors

* **Mohamed Amine Naimi** - *Comp Science Student* - [Mohamed Amine Naimi](https://github.com/The-Intruder/) - *Built the push_swap project*

## Acknowledgements

* [The-Intruder](https://github.com/The-Intruder/)
