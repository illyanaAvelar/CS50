import re

def luhn_algorithm(card_number):
    total = 0
    reversed_digits = [int(digit) for digit in card_number[::-1]]

    for i, num in enumerate(reversed_digits):
        if i % 2 == 1:
            num *= 2
            if num > 9:
                num -= 9
        total += num

    return total % 10 == 0

def get_type(card_number):
    if not luhn_algorithm(card_number):
        return "INVALID"
    elif re.match(r"^3[47][0-9]{13}$", card_number):
        return "AMEX"
    elif re.match(r"^5[1-5][0-9]{14}$", card_number):
        return "MASTERCARD"
    elif re.match(r"^4[0-9]{12}(?:[0-9]{3})?$", card_number):
        return "VISA"
    return "INVALID"

card_number = input("Number: ").strip()
print(get_type(card_number))
