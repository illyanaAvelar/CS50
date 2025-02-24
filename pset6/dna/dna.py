import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database.csv> <sequence.txt>")
        sys.exit(1)

    # Read database file into a variable
    database_filename = sys.argv[1]
    sequence_filename = sys.argv[2]

    with open(database_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        database = list(reader)

    # Read DNA sequence file into a variable
    with open(sequence_filename, 'r') as seqfile:
        sequence = seqfile.read().strip()

    # Find longest match of each STR in DNA sequence
    str_list = database[0].keys()
    str_counts = {}

    for str_name in str_list:
        if str_name != "name":
            str_counts[str_name] = longest_match(sequence, str_name)


    # Check database for matching profiles
    for profile in database:
        match = True
        for str_name in str_list:
            if str_name != "name" and int(profile[str_name]) != str_counts[str_name]:
                match = False
                break

        if match:
            print(profile["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
