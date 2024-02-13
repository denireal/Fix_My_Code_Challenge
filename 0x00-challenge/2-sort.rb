###
# This script sorts a list of integers passed as command-line arguments
# and prints the sorted list.
###

# Initialize an empty array to store the sorted integers
result = []

# Iterate through each command-line argument
ARGV.each do |arg|
    # Skip if the argument is not an integer
    next if arg !~ /^-?[0-9]+$/

    # Convert the argument to an integer
    num = arg.to_i

    # Insert the integer at the right position in the sorted array
    inserted = false
    index = 0
    length = result.size
    while !inserted && index < length do
        if result[index] < num
            index += 1
        else
            result.insert(index, num)
            inserted = true
            break
        end
    end
    # Append the integer to the end of the array if it's not inserted yet
    result << num if !inserted
end

# Output the sorted array
puts result
