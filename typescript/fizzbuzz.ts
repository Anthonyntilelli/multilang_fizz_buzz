const abort = function (errorMessage: string, exitCode: number) {
  // Prints to standard error and exits with exit code.
  console.error(errorMessage);
  process.exit(exitCode);
};

const convertToInt = function (value: string) {
  const int = Number(value);
  if (Number.isNaN(int)) abort(`Error: ${value} is not an integer`, 4);
  return int;
};

const checkDivisible = function (
  value: number,
  wordsObj: { word: string; divisor: number }[]
) {
  // Check is number is divisible and replace with word if it is.
  let output: string = "";
  for (let word of wordsObj) {
    if (value % word.divisor === 0) output += word.word;
  }
  if (output === "") output = value.toString();
  return output;
};

const wordPair = [
  { word: "Fizz", divisor: 3 },
  { word: "Buzz", divisor: 5 },
];

if (process.argv.length === 3) {
  console.log(checkDivisible(convertToInt(process.argv[2]), wordPair));
} else if (process.argv.length === 4) {
  const min = convertToInt(process.argv[2]);
  const max = convertToInt(process.argv[3]);
  if (min >= max) {
    abort(`Error:Bad range ${min} >= ${max}`, 5);
  }
  for (let i = min; i <= max; i++) {
    console.log(checkDivisible(i, wordPair));
  }
} else {
  abort("Error: Incorrect number of Arguments", 3);
}
