def get_int(user_input):
    while True:
        try:
            value = int(input(user_input))
            if 1 <= value <= 8:
                return value
        except ValueError:
            pass
        print("Please enter a positive integer between 1 and 8.")


def pyramid(height):
    for i in range(1, height+1):
        spaces = ' ' * (height - i)
        hashes = '#' * i
        print(f"{spaces}{hashes}  {hashes}")


height = get_int("Height: ")
pyramid(height)
