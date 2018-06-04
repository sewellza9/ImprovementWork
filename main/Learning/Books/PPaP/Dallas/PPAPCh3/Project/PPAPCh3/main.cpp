#include <iostream>
#include <cmath>
#include <string>

int main()
{
	////Part 1: Input
	//std::cout << "Put ya first name here. throw an age after it and press entah" << std::endl;
	//std::string first_name;
	//double age = -1.0;
	//std::cin >> first_name >> age;
	//std::cout << "Hello, " << first_name << " (age " << age << " year{s}, or " << age * 12 << " month{s})! Nice to meet ya!" << std::endl;


	////Part 2: Operators (ints)
	//std::cout << "enter floating point numba: ";
	//int n0;
	//std::cin >> n0;
	//std::cout << "n0 == " << n0
	//	<< std::endl << "n0 + 1 == " << n0 + 1
	//	<< std::endl << "three times n0 == " << 3 * n0
	//	<< std::endl << "twice n0 == " << n0 + n0
	//	<< std::endl << "n0 squared == " << n0 * n0
	//	<< std::endl << "n0 remainder 5 == " << n0 % 5
	//	<< std::endl << "half of n0 (int) == " << n0 / 2;
	//double n = n0;
	//std::cout << std::endl << "square root of n == " << std::sqrt(n)
	//	<< std::endl << "half of n0 (float) == " << n / 2
	//	<< std::endl;


	////Part 3: Operators (strings)
	//std::cout << "enter your full name" << std::endl;
	//std::string first;
	//std::string last;
	//std::cin >> first >> last;

	//std::string full_name = first + ' ' + last;
	//std::cout << "Hi, " << full_name << '!' << std::endl;

	//if (first == last)
	//{
	//	std::cout << "Your first name is the same as your last name!" << std::endl;
	//}
	//else if (first < last)
	//{
	//	std::cout << "Your first name is alphabetically before your last" << std::endl;
	//}
	//else if (first > last)
	//{
	//	std::cout << "Your first name is alphabetically after your last" << std::endl;
	//}


	////Part 4: Assignment vs Initialization
	//std::string previous = " ";
	//std::string current;
	//int number_of_words = 0;

	//while (std::cin >> current)
	//{
	//	++number_of_words;
	//	if (previous == current)
	//	{
	//		std::cout << current << " is a repeat: " << number_of_words << std::endl;
	//	}
	//	previous = current;
	//}


	////Part 5: Type Conversions
	//double d = 0.0;
	//while (std::cin >> d)
	//{
	//	//int i = d;
	//	char i = 'a';
	//	char c { i };
	//	int i2 = c;
	//	std::cout << "d==" << d
	//		<< " i==" << i
	//		<< " i2==" << i2
	//		<< " char(" << c << ")\n";
	//}


	////Drill
	//std::cout << "Enter the first name of the person you want to write to.\n";
	//std::string first_name;

	//std::cin >> first_name;

	//std::cout << "Dear " << first_name << ',' << std::endl;

	//std::cout << "\tYou already know.\n";

	//std::string friend_name;

	//std::cout << "Name a friend: ";
	//std::cin >> friend_name;
	//std::cout << "Have you seen " << friend_name << " lately?\n";

	//char friend_sex = 0;
	//std::cout << "Enter " << friend_name << "\'s sex: ";
	//std::cin >> friend_sex;

	//if (friend_sex == 'm')
	//{
	//	std::cout << "If you see " << friend_name << ", make sure to tell him that he's a nerd.\n";
	//}
	//else
	//{
	//	std::cout << "If you see " << friend_name << ", make sure to tell her that she's a nerd.\n";
	//}


	//int age = 0;
	//std::cout << "I know that " << friend_name << " just had a birthday. How old are they now?\n";
	//std::cin >> age;

	//if (age <= 0 || age >= 110)
	//{
	//	std::cout << "You're kidding!!\n";
	//}
	//else if (age < 12)
	//{
	//	std::cout << "Next year, they will be " << age + 1 << std::endl;
	//}
	//else if (age == 17)
	//{
	//	std::cout << "Next year, they will be able to vote!\n";
	//}
	//else if (age > 70)
	//{
	//	std::cout << "I hope they are enjoying retirement.\n";
	//}

	//std::cout << "Yours Sincerely,\n\nDallas\n";


	//Exercise 1: Do the "Try This" segments. already done
	////Exercise 2:
	//std::cout << "Please enter a number of miles (double): ";

	//double miles = 0.0;
	//std::cin >> miles;

	//std::cout << miles << " miles is " << miles * 1.609 << " kilometers.\n";


	////Exercise 3:
	//int double = 0;
	//int 9_ways = 9;
	//int true = 0;
	//int aosl& = 0;
	//int _12ka = 0;
	//int int = 0;
	//int compiler = 0;


	////Exercise 4/5:
	//std::cout << "Please enter two non-zero numbers (doubles): ";
	//double val1 = 0;
	//double val2 = 0;

	//std::cin >> val1 >> val2;

	//std::cout << "Smaller = " << (val1 <= val2 ? val1 : val2)
	//	<< std::endl << "Larger = " << (val1 <= val2 ? val2 : val1)
	//	<< std::endl << "Sum = " << val1 + val2
	//	<< std::endl << "Difference = " << std::abs(val1 - val2)
	//	<< std::endl << "Product = " << val1 * val2
	//	<< std::endl << "Ratio = " << val1 / val2
	//	<< std::endl;

	////Exercise 6:
	//std::cout << "Please enter three numbers: ";
	//int num1 = 0;
	//int num2 = 0;
	//int num3 = 0;

	//std::cin >> num1 >> num2 >> num3;

	//int smallest = INT_MIN;
	//int middle = 0;
	//int largest = INT_MAX;

	//if (num1 < num2)
	//{
	//	if (num1 < num3)
	//	{
	//		smallest = num1;

	//		middle = num2 < num3 ? num2 : num3;
	//		largest = num2 < num3 ? num3 : num2;
	//	}
	//	else
	//	{
	//		smallest = num3;

	//		middle = num1;
	//		largest = num2;
	//	}
	//}
	//else
	//{
	//	if (num2 < num3)
	//	{
	//		smallest = num2;

	//		middle = num1 < num3 ? num1 : num3;
	//		largest = num1 < num3 ? num3 : num1;
	//	}
	//	else
	//	{
	//		smallest = num3;

	//		middle = num2;
	//		largest = num1;
	//	}
	//}

	//std::cout << "Smallest: " << smallest << std::endl;
	//std::cout << "Middle: " << middle << std::endl;
	//std::cout << "Largest: " << largest << std::endl;

	////Exercise 7
	//std::cout << "Please enter three strings: ";
	//std::string string1 = "";
	//std::string string2 = "";
	//std::string string3 = "";

	//std::cin >> string1 >> string2 >> string3;

	//std::string smallest = "";
	//std::string middle = "";
	//std::string largest = "";

	//if (string1 < string2)
	//{
	//	if (string1 < string3)
	//	{
	//		smallest = string1;

	//		middle = string2 < string3 ? string2 : string3;
	//		largest = string2 < string3 ? string3 : string2;
	//	}
	//	else
	//	{
	//		smallest = string3;

	//		middle = string1;
	//		largest = string2;
	//	}
	//}
	//else
	//{
	//	if (string2 < string3)
	//	{
	//		smallest = string2;

	//		middle = string1 < string3 ? string1 : string3;
	//		largest = string1 < string3 ? string3 : string1;
	//	}
	//	else
	//	{
	//		smallest = string3;

	//		middle = string2;
	//		largest = string1;
	//	}
	//}

	//std::cout << "Smallest: " << smallest << std::endl;
	//std::cout << "Middle: " << middle << std::endl;
	//std::cout << "Largest: " << largest << std::endl;


	////Exercise 8:
	//std::cout << "Please enter a number (int): ";
	//int num = 0;
	//std::cin >> num;

	//if (num == 0)
	//{
	//	std::cout << "The number " << num << " is neither odd nor even." << std::endl;
	//}
	//else if (num % 2 == 0)
	//{
	//	std::cout << "The number " << num << " is even!" << std::endl;
	//}
	//else
	//{
	//	std::cout << "The number " << num << " is odd!" << std::endl;
	//}


	////Exercise 9:
	//std::cout << "Hello, I am a but a fresh computer and I'm unused to computing. Will you please help me become a better computer?" << std::endl;

	//while (true)
	//{
	//	std::string answer = "";
	//	std::cin >> answer;
	//	if (answer == "n" || answer == "N" || answer == "No" || answer == "no" || answer == "NO")
	//	{
	//		std::cout << "\noh...ok...\n\ngood-bye then...\n" << std::endl;
	//		break;
	//	}
	//	else if (answer == "y" || answer == "Y" || answer == "Yes" || answer == "yes" || answer == "YES")
	//	{
	//		std::cout << "\nOH! :D Goodie! Thank you very much!! :D" <<
	//			std::endl << "Then let us proceed." <<
	//			std::endl << "Please tell me the name of a number and I'll try to convert it to the arabic numeral: ";
	//		std::string number;
	//		std::cin >> number;

	//		if (number == "zero" || number == "Zero" || number == "ZERO")
	//		{
	//			std::cout << "\nOh, that's easy!!! I know this one! It's 0! :D!!!" << std::endl;
	//		}
	//		else if (number == "one" || number == "One" || number == "ONE")
	//		{
	//			std::cout << "\nYep! I totally know this one. That's 1!" << std::endl;
	//		}
	//		else if (number == "two" || number == "Two" || number == "TWO")
	//		{
	//			std::cout << "\nHmmmm. I'm pretty sure that this one is 2" << std::endl;
	//		}
	//		else if (number == "three" || number == "Three" || number == "THREE")
	//		{
	//			std::cout << "\nOh...Uhmmm...Hmmmmm. I think this one is...3?...Yeah, 3." << std::endl;
	//		}
	//		else if (number == "four" || number == "Four" || number == "FOUR")
	//		{
	//			std::cout << "\n???..." << number << "?......i'm not sure. I don't think I've heard that one before..." <<
	//				std::endl << "I'm sorry...but I really just ca-...wait...hold up..." <<
	//				std::endl << number << "..." << number << "..." << "4!! " << number << " is 4! It's gotta be!" <<
	//				std::endl;
	//		}
	//		else
	//		{
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "i'm sorry" << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "..." << std::endl;
	//			std::cout << "i really don't know this one..." << std::endl;
	//			std::cout << "i'm such a failure as a computer...i'm sorry...i'll just leave...thanks for trying..." << std::endl;
	//			std::cout << "\ngood-bye\n\n";
	//		}
	//		break;
	//	}
	//	else
	//	{
	//		std::cout << "\nI'm sorry...I just...don't quite understand what you're trying to tell me." <<
	//			std::endl << "Could you maybe phrase that differently please?" << std::endl;
	//	}
	//}


	////Exercise 10:
	//std::cout << "Please enter an operation followed by two operands (non-zero): ";
	//std::string oper;
	//double operand1;
	//double operand2;

	//std::cin >> oper >> operand1 >> operand2;

	//if (oper == "+" || oper == "plus")
	//{
	//	std::cout << operand1 << " " << oper << " " << operand2 << " = " << operand1 + operand2 << std::endl;
	//}
	//else if (oper == "-" || oper == "minus")
	//{
	//	std::cout << operand1 << " " << oper << " " << operand2 << " = " << operand1 - operand2 << std::endl;
	//}
	//else if (oper == "*" || oper == "mul")
	//{
	//	std::cout << operand1 << " " << oper << " " << operand2 << " = " << operand1 * operand2 << std::endl;
	//}
	//else if (oper == "/" || oper == "div")
	//{
	//	std::cout << operand1 << " " << oper << " " << operand2 << " = " << operand1 / operand2 << std::endl;
	//}
	//else
	//{
	//	std::cout << "Not a supported operator." << std::endl;
	//}


	////Exercise 11:
	//int pennies = 0;
	//int nickels = 0;
	//int dimes = 0;
	//int quarters = 0;
	//int half_dollars = 0;

	//std::cout << "How many pennies do you have: ";
	//std::cin >> pennies;
	//std::cout << "How many nickels do you have: ";
	//std::cin >> nickels;
	//std::cout << "How many dimes do you have: ";
	//std::cin >> dimes;
	//std::cout << "How many quarters do you have: ";
	//std::cin >> quarters;
	//std::cout << "How many half_dollars do you have: ";
	//std::cin >> half_dollars;

	//if (pennies < 0)
	//{
	//	pennies = 0;
	//}
	//if (nickels < 0)
	//{
	//	nickels = 0;
	//}
	//if (dimes < 0)
	//{
	//	dimes = 0;
	//}
	//if (quarters < 0)
	//{
	//	quarters = 0;
	//}
	//if (half_dollars < 0)
	//{
	//	half_dollars = 0;
	//}


	//if (pennies == 1)
	//{
	//	std::cout << "You have " << pennies << " penny" << std::endl;
	//}
	//else
	//{
	//	std::cout << "You have " << pennies << " pennies" << std::endl;
	//}
	//if (nickels == 1)
	//{
	//	std::cout << "You have " << nickels << " nickel" << std::endl;
	//}
	//else
	//{
	//	std::cout << "You have " << nickels << " nickels" << std::endl;
	//}
	//if (dimes == 1)
	//{
	//	std::cout << "You have " << dimes << " dime" << std::endl;
	//}
	//else
	//{
	//	std::cout << "You have " << dimes << " dimes" << std::endl;
	//}
	//if (quarters == 1)
	//{
	//	std::cout << "You have " << quarters << " quarter" << std::endl;
	//}
	//else
	//{
	//	std::cout << "You have " << quarters << " quarters" << std::endl;
	//}
	//if (half_dollars == 1)
	//{
	//	std::cout << "You have " << half_dollars << " half_dollar" << std::endl;
	//}
	//else
	//{
	//	std::cout << "You have " << half_dollars << " half_dollars" << std::endl;
	//}


	//double total = 0;

	//if (pennies != 0)
	//{
	//	total += static_cast<double>(pennies) / 100;
	//}
	//if (nickels!= 0)
	//{
	//	total += static_cast<double>(nickels) / 20;
	//}
	//if (dimes != 0)
	//{
	//	total += static_cast<double>(dimes) / 10;
	//}
	//if (quarters != 0)
	//{
	//	total += static_cast<double>(quarters) / 4;
	//}
	//if (half_dollars != 0)
	//{
	//	total += static_cast<double>(half_dollars) / 2;
	//}

	//std::cout << "You have a total of $" << total << '.' << std::endl;

	system("Pause");
	return 0;
}