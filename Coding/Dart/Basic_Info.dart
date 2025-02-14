void main()
{
    print("Hello World");
    print("This is my first Dart Program");


    // Comments in Dart
    // Single Line Comment
    /* Multi Line Comment */

    // Variables in Dart
    // var, dynamic, int, double, String, bool

    var name = "John"; // String
    var age = 25; // int
    var height = 5.9; // double
    var isEmployed = true; // bool

    final age1 = 25; // value can't be changed once assigned
    const pi =3.14159; // compile time constant

    dynamic value = 100; // dynamic type
    print(value);

    value = "Hello World";
    print(value);

    print(name);
    print(age);
    print(height);
    print(isEmployed);
    print(pi);

    
    // Data Types in Dart

    int count =10;
    double percentage = 90.5;
    String name1 = "John";
    bool isEmployed1 = true;
    value= 29;
    print (count.runtimeType); // output: int
    print (percentage.runtimeType); // output: double
    print (name1.runtimeType); // output: String
    print (isEmployed1.runtimeType); // output: bool
    print(value.runtimeType); // output: int

    value="Now it's a string";
    print(value.runtimeType); // output: String

    // new line print
    print("Hello \nWorld");
    print("Hello World ${name1}");
   
   age =25;
   if (age > 18)
   {
     print("You are eligible to vote");
   }
   else if (age == 18)
   {
     print("You are 18 years old");
   }
   else
   {
     print("You are not eligible to vote");
   }

    // Switch Case

    var grade = "A";
    switch(grade)
    {
      case "A": print("Excellent");
      break;

      case "B": print("Good");
      break;

      case "C": print("Fair");
      break;

      case "D": print("Poor");
      break;

      default: print("Invalid Grade");
      break;
    }

    // Loops in Dart
    // For Loop
    for (var i = 1; i <= 10; i++)
    {
      print(i);
    }

    // While Loop
    var i = 1;
    while (i <= 10)
    {
      print(i);
      i++;
    }

    // Do While Loop
    i = 1;
    do
    {
      print(i);
      i++;
    } while (i <= 10);


    // for each loop

    List<String> fruits = ["Apple", "Banana", "Mango", "Orange"];
    for (var u in fruits)
    {
      print(u);
    }

    fruits.forEach((f) => print(f));
    



}