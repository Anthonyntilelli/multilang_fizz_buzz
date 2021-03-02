# Fizz_buzz - [Fizzbuzz](https://en.wikipedia.org/wiki/Fizz_buzz) game written in ruby
## Table of Contents
1. [Description](#Description)
2. [Parameters](#Parameters)
3. [Examples](#Examples)
4. [Exit status](#Exit_status)
5. [Authors](#Authors)
6. [Reference](#Reference)

## Description                <a name= "Description"></a>
  Based on a game to teach division to children. `Fizz` is outputted on any integers divisible by 3 and `Buzz`
  if divisible by 5. Any integers that are divisible by both with get `Fizz Buzz`. Non-integer inputs will cause program to abort.

## Parameters:               <a name="Parameters"></a>
  ruby fizzbuzz.rb MIN MAX

    MIN - integer to begin fizz buzz range on
    MAX - last integer to end the range on
    Max is optional, if not provided, the range is set min + 10. 

## Examples:                 <a name="Examples"></a>
`ruby fizzbuzz.rb 10`

`ruby fizzbuzz.rb 10 25`

## Exit status:              <a name="Exit_status"></a>

     0  Success
     1 General Failure or incorrect parameter provided (varied Message)

## Authors:                  <a name="Authors"></a>
- Anthony Tilelli
