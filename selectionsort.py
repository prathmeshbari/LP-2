def selection_sort(array):
    for i in range(len(array)):
        smallest = i
        for j in range(i + 1, len(array)):
            if array[j] < array[smallest]:
                smallest = j
        array[i], array[smallest] = array[smallest], array[i]

# Get input from the user
array = input("Enter a list of numbers, separated by commas: ").split(",")

# Convert the input to a list of integers
array = [int(x) for x in array]

# Sort the list using selection sort
selection_sort(array)

# Print the sorted list
print("The sorted list is:", array)