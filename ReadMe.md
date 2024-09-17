# Swedish Identification Number Validator

This project is a validator for Swedish identification numbers: `personnummer`, `samordningsnummer`, and `organisationsnummer`. It validates these numbers based on the Luhn algorithm and various other rules specific to each type of number. The program takes an input file containing identification numbers and outputs the validation result.

## Features

- **Personnummer Validation**: Validates Swedish personal identification numbers.
- **Samordningsnummer Validation**: Validates coordination numbers used for individuals without personal numbers.
- **Organisationsnummer Validation**: Validates organizational numbers for companies and other entities.

## Prerequisites

To compile and run the project, you need:

- A C++ compiler (e.g., `g++`).
- Make installed on your system.

## Installation

1. Clone or download this repository.
2. Ensure that you have an `input.txt` file in the project directory with the identification numbers you want to validate, one per line, like so:

   ```txt
   201701102384
   141206-2380
   20080903-2386

3. Compile the project using the `makefile` provided.

### Compilation

To compile the project, run the following command in the terminal:

```bash
make
```

This will generate an executable file named `main`.

### Running the Program

Once the project is compiled, you can run the executable to validate the numbers in `input.txt`:

```bash
./main
```
The program will read from `input.txt` and output the validation results for each identification number, for example:

```bash
Personnummer:
201701102384 Giltigt
Samordningsnummer:
190910799824 Ogiltigt: kontrollsiffra
Organisationsnummer:
556614-3185 Giltigt
```

### Changing the Input File

If you want to use a different input file, modify the filename in the `main.cpp` file where the input file is opened:

```cpp
std::ifstream inputFile("input.txt");
```

### Cleaning Up

To clean up the project files, including the compiled binaries and object files, run the following command:

```bash
make clean
```

This command will remove the generated executable (`main`), object files, and any other temporary files created during the build process, ensuring that the directory is clean.

## File Structure

- **`main.cpp`**: Contains the main program logic that handles input and manages the validation process.
- **`Identifier.cpp` / `Identifier.h`**: Defines the base class for the different types of identification number validations.
- **`Personnummer.cpp` / `Personnummer.h`**: Implements the logic for validating Swedish personal identification numbers (`personnummer`).
- **`Samordningsnummer.cpp` / `Samordningsnummer.h`**: Implements the logic for validating Swedish coordination numbers (`samordningsnummer`).
- **`Organisationsnummer.cpp` / `Organisationsnummer.h`**: Implements the logic for validating Swedish organizational numbers (`organisationsnummer`).
