#!/usr/bin/node
/*
This script prints a square made of '#' characters with a specified size.

Usage: ./1-print_square.js <size>
Example: ./1-print_square.js 8
*/

/* Check if a command-line argument is provided */
if (process.argv.length <= 2)
{
/* Print error message & usage instructions if no argument is provided */
process.stderr.write("Missing argument\n");
process.stderr.write("Usage: ./1-print_square.js <size>\n");
process.stderr.write("Example: ./1-print_square.js 8\n");
/* Exit with error code 1 */
process.exit(1);
}

/* Parse the command-line argument as an integer */
size = parseInt(process.argv[2], 10);

/* Loop to print the square */
for (let row = 0 ; row < size ; row++)
{
/* Loop to print each row of the square */
for (let column = 0 ; column < size ; column++)
{
/* Print '#' character */
process.stdout.write("#");
}
/* Move to the next line after printing each row */
process.stdout.write("\n");
}
