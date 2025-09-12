using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("How many numbers (at least 5)? ");
            int n;
            if (!int.TryParse(Console.ReadLine(), out n) || n < 5)
            {
                Console.WriteLine("You must enter at least 5 numbers. Program ending.");
                return;
            }

            int[] numbers = new int[n];
            for (int i = 0; i < n; i++)
            {
                Console.Write($"Enter number {i + 1}: ");
                while (!int.TryParse(Console.ReadLine(), out numbers[i])) { }
            }

            int sum = 0;
            int max = numbers[0], min = numbers[0];
            foreach (var num in numbers)
            {
                sum += num;
                if (num > max) max = num;
                if (num < min) min = num;
            }

            Console.WriteLine($"\nSum: {sum}");
            Console.WriteLine($"Maximum: {max}, Minimum: {min}");

            Console.Write("Reversed order: ");
            Array.Reverse(numbers);
            foreach (var num in numbers) Console.Write(num + " ");
            Console.WriteLine();
        }
    }
}
