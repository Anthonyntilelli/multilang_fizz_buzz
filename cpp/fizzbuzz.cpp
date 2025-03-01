#include <iostream>
#include <map>
#include <string>
#include <stdexcept> 

// Word List
const std::map<int, std::string> WORDS = {{3, "Fizz"}, {5, "Buzz"}};

// Attempt to convert a string into an int.
// It will exit program if the conversion fails.
int intCheckConvert(const std::string &value){
    int new_int{};
    try{
        new_int = std::stoi(value);
    } catch(const std::invalid_argument& _){
        std::cerr << "Error: `" << value << "` is not an integer" << std::endl;
        exit(4);
      } catch(const std::out_of_range& _) {
        std::cerr << "Error: `" << value << "` is out of range for an integer" << std::endl;
        exit(4);
      }
    return new_int;
}

// Check if value is divisable to number and outputs word or number to standard out.
void checkDivisible(int value){
  std::string processed {};
  for (auto& [key, word]: WORDS) if(value % key == 0) processed += word;
  if (processed.empty()) std::cout << value << std::endl;
  else std::cout << processed << std::endl;
}

int main(int argc, char* argv[]){
  // First argument is programs name.
  switch(argc){
    case 2: // One Number provided
      checkDivisible(intCheckConvert(argv[1]));
      break;
    case 3: { // two Number provided
      const int min = intCheckConvert(argv[1]);
      const int max = intCheckConvert(argv[2]);
      if (min >= max) {
        std::cerr << "Error: Bad range " << min << " >= " << max << std::endl;
        std::exit(5);
      }
      for(int i = min; i <= max; i++) checkDivisible(i);
    }
      break;
    default:
      std::cerr << "Error: Incorrect number of Arguments" << std::endl;
      std::exit(3);
      break;
  }
  return 0;
}