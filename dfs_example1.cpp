#include <iostream>
#include <string>
#include <vector>


/*
This program finds all the possible letter combinations for a given phone number.
Note: The numbers '0' and '1' are not associated with any letters

Summary: dfs using recursion
*/

//                           Index:  0   1     2      3      4      5      6      7       8      9
std::vector<std::string> digitMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateStrings(std::vector<std::string>& solutions, std::string& digits, std::vector<std::string>& digitMap, int index, std::string curr)
{
	if (curr.length() == digits.length())
	{
		solutions.push_back(curr);
		return;
	}

	std::string possibilities = digitMap[digits[index] - '0'];

	for (int i = 0; i < possibilities.length(); i++)
		generateStrings(solutions, digits, digitMap, index + 1, curr + possibilities[i]);
}

int main()
{
	std::vector<std::string> solutions;

	std::string number = "222";
	std::string empty = "";

	generateStrings(solutions, number, digitMap, 0, empty);

	for (int i = 0; i < solutions.size(); i++)
		std::cout << solutions[i] << std::endl;



	return 0;
}