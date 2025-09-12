using System;
using System.Collections.Generic;
using System.Linq;

namespace Task6
{
    class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Marks { get; set; }

        public Student(int id, string name, int marks)
        {
            Id = id;
            Name = name;
            Marks = marks;
        }

        public string Grade
        {
            get
            {
                if (Marks >= 80) return "A";
                if (Marks >= 70) return "B";
                if (Marks >= 60) return "C";
                if (Marks >= 50) return "D";
                return "F";
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Student> students = new List<Student>();

            Console.Write("How many students? ");
            int n;
            while (!int.TryParse(Console.ReadLine(), out n) || n <= 0) { }

            for (int i = 0; i < n; i++)
            {
                Console.Write($"Student {i + 1} Id: ");
                int id;
                while (!int.TryParse(Console.ReadLine(), out id)) { }

                Console.Write($"Student {i + 1} Name: ");
                string name = Console.ReadLine() ?? "";

                Console.Write($"Student {i + 1} Marks: ");
                int marks;
                while (!int.TryParse(Console.ReadLine(), out marks) || marks < 0 || marks > 100) { }

                students.Add(new Student(id, name, marks));
            }

            // Average marks
            double average = students.Average(s => s.Marks);
            Console.WriteLine($"\nClass Average: {average:F2}");

            // Highest scorer
            Student top = students.OrderByDescending(s => s.Marks).First();
            Console.WriteLine($"Highest Scorer: {top.Name} (Marks: {top.Marks})");

            // Grade distribution
            int a = students.Count(s => s.Grade == "A");
            int b = students.Count(s => s.Grade == "B");
            int c = students.Count(s => s.Grade == "C");
            int d = students.Count(s => s.Grade == "D");
            int f = students.Count(s => s.Grade == "F");

            Console.WriteLine("\nGrade Distribution:");
            Console.WriteLine($"A: {a}");
            Console.WriteLine($"B: {b}");
            Console.WriteLine($"C: {c}");
            Console.WriteLine($"D: {d}");
            Console.WriteLine($"F: {f}");
        }
    }
}
