#!/usr/bin/python3

'''
Based on the Fizz Buzz game that outputs

Prints out string in place of number based `WORDS` variable

'''
import sys

def abort(error_message, exitcode):
    """
    Prints to standard error and stops with desired exit code
    """
    print(error_message, file=sys.stderr)
    sys.exit(exitcode)

def convert_to_int(value):
    '''
    Converts value to int

    Catches Value Error exception and exits program with a 4
    '''
    try:
        return int(value)
    except ValueError:
        abort("Error: `{}` is not an integer".format(value), 4)


def check_divisible(value, words):
    '''
    Check is number is divisible and replace with word if it is.
    '''
    assert type(value) == int
    assert type(words) == tuple

    processed = ''
    for key, number in words:
        if value % number == 0:
            processed += str(key)

    if processed == '':
        processed = value

    return processed

WORDS = (('Fizz', 3), ('Buzz', 5))
# (string:divisible_integer)

INPUT_ = sys.argv
COUNT_INPUT_ = len(INPUT_)

if COUNT_INPUT_ == 2: #INT
    print(check_divisible(convert_to_int(INPUT_[1]), WORDS))

elif COUNT_INPUT_ == 3: #MIN/MAX
    MIN_ = convert_to_int(INPUT_[1])
    MAX_ = convert_to_int(INPUT_[2])
    if MIN_ >= MAX_:
        abort("Error:Bad range {} >= {}".format(MIN_, MAX_), 5)
    for num in range(MIN_, MAX_+1):
        print(check_divisible(num, WORDS))

else:  # Too many or few arguments
    abort("Error: Incorrect number of Arguments", 3)

exit()
