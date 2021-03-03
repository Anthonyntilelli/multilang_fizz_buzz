package main

import (
	"fmt"
	"os"
	"strconv"
)

type wordPair struct {
	word   string
	number int
}

// Words should be in count order
var words = [...]wordPair{{"Fizz", 3}, {"Buzz", 5}}

func main() {
	if len(os.Args) == 2 { // INT
		checkDivisible(stringToiOrError(os.Args[1]))
	} else if len(os.Args) == 3 { // MIN/MAX
		min, max := stringToiOrError(os.Args[1]), stringToiOrError(os.Args[2])
		for i := min; i <= max; i++ {
			checkDivisible(i)
		}
		if min >= max {
			abort("Error:Bad range "+os.Args[1]+" >= "+os.Args[2], 5)
		}
	} else {
		abort("Error: Incorrect number of Arguments", 3)
	}
}

// Exits program by sending error message to standard error and specified error code.
func abort(errorMessage string, exitcode int) {
	fmt.Fprintln(os.Stderr, errorMessage)
	os.Exit(exitcode)
}

// Attempts to convert sting to integer or aborts program
func stringToiOrError(arg string) int {
	i, err := strconv.Atoi(arg)
	if err != nil {
		abort("Error: "+arg+"is not an integer", 4)
	}
	return i
}

// Check if value is divisable to number and outputs word or number to standard out.
func checkDivisible(value int) {
	processed := ""
	for _, check := range words {
		if value%check.number == 0 {
			processed += check.word
		}
	}
	if processed == "" {
		fmt.Println(value)
	} else {
		fmt.Println(processed)
	}

}
