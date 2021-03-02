# Sets words and divisible check
WORDS = { Fizz: 3, Buzz: 5 }.freeze
# { word:divisible_integer }

num = []
# num[0] is min and num[1] is max
abort('Max 2 arguments') if ARGV.size > 2

ARGV.each_with_index do |input, index|
  case input
  when /^-[[:digit:]]+$/ # negative number
    num[index] = input.to_i
  when /[^[[:digit:]]]/
    abort("Error: Non-integer input -> #{input} <-")
  when /[[:digit:]]/
    num[index] = input.to_i
  else
    abort("Error: Invalid input entered -> #{input} <-")
  end
end
ARGV.clear

num[0] ||= 0
num[1] ||= (num[0] + 10)

abort("ERROR:Bad range #{num[0]} >= #{num[1]}") if num[0] >= num[1]

(num[0]..num[1]).each do |value|
  output = nil
  WORDS.each do |key, test|
    break if value.zero?
    output = output.to_s + key.to_s if (value % test).zero?
  end
  puts(output || value) # prints value when output is nil
end
