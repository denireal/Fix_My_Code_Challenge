#!/usr/bin/python3
import sys


# Function to generate FizzBuzz sequence
def fizzbuzz(n):
    # Check if the input number is less than 1
    if n < 1:
        return

    # Initialize an empty list to store the FizzBuzz sequence
    result = []

    # Iterate from 1 to n (inclusive)
    for num in range(1, n + 1):
        # Check divisibility by 3 and 5
        if (num % 3) == 0 and (num % 5) == 0:
            # Append "FizzBuzz" if divisible by both 3 and 5
            result.append("FizzBuzz")
        # Check divisibility by 3
        elif (num % 3) == 0:
            # Append "Fizz" if divisible by 3
            result.append("Fizz")
        # Check divisibility by 5
        elif (num % 5) == 0:
            # Append "Buzz" if divisible by 5
            result.append("Buzz")
        else:
            # Append the number itself if not divisible by either 3 or 5
            result.append(str(num))
    
    # Print the FizzBuzz sequence as a space-separated string
    print(" ".join(result))


if __name__ == '__main__':
    # Check if a command-line argument is provided
    if len(sys.argv) <= 1:
        # Print error message & usage instructions if no argument is provided
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 89")
        # Exit with error code 1
        sys.exit(1)

    # Convert the command-line argument to an integer
    num = int(sys.argv[1])
    # Generate and print the FizzBuzz sequence
    fizzbuzz(num)
