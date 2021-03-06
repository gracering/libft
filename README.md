# libft
---
A customizable cross-platform standard library for C

<a href="https://github.com/LexouDuck/libft/actions">
	<img src="https://github.com/LexouDuck/libft/workflows/libft%20CI/badge.svg" />
</a>



### The Project
---
The objective is to have one simple, well-documented, efficient open-source implementation of the C standard library, but with easier to use functions and types than what is offered by the ISO standards - mostly by consistently handling undefined behaviors, and handling edge cases in a consistent, coherent way, so as to have code that is as little machine-specific as possible.

The first step to accomplishing this is to not use the native int/long/short types, which can have different storage size depending on the platform
('int' is defined as the fastest integer type for the given machine, typically this will be the CPU register size - so on a 64-bit machine, that'd be int64, on a 32-bit machine int32, and some old embedded systems you come across might have 16-bit ints as the machine's default storage size). So first of all, using the integer types defined in "inttypes.h" ('int32_t', 'uint64_t', etc) is essential for any cross-platform C code, as it ensures consistent cross-platform overflow behaviors.

Furthermore, there are other functions here that are not found in the ISO standard, particularly in the following categories:
* convert: functions to replace the wonky std libc atoi/itoa/atof/strtol functions with more understandable type-specific conversion functions
* io: functions for reading and writing (from/to terminal, or from/to file(s))
* color: functions for converting between different common color encodings, as well as other useful color-related functions (like blending colors, etc)
* random: a set of simple functions for different methods of pseudo-random number generation
* stringarray: a set of functions used to manipulate string arrays (`char **`), where the top-level pointer array is terminated by a NULL pointer
* stat: statistics & probabilities functions: int array sort functions, median, standard deviation, etc
* list: linked list functions (using a simple list type which only stores the 'next' pointer)
* vlq: Variable-Length Quantity math functions, for variable-size "big ints".



### Why does this exist ?
---
What started as a necessary exercise for the 42 school quickly became a much more expansive project: whereas the 42 libft project only requires students to code a certain set of important memory/string/io functions, we decided to take it further. Whereas libft is originally meant as an educational exercise, in which a student learns a lot by "reinventing wheels", here the goal is to have a standard C library which is fully cross-platform, uniformized, and customizable.



### Building
---
The Makefile simply builds a libft.a library to link to your project. (eg: something like `gcc main.c -I./libft/hdr/ -L./libft/ -lft`)

You can also add this git repo as a "git submodule" to your own if you wish (this allows you to be up to date to the latest version at all times).

In general though, we recommend having the source code and compiling it yourself (as there are important customization flags in `./hdr/libft.h` which change how the library is compiled). In particular:
- `LIBFTCONFIG_HANDLE_NULLPOINTERS`
	If 0, then libft functions will always segfault when given NULL pointers.
	If 1, then all NULL pointer accesses will be avoided, and an appropriate return value (eg:`NULL`, `0`, sometimes `-1`) will be returned.
- `LIBFTCONFIG_FAST_APPROX_MATH`
	If 1, the libft fast approximate functions will be used (precision error margin: 0.0001)
	If 0, the builtin FPU-call libc math functions will be used (eg: `__builtin_powf()`, etc)



### Testing
---
To ensure proper functionality of all these important functions in every edge case, a big testing program was implemented, featuring segfault handling and execution time comparison among other things.
You can test the libft by running `make test`: this will compile and run the test suite program from the files found in the 'test' folder.



### Contributing and Continuous Integration
---
Check `CONTRIBUTING.md`, this file serves as a "contributions style guide". We were alone at first so we wrote this code quick and dirty, but it'll do some good for us to have a coherent commit style for the whole team, so we'll follow these guidelines from now on. You should do the same.

// TODO add description of coding style to `CONTRIBUTING.md`


Every time a new commit/push is done, the automated CI testing job is run, as defined in `.github/workflows/ci.yml` (see the [official github documentation for Actions and Workflows to learn more](https://help.github.com/en/actions/reference/workflow-syntax-for-github-actions)).

This CI job builds everything with a `make`, and runs the testing suite with a `make test`. It runs with all of the following configurations:
- Ubuntu (gcc and clang)
- MacOS (gcc and clang)
- Windows (mingw-gcc)



### Build system
---
Cross-platform Makefile: builds a `libft.a` library file to link against.
The make commands are:


##### Building

##### `make` or `make all`
- Build the `libft.a` library file.


##### Checking/CI

##### `make libft_test`
- Builds a test software `libft_test`, which runs test suites on every libft function.

##### `make test`
- Builds `libft_test` and runs it without any arguments (running all tests).

##### `make lint`
- Runs CPPcheck on all source files

##### `make preprocessed`
- Fills the `./obj/` folder with `.c` files in their preprocessed state - this can help debug certain code macros, etc


##### Deleting

##### `make clean`
- Delete all object files in `./obj/` folder.

##### `make rclean`
- Delete all object files in `./obj/` folder, and the folder itself.

##### `make fclean`
- Delete all object files in `./obj/` folder, as well as the executable and library files.

##### `make tclean`
- Delete the test executable file, if present.

##### `make re`
- Does a `make fclean` followed by a `make`
