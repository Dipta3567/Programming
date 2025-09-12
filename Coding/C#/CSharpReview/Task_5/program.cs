using System;
using System.ComponentModel.DataAnnotations; // needed for ValidationException

namespace Task5
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.Write("Enter numerator: ");
                int numerator = int.Parse(Console.ReadLine()!);

                Console.Write("Enter denominator: ");
                int denominator = int.Parse(Console.ReadLine()!);

                // check for negative numbers
                if (numerator < 0 || denominator < 0)
                    throw new ValidationException("Negative numbers are not allowed.");

                double result = (double)numerator / denominator;
                Console.WriteLine($"Result: {result}");
            }
            catch (FormatException)
            {
                Console.WriteLine("Invalid number input!");
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Cannot divide by zero!");
            }
            catch (ValidationException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("Program finished.");
            }
        }
    }
}
