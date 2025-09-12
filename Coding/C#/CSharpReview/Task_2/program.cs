using System;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter your age: ");
            int age;
            while (!int.TryParse(Console.ReadLine(), out age) || age < 0)
            {
                Console.Write("Invalid input. Enter age again: ");
            }

            // Using if-else
            Console.WriteLine("\nUsing if-else:");
            if (age < 13)
                Console.WriteLine("Child");
            else if (age <= 19)
                Console.WriteLine("Teenager");
            else if (age <= 59)
                Console.WriteLine("Adult");
            else
                Console.WriteLine("Senior Citizen");

            // Using switch-case with pattern matching
            Console.WriteLine("\nUsing switch-case:");
            switch (age)
            {
                case < 13:
                    Console.WriteLine("Child");
                    break;
                case <= 19:
                    Console.WriteLine("Teenager");
                    break;
                case <= 59:
                    Console.WriteLine("Adult");
                    break;
                default:
                    Console.WriteLine("Senior Citizen");
                    break;
            }
        }
    }
}
