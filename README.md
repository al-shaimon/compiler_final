# C Source Code Analyzer

![Version](https://img.shields.io/badge/version-2.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C-brightgreen.svg)
![License](https://img.shields.io/badge/license-Educational-green.svg)

A comprehensive tool for analyzing C source code to detect variable declarations, usage patterns,
and potential issues.

## Quick Start

```bash
# Clone or download the project
# Navigate to the compiler_final directory
cd compiler_final

# Compile the analyzer (Windows)
gcc -Wall -Wextra -std=c99 main.c symbol_table.c analyzer.c utils.c -o analyzer.exe

# If you get "Permission denied", delete the old file first:
# del analyzer.exe

# Run with a test file
echo test1.c | analyzer.exe
```

## Features

- **Variable Declaration Detection**: Identifies all variable declarations in C source files
- **Variable Usage Analysis**: Tracks how variables are used throughout the code
- **Unused Variable Detection**: Finds variables that are declared but never used
- **Undeclared Variable Detection**: Identifies variables used without proper declaration
- **Comment and String Filtering**: Intelligently ignores variables in comments and strings
- **Detailed Reporting**: Provides comprehensive analysis results with statistics
- **Cross-Platform Compatibility**: ASCII-only output ensures consistent display across all systems

## Project Structure

```text
compiler_final/
├── main.c           # Main program with enhanced UI
├── symbol_table.h   # Symbol table structure definitions
├── symbol_table.c   # Symbol table operations
├── analyzer.h       # Code analysis function declarations
├── analyzer.c       # Core analysis logic
├── utils.h          # Utility function declarations
├── utils.c          # Utility functions (keywords, comment stripping)
├── Makefile         # Build configuration
├── README.md        # This documentation
├── test1.c          # Basic test case with errors and warnings
├── test2.c          # Mixed data types test case
├── test3.c          # Complex syntax test case
└── test4.c          # Clean code test case
```

## Compilation

### Using Makefile (Linux/Mac)

```bash
make
```

**Note:** The Makefile is optimized for Linux/Mac systems. Windows users should use the manual
compilation method above.

### Manual Compilation

**Windows:**

```cmd
gcc -Wall -Wextra -std=c99 main.c symbol_table.c analyzer.c utils.c -o analyzer.exe
```

**Linux/Mac:**

```bash
gcc -Wall -Wextra -std=c99 main.c symbol_table.c analyzer.c utils.c -o analyzer
```

## Usage

1. Compile the program using one of the methods above
2. Run the analyzer:

   **Windows:**

   ```cmd
   analyzer.exe
   ```

   **Linux/Mac:**

   ```bash
   ./analyzer
   ```

3. Enter the filename when prompted (e.g., `test1.c`, `test2.c`, `test3.c`, or `test4.c`)
4. Review the detailed analysis results

## Running Test Cases

To test the analyzer with the provided test cases:

```bash
# Test basic error detection
echo test1.c | analyzer.exe

# Test mixed data types
echo test2.c | analyzer.exe

# Test complex syntax (shows parser limitations)
echo test3.c | analyzer.exe

# Test clean code scenario
echo test4.c | analyzer.exe
```

Each test case demonstrates different aspects of the analyzer's capabilities.

## Sample Output

```text
===================================================================
|                    C SOURCE CODE ANALYZER                      |
|                         Version 2.0                            |
|                                                                 |
|  Features:                                                      |
|  * Variable Declaration Detection                               |
|  * Variable Usage Analysis                                      |
|  * Unused Variable Detection                                    |
|  * Undeclared Variable Detection                                |
|  * Comment and String Filtering                                 |
===================================================================

>> Enter C source filename to analyze: test1.c

>> Starting analysis of file: test1.c
=========================================
>> Processing Line 3: int a, b, c;
>> Found variable declaration(s) of type 'int'
>> Variable 'a' declared successfully.
>> Variable 'b' declared successfully.
>> Variable 'c' declared successfully.
...
ERROR: Variable 'e' used without declaration.
WARNING: Variable 'c' is already declared.
...
>> ANALYSIS STATISTICS:
   * Total variables declared: 4
   * Variables used: 2
   * Variables unused: 2
```

## Supported C Features

- Variable declarations: `int`, `float`, `char`
- Multi-line and single-line comments
- String literals
- Function definitions
- Basic operators and expressions

## Files Description

### Core Files

- **main.c**: Enhanced main program with clean ASCII UI and detailed reporting
- **symbol_table.c/.h**: Manages the symbol table for tracking variables
- **analyzer.c/.h**: Contains the core logic for parsing and analyzing C code
- **utils.c/.h**: Utility functions for keyword detection and comment filtering

### Build Files

- **Makefile**: Automated build configuration
- **README.md**: Project documentation

### Test Files

- **test1.c**: Basic test case with variable errors and warnings

  - Contains: Undeclared variable usage, duplicate declarations, unused variables
  - Good for: Testing basic error detection capabilities

- **test2.c**: Mixed data types test case

  - Contains: `int`, `float`, `char` variables with some unused
  - Good for: Testing multi-type variable detection

- **test3.c**: Complex syntax test case

  - Contains: Variable initialization, arrays, complex expressions
  - Good for: Understanding parser limitations with advanced syntax

- **test4.c**: Clean code test case
  - Contains: Well-structured code with minimal issues
  - Good for: Testing ideal code scenarios

## Test Case Summary

| Test File | Variables | Used | Unused | Errors | Warnings | Purpose        |
| --------- | --------- | ---- | ------ | ------ | -------- | -------------- |
| test1.c   | 4         | 2    | 2      | 1      | 1        | Basic issues   |
| test2.c   | 5         | 3    | 2      | 0      | 0        | Mixed types    |
| test3.c   | 7\*       | 3    | 4      | 5      | 1        | Complex syntax |
| test4.c   | 7         | 6    | 1      | 0      | 0        | Clean code     |

\*Note: test3.c demonstrates parser limitations with complex declarations

## Troubleshooting

### Common Issues

1. **File Not Found Error**

   - Ensure the C file exists in the same directory as the analyzer
   - Check the filename spelling and extension

2. **Compilation Errors**

   - Make sure you have GCC installed
   - Use the exact compilation command provided
   - Check that all source files are present

3. **Permission Denied Error (Windows)**

   - If you get "Permission denied" when compiling, the .exe file is likely still running
   - Close any running instances of analyzer.exe
   - Delete the old analyzer.exe file: `del analyzer.exe`
   - Try compiling again
   - Alternative: Use `taskkill /F /IM analyzer.exe` to force-close the process

4. **Makefile Issues on Windows**

   - The provided Makefile works best on Linux/Mac
   - Windows users should use the manual compilation command instead
   - Consider using WSL (Windows Subsystem for Linux) for Makefile support

5. **Unexpected Parsing Results**
   - The analyzer works best with simple variable declarations
   - Complex syntax may not be parsed correctly (see Known Limitations)
   - Use test4.c as a reference for supported syntax

### Performance Notes

- Analysis time depends on file size and complexity
- Large files (>1000 lines) may take longer to process
- The analyzer is optimized for educational C code

## Technical Details

- **Maximum Variables**: 100 (configurable via MAX_VARIABLES)
- **Maximum Name Length**: 50 characters (configurable via MAX_NAME_LEN)
- **Comment Handling**: Supports both `//` and `/* */` style comments
- **String Handling**: Properly ignores variables within string literals

## Known Limitations

- **Variable Initialization**: Declarations like `int x = 5` may not parse correctly
- **Array Declarations**: Array syntax like `int arr[10]` may cause parsing issues
- **Complex Expressions**: Advanced C syntax may not be fully recognized
- **Function Parameters**: Function parameter variables are not currently tracked
- **Scope Handling**: All variables are treated as global scope
- **Preprocessor Directives**: Only basic `#include` handling

## Improvements in Version 2.0

1. **Modular Design**: Code split into logical modules for better maintainability
2. **Enhanced UI**: Clean console interface with ASCII formatting for universal compatibility
3. **Detailed Reporting**: Comprehensive statistics and recommendations
4. **Better Error Handling**: More informative error messages with clear indicators
5. **Build System**: Makefile for easy compilation
6. **Documentation**: Complete README with usage instructions and troubleshooting
7. **Multiple Test Cases**: Four different test scenarios covering various use cases
8. **Cross-Platform Compatibility**: ASCII-only output works on all systems
9. **Windows Compatibility**: Specific guidance for Windows compilation issues

## Contributing

Feel free to submit issues and enhancement requests!

## Future Enhancements

Potential improvements for future versions:

- **Enhanced Parser**: Better handling of complex C syntax
- **Scope Analysis**: Track variables within different scopes (functions, blocks)
- **Function Analysis**: Analyze function parameters and local variables
- **More Data Types**: Support for structs, unions, and custom types
- **Control Flow Analysis**: Track variables through if/else, loops
- **File Export**: Save analysis results to text or CSV files
- **GUI Interface**: Graphical user interface for easier use
- **Batch Processing**: Analyze multiple files at once

## License

This project is provided as-is for educational purposes.
