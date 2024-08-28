// Variable

var test = "Hello World"
var x = 5
console.log(test)
console.log(x)


// type of variable

console.log(typeof test)

// object

var obj = {
    name: "Sachin",
    age: 24
}
console.log(obj)
console.log(obj.name)

// parseFloat and parseInt

var num1 = "10.5"
var num2 = 20
var result = parseFloat(num1) + num2
console.log("Num1 is : ", typeof num1)
console.log(num1 + num2)
console.log(parseFloat(num1))
console.log(parseInt(num1))
console.log(result)

// if else

var age = 18
if (age > 18)
    console.log("You are eligible for vote")
else if (age == 18)
    console.log("You are 18")
else
    {
        console.log("You are not eligible for vote")
        console.log("You are under 18")
    }


// Array

var arr = [1, 2, 3, 4, 5]
console.log(arr)
console.log(arr[0])
console.log(arr.length)
arr.push(6)

var friend = ["Sachin", "Rahul", "Rohit", {name: "Virat", age: 30}]
console.log(friend)
console.log(friend[3].name)


// Loop

for (var i = 0; i < arr.length; i++)
    console.log(arr[i])

// while loop

var i = 0
while (i < arr.length)
    {
        console.log(arr[i])
        i++
    }



// Function

function add(a, b)
    {
        return a + b
    }

console.log(add(5, 10))

// Arrow Function

var add = (a, b) => a + b
console.log(add(5, 10))