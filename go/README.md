# Fizz_buzz - [Fizzbuzz](https://en.wikipedia.org/wiki/Fizz_buzz) game written in go

## Table of Contents

1. [Description](#Description)
2. [Parameters](#Parameters)
3. [Build](#Build)
4. [Examples](#Examples)
5. [Exit status](#Exit_status)
6. [Authors](#Authors)

## Description                <a name= "Description"></a>

  Based on a game to teach division to children. `Fizz` is outputted on any integers divisible by 3 and `Buzz`
  if divisible by 5. Any integers that are divisible by both with get `Fizz Buzz`. The game can be expanded to
  include other numbers and string responses. Non-integer inputs will cause program to abort.

## Parameters:               <a name="Parameters"></a>

  fixbuzz INT

    INT - integer for fizz buzz to check

  fizzbuzz MIN MAX

    MIN - integer to begin fizz buzz range on
    MAX - last integer to end the range on

## Build                     <a name="Build"></a>

`go build fizzbuzz.go`

## Examples:                 <a name="Examples"></a>

`fizzbuzz 10`

`fizzbuzz 10 25`

## Exit status:              <a name="Exit_status"></a>

     0 Success
     1 General Failure (varied Message)
     3 Error: Incorrect number of Arguments
     4 Error: `input` is not an integer
     5 Error: Bad range `min` >= `max`

## Authors:                  <a name="Authors"></a>

- Anthony Tilelli
