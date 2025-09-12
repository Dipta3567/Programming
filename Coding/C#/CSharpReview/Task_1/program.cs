using System;
using System.ComponentModel.DataAnnotations;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "";
            int age;

            while (true)
            {
                try
                {
                    Console.Write("Enter your name: ");
                    name = Console.ReadLine() ?? "";

                    Console.Write("Enter your age: ");
                    string? input = Console.ReadLine();

                    if (!int.TryParse(input, out age))
                        throw new FormatException("Age must be a number.");

                    if (string.IsNullOrWhiteSpace(name) || age < 0)
                        throw new ValidationException("Invalid input! Name cannot be empty and age cannot be negative.");

                    Console.WriteLine($"Hello {name}, you are {age} years old.");
                    break;
                }
                catch (FormatException ex)
                {
                    Console.WriteLine(ex.Message + " Try again.");
                }
                catch (ValidationException ex)
                {
                    Console.WriteLine(ex.Message + " Try again.");
                }
            }
        }
    }
}
