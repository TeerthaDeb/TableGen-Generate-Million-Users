# TableGen For Assignment 1

TableGen is a simple User Management System implemented in C, designed for generating random users from provided details. You can create up to 10 million (safe value) users.

## Installation

1. Copy the code to a folder.

2. Ensure the following files are present: ["countries.txt", "email_suffixes.txt", "first_names.txt", "last_names.txt"] as they are essential for generating the table.

3. Navigate to the project directory:

```bash
cd YOUR-FOLDER-full-address
```

4. Compile the C files:

```bash
gcc tablegen.c io.c sort.c generate.c -o TableGen
```

5. Run the program:

```bash
./TableGen.out
```

For Windows users:

```bash
start TableGen.exe
```

## Usage

Running `TableGen` will prompt for input. Enter '1' to access the 'Main Menu', or any other key to exit the program using the `exit_code()` function.

### Main Menu

The Main Menu accepts commands separated by commas (,). Error checking is minimal, so be cautious with input. Note that users will be sorted based on the first selection.

## !!! Important: Generating email IDs before first and last names may result in incorrect emails. To generate email IDs, enter them after providing first and last names.

You will then be prompted to enter the number of rows (users) you want to generate. Valid range: (1 < x < 1M). Feel free to test higher values.

## !!! Important: Generating 1M users may take around 20 seconds due to slower file IO in C. A faster version is available in the 'Fastest' folder, but it requires compilation using an IDE like VSCode or Code::Blocks.

Next, provide a file name. An extension is not required .csv will be added automatically.

After completion, you'll be asked if you want to perform another operation. Press 'c' or 'C' to continue, or any other key to exit.

## !!! Warnings:

1. This is not the fastest version. For the fastest version, check the 'Fastest' folder. It can generate 1M users in less than 5 seconds, but requires compilation with an IDE.

2. Generating email IDs before first and last names may result in invalid emails, possibly from the previous user. Sorting by email IDs is not recommended.

3. Invalid input may cause program crashes, as there is minimal error checking.

4. During generation, ensure the files ["countries.txt", "email_suffixes.txt", "first_names.txt", "last_names.txt"] are located in the same directory.

## Note that:
	*.h files contains those functions which are needed outside the file. And Tablegen does not have a .h file.

## Thank You
Thank you for using and exploring my program.