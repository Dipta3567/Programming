using System;
using System.Collections.Generic;

namespace Task4
{
    class Program
    {
        // check if a number is prime
        static bool IsPrime(int n)
        {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0) return false;
            return true;
        }

        // return all primes up to a number
        static int[] GetPrimes(int limit)
        {
            List<int> primes = new List<int>();
            for (int i = 2; i <= limit; i++)
            {
                if (IsPrime(i))
                    primes.Add(i);
            }
            return primes.ToArray();
        }

        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int num;
            while (!int.TryParse(Console.ReadLine(), out num)) { }

            if (IsPrime(num))
                Console.WriteLine($"{num} is prime.");
            else
                Console.WriteLine($"{num} is not prime.");

            int[] primes = GetPrimes(num);
            Console.WriteLine($"Primes up to {num}: {string.Join(", ", primes)}");
        }
    }
}
