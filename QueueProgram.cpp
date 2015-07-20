#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getUserInput();
//void addToVector();
void printVector(std::vector<std::string>);

int main ()
{
  std::vector<std::string> aVector = getUserInput();
  printVector(aVector);
  return 0;
}

std::vector<std::string> getUserInput()
{
  std::string input;
  std::vector<std::string> inputVector;
  do
  {  
    std::cout << "Type in some strings, type 'STOP' to stop:\n";
    std::getline(std::cin, input);
    if (input != "STOP")
    {
      inputVector.push_back(input);
    }
  } while (input != "STOP");
  std::cout << std::endl;
  return inputVector;
}

void printVector(std::vector<std::string> vect)
{
  for (int i = vect.size() - 1; i >= 0; i--)
  {
    std::cout << vect[i] << "\n";
  }
  std::cout << std::endl;
}