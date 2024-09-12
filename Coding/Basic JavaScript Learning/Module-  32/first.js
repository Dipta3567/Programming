//  MODULE -32 

//  TOPIC - COMMON CONCEPTS OF JS


//  STRONG TYPE  VS DYNAMIC TYPE

// STRONG TYPE = JESOB VARIABLE KE DECLARE KORTE EDER TYPE DIYE DECLARE KORTE HOI..

// int a = 10 ;

// double b = 10.5  etc



//  Dynamic => jader type charai let , var, const diye declare kora jai.

let a = 10 ;

let b = 10.5 ;


//  ******** PRIMITIVE     VS    NON - PRIMITIVE *********

// PRIMITIVE => VARIABLE E EKTA VALUE RAKEHE. => LET A = 10 ; LET B ="AFFNAN" .... BOOLEAN , STRING , NUMBER ETC..


// NON-PRIMITIVE : VARIABLE E ONEKGULO VALUE RAKHE. LET A = [1,2,3].=> ARRAY, OBJECT...


// UNDEFINED.

// 1. VARIABLE E VALUE NA THAKLE .

// RETURN NA KORLE .

// RETURN E KI RETURN KORBO SETA NA DILE . 

// OBJECT E J PROPERTY NAI / ARRAY TE J INDEX NAI SETA CONSOLE LOG KORLE.

// ARGUMENT E MAN NA DILE , JDI PARAMTR E DEFAULT VALUEO NA THAKE TAILE UNDEFINED DEI....

// UNDEFINED R TYPE = UNDEFINED .

// NULL ER TYPE = OBJECT ...  [ THROUGH IT IS CONTROVERSIAL]



//  ******* TRUTHY  VS  FALSY **********

// JEKONO NUMBER , TRUTHY.. EXCEPT 0 .
// EMPTY ARRAY , OBJECT ETC ....

let x = 10 ;

if (x){
    console.log("it is truthy");
}
else{
    console.log("it is falsy");
}


// falsy => 0 hole falsy ... empty string , null , undefined hole falsy..




////  ==  vs ==== 


// ==  just value  check kore..  etate type casting , conversion , corcein o hoi...


// ====  , value + type of variable check kore.. it is advanced.


// In JavaScript, scope refers to the current context of execution in which values and expressions are "visible" or can be referenced. Scopes can be broadly categorized into global scope and block scope.

// Global Scope
// Variables declared outside any function or block are in the global scope. They can be accessed from anywhere in the code.

// Example:

// javascript
// Copy code
// var globalVar = "I am a global variable";

// function showGlobalVar() {
//     console.log(globalVar); // Accessible here
// }

// showGlobalVar(); // Output: I am a global variable
// console.log(globalVar); // Accessible here as well


// Block Scope
// Variables declared with let or const inside a block (e.g., inside {}) are in block scope. They can only be accessed within that block.

// Example:

// javascript
// Copy code
// function showBlockScope() {
//     if (true) {
//         let blockVar = "I am a block-scoped variable";
//         console.log(blockVar); // Accessible here
//     }
//     // console.log(blockVar); // Error: blockVar is not defined
// }

// showBlockScope();
// In the block scope example, the variable blockVar is only accessible within the if block where it is declared. Attempting to access it outside that block results in an error.





//  CLOUSURE , ENCAPSULATION , PRIVATE VARIABLE

// ### Closure
// A closure in JavaScript is a feature where an inner function has access to the outer (enclosing) function's variables. This allows the function to retain access to its lexical scope, even when the function is executed outside that scope.

// **Example:**
// ```javascript
// function outerFunction() {
//     let outerVariable = "I'm an outer variable";

//     function innerFunction() {
//         console.log(outerVariable); // Inner function accessing outer function's variable
//     }

//     return innerFunction;
// }

// const myClosure = outerFunction();
// myClosure(); // Output: I'm an outer variable
// ```

// ### Encapsulation
// Encapsulation is the concept of bundling the data (variables) and methods (functions) that operate on the data into a single unit or object, and restricting access to some of the object's components. This is typically achieved using closures and immediately invoked function expressions (IIFEs) to create private variables and methods.

// **Example:**
// ```javascript
// function createCounter() {
//     let count = 0; // Private variable

//     return {
//         increment: function() {
//             count++;
//             return count;
//         },
//         decrement: function() {
//             count--;
//             return count;
//         },
//         getCount: function() {
//             return count;
//         }
//     };
// }

// const counter = createCounter();
// console.log(counter.increment()); // 1
// console.log(counter.increment()); // 2
// console.log(counter.decrement()); // 1
// console.log(counter.getCount()); // 1
// // console.log(counter.count); // Undefined (count is private)
// ```

// ### Private Variables
// Private variables in JavaScript can be created using closures. Variables defined within a function are not accessible from outside that function, providing a way to create private variables.

// **Example:**
// ```javascript
// const createPerson = (name, age) => {
//     let privateName = name; // Private variable
//     let privateAge = age; // Private variable

//     return {
//         getName: () => privateName,
//         getAge: () => privateAge,
//         setName: (newName) => {
//             privateName = newName;
//         },
//         setAge: (newAge) => {
//             privateAge = newAge;
//         }
//     };
// };

// const person = createPerson("Alice", 30);
// console.log(person.getName()); // Alice
// console.log(person.getAge()); // 30

// person.setName("Bob");
// person.setAge(35);

// console.log(person.getName()); // Bob
// console.log(person.getAge()); // 35
// ```

// In this example, `privateName` and `privateAge` are private variables, accessible only through the methods provided within the returned object. They cannot be accessed or modified directly from outside the function.



// In JavaScript, function arguments can be passed by value or by reference depending on the type of the argument.

// ### Pass by Value
// When you pass a primitive value (such as a number, string, boolean, `null`, `undefined`, `symbol`, or `bigint`) to a function, the value is passed by value. This means a copy of the value is made, and any changes to the argument within the function do not affect the original value.

// **Example:**
// ```javascript
// function changeValue(val) {
//     val = 100;
//     console.log('Inside function:', val); // 100
// }

// let num = 10;
// changeValue(num);
// console.log('Outside function:', num); // 10
// ```

// In this example, `num` is passed by value to the `changeValue` function. Changes made to `val` inside the function do not affect the original `num` variable.

// ### Pass by Reference
// When you pass an object (including arrays and functions) to a function, the value is passed by reference. This means a reference to the original object is passed, and changes to the object within the function do affect the original object.

// **Example:**
// ```javascript
// function changeProperty(obj) {
//     obj.name = 'Alice';
//     console.log('Inside function:', obj); // { name: 'Alice' }
// }

// let person = { name: 'Bob' };
// changeProperty(person);
// console.log('Outside function:', person); // { name: 'Alice' }
// ```

// In this example, `person` is passed by reference to the `changeProperty` function. Changes made to `obj` inside the function affect the original `person` object.

// ### Example with Arrays
// Arrays are objects in JavaScript and are therefore passed by reference.

// **Example:**
// ```javascript
// function modifyArray(arr) {
//     arr.push(4);
//     console.log('Inside function:', arr); // [1, 2, 3, 4]
// }

// let myArray = [1, 2, 3];
// modifyArray(myArray);
// console.log('Outside function:', myArray); // [1, 2, 3, 4]
// ```

// In this example, `myArray` is passed by reference to the `modifyArray` function. The change made to `arr` inside the function affects the original `myArray`.

// ### Summary
// - **Primitive types** (numbers, strings, booleans, `null`, `undefined`, symbols, and bigints) are passed by value.
// - **Objects** (including arrays and functions) are passed by reference.

// Understanding this distinction is crucial for managing data within your functions and ensuring that your code behaves as expected.






