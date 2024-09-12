// # INTERVIEW QUESTIONS

// ### Comprehensive Interview Questions and Answers for a Junior Front-End Developer About JavaScript

// ### Basic Questions

// 1. **What is JavaScript, and how is it different from Java?**
//     - **Answer:** JavaScript is a scripting language primarily used for creating interactive web pages. It is interpreted, whereas Java is a compiled programming language used for building applications. JavaScript is mainly used in web development, while Java is used for various types of applications, including web, mobile, and desktop applications.
// 2. **What are the different data types present in JavaScript?**
//     - **Answer:** JavaScript has several data types:
//         - Primitive types: `Number`, `String`, `Boolean`, `Undefined`, `Null`, `Symbol`, `BigInt`.
//         - Composite types: `Object` (including Arrays and Functions).
// 3. **Explain the concept of `hoisting` in JavaScript.**
//     - **Answer:** Hoisting is JavaScript's default behavior of moving declarations to the top of the current scope (script or function). This means variables and function declarations can be used before they are declared in the code. For example:
        
//         ```jsx
//         javascriptCopy code
//         console.log(myVar); // undefined
//         var myVar = 5;
        
//         ```
        
// 4. **What are closures in JavaScript?**
//     - **Answer:** A closure is a function that retains access to its lexical scope even when the function is executed outside that scope. Closures are created whenever a function is created, allowing the function to access variables from an enclosing scope. For example:
        
//         ```jsx
//         javascriptCopy code
//         function outerFunction() {
//           let outerVariable = 'I am from the outer scope';
//           function innerFunction() {
//             console.log(outerVariable);
//           }
//           return innerFunction;
//         }
//         const inner = outerFunction();
//         inner(); // logs 'I am from the outer scope'
        
//         ```
        
// 5. **What is the difference between `let`, `const`, and `var`?**
//     - **Answer:**
//         - `var`: Function-scoped or globally scoped if declared outside a function. It can be re-declared and updated.
//         - `let`: Block-scoped, can be updated but not re-declared within the same scope.
//         - `const`: Block-scoped, cannot be updated or re-declared. It must be initialized at the time of declaration.
// 6. **What is an Immediately Invoked Function Expression (IIFE)?**
//     - **Answer:** An IIFE is a function that runs as soon as it is defined. It is a common design pattern for creating local scopes in JavaScript to avoid polluting the global scope. Example:
        
//         ```jsx
//         javascriptCopy code
//         (function() {
//           console.log('IIFE running');
//         })();
        
//         ```
        
// 7. **Explain `event delegation`.**
//     - **Answer:** Event delegation is a technique involving the use of a single event listener to manage events for multiple elements, usually by leveraging event propagation (bubbling). This is efficient because it reduces the number of event listeners needed and can handle dynamically added elements. Example:
        
//         ```jsx
//         javascriptCopy code
//         document.getElementById('parent').addEventListener('click', function(event) {
//           if (event.target && event.target.matches('button.class-name')) {
//             console.log('Button clicked!');
//           }
//         });
        
//         ```
        
// 8. **What is the purpose of the `bind` method in JavaScript?**
//     - **Answer:** The `bind` method creates a new function that, when called, has its `this` keyword set to the provided value. It can also pass in any number of arguments to be prepended to arguments provided to the bound function when invoked. Example:
        
//         ```jsx
//         javascriptCopy code
//         const obj = { name: 'Alice' };
//         function greet(greeting) {
//           console.log(greeting + ', ' + this.name);
//         }
//         const boundGreet = greet.bind(obj);
//         boundGreet('Hello'); // logs 'Hello, Alice'
        
//         ```
        
// 9. **What is the difference between `==` and `===`?**
//     - **Answer:** `==` is the loose equality operator, which compares two values for equality after converting both values to a common type (type coercion). `===` is the strict equality operator, which compares both the value and the type without doing any type conversion. Example:
        
//         ```jsx
//         javascriptCopy code
//         console.log(1 == '1'); // true
//         console.log(1 === '1'); // false
        
//         ```
        
// 10. **What is the purpose of promises in JavaScript?**
//     - **Answer:** Promises provide a way to handle asynchronous operations in JavaScript. They represent a value that may be available now, later, or never. A promise can be in one of three states: pending, fulfilled, or rejected. They allow chaining with `.then()` and handling errors with `.catch()`. Example:
        
//         ```jsx
//         javascriptCopy code
//         const promise = new Promise((resolve, reject) => {
//           setTimeout(() => {
//             resolve('Success');
//           }, 1000);
//         });
//         promise.then(value => console.log(value)); // logs 'Success' after 1 second
        
//         ```
        
// 11. **Explain the concept of `async` and `await`.**
//     - **Answer:** `async` and `await` are syntactic sugar built on top of promises to make asynchronous code easier to write and understand. An `async` function always returns a promise, and `await` can be used to pause the execution of an `async` function until the promise is resolved. Example:
        
//         ```jsx
//         javascriptCopy code
//         async function fetchData() {
//           try {
//             const response = await fetch('https://api.example.com/data');
//             const data = await response.json();
//             console.log(data);
//           } catch (error) {
//             console.error('Error fetching data:', error);
//           }
//         }
//         fetchData();
        
//         ```
        
// 12. **What are arrow functions, and how do they differ from regular functions?**
//     - **Answer:** Arrow functions are a shorthand syntax for writing functions. They have a more concise syntax and do not have their own `this`, `arguments`, `super`, or `new.target` bindings. This makes them particularly useful for non-method functions. Example:They are especially useful for preserving the context of `this` in nested functions or callbacks.
        
//         ```jsx
//         javascriptCopy code
//         const add = (a, b) => a + b;
//         console.log(add(2, 3)); // 5
        
//         ```
        
// 13. **Explain the concept of `prototype` and prototypal inheritance in JavaScript.**
//     - **Answer:** Every JavaScript object has a `prototype`, which is another object that the original object inherits properties and methods from. This is known as prototypal inheritance. JavaScript uses this mechanism to allow objects to share properties and methods. Example:
        
//         ```jsx
//         javascriptCopy code
//         function Person(name) {
//           this.name = name;
//         }
//         Person.prototype.greet = function() {
//           console.log('Hello, ' + this.name);
//         };
//         const alice = new Person('Alice');
//         alice.greet(); // logs 'Hello, Alice'
        
//         ```
        
// 14. **What is the event loop in JavaScript?**
//     - **Answer:** The event loop is a mechanism that allows JavaScript to perform non-blocking I/O operations by offloading operations to the system kernel whenever possible. It constantly checks the message queue and executes pending tasks in the event loop. This allows JavaScript to handle asynchronous operations like callbacks, promises, and `async`/`await` without blocking the main thread.
// 15. **What are modules in JavaScript, and how do you use them?**
//     - **Answer:** Modules in JavaScript are reusable pieces of code that can be exported from one script and imported for use in another script. ES6 introduced native support for modules with `export` and `import` statements. Example:
        
//         ```jsx
//         javascriptCopy code
//         // math.js
//         export function add(a, b) {
//           return a + b;
//         }
//         // main.js
//         import { add } from './math.js';
//         console.log(add(2, 3)); // 5
        
//         ```
        
// 16. **What is the difference between `null` and `undefined` in JavaScript?**
//     - **Answer:** `null` is an assignment value that represents no value or an empty value. `undefined` means a variable has been declared but has not yet been assigned a value. Example:
        
//         ```jsx
//         javascriptCopy code
//         let a;
//         console.log(a); // undefined
//         let b = null;
//         console.log(b); // null
        
//         ```
        
// 17. **What is the purpose of the `this` keyword in JavaScript?**
//     - **Answer:** The `this` keyword refers to the object from which the function was called. Its value depends on the context in which it is used (global, function, method, event, etc.). In the global context, `this` refers to the global object (e.g., `window` in browsers).
// 18. **How do you check if a variable is an array in JavaScript?**
//     - **Answer:** You can check if a variable is an array using `Array.isArray(variable)`. Example:
        
//         ```jsx
//         javascriptCopy code
//         let arr = [1, 2, 3];
//         console.log(Array.isArray(arr)); // true
        
//         ```
        
// 19. **What is destructuring in JavaScript, and how does it work?**
//     - **Answer:** Destructuring is a syntax that allows you to unpack values from arrays or properties from objects into distinct variables. Example:
        
//         ```jsx
//         javascriptCopy code
//         let [a, b] = [1, 2];
//         console.log(a, b); // 1 2
        
//         let { name, age } = { name: 'Alice', age: 25 };
//         console.log(name,
        
//         ```
        
//         1. **What is the purpose of the `this` keyword in JavaScript?**
//         - **Answer:** The `this` keyword refers to the object from which the function was called. Its value depends on the context in which it is used (global, function, method, event, etc.). In the global context, `this` refers to the global object (e.g., `window` in browsers).
//         1. **How do you check if a variable is an array in JavaScript?**
//             - **Answer:** You can check if a variable is an array using `Array.isArray(variable)`. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 let arr = [1, 2, 3];
//                 console.log(Array.isArray(arr)); // true
                
//                 ```
                
        
//         ### Additional Intermediate Questions
        
//         1. **What is destructuring in JavaScript, and how does it work?**
//             - **Answer:** Destructuring is a syntax that allows you to unpack values from arrays or properties from objects into distinct variables. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 let [a, b] = [1, 2];
//                 console.log(a, b); // 1 2
                
//                 let { name, age } = { name: 'Alice', age: 25 };
//                 console.log(name, age); // Alice 25
                
//                 ```
                
//         2. **What is the purpose of the `spread` operator, and how is it used?**
//             - **Answer:** The spread operator (`...`) allows an iterable (like an array or string) to be expanded in places where zero or more arguments or elements are expected. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 let arr = [1, 2, 3];
//                 let newArr = [...arr, 4, 5];
//                 console.log(newArr); // [1, 2, 3, 4, 5]
                
//                 function sum(a, b, c) {
//                   return a + b + c;
//                 }
//                 console.log(sum(...arr)); // 6
                
//                 ```
                
//         3. **What is the `rest` parameter, and how is it different from the `spread` operator?**
//             - **Answer:** The rest parameter (`...args`) allows a function to accept an indefinite number of arguments as an array. It collects all remaining elements into an array. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 function sum(...args) {
//                   return args.reduce((acc, curr) => acc + curr, 0);
//                 }
//                 console.log(sum(1, 2, 3, 4)); // 10
                
//                 ```
                
//         4. **What is a promise chain?**
//             - **Answer:** A promise chain allows multiple asynchronous operations to be performed in sequence. Each `.then()` method returns a new promise, making it possible to chain additional `.then()` methods for subsequent operations. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 fetch('https://api.example.com/data')
//                   .then(response => response.json())
//                   .then(data => {
//                     console.log(data);
//                     return fetch('https://api.example.com/other-data');
//                   })
//                   .then(response => response.json())
//                   .then(otherData => {
//                     console.log(otherData);
//                   })
//                   .catch(error => {
//                     console.error('Error:', error);
//                   });
                
//                 ```
                
        
//         ### Additional Advanced Questions
        
//         1. **What are `generators` in JavaScript, and how do they differ from regular functions?**
//             - **Answer:** Generators are functions that can be paused and resumed, allowing them to produce a sequence of values over time. They use the `function*` syntax and the `yield` keyword. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 function* generateNumbers() {
//                   yield 1;
//                   yield 2;
//                   yield 3;
//                 }
//                 const generator = generateNumbers();
//                 console.log(generator.next().value); // 1
//                 console.log(generator.next().value); // 2
//                 console.log(generator.next().value); // 3
                
//                 ```
                
//         2. **What is `debouncing` in JavaScript, and why is it useful?**
//             - **Answer:** Debouncing is a technique used to limit the rate at which a function is executed. It ensures that the function is only called after a certain amount of time has passed since the last time it was invoked, which is useful for performance optimization, particularly in handling events like window resizing or key presses. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 function debounce(func, delay) {
//                   let timeoutId;
//                   return function(...args) {
//                     clearTimeout(timeoutId);
//                     timeoutId = setTimeout(() => func.apply(this, args), delay);
//                   };
//                 }
                
//                 window.addEventListener('resize', debounce(() => {
//                   console.log('Window resized');
//                 }, 300));
                
//                 ```
                
//         3. **Explain `throttling` in JavaScript.**
//             - **Answer:** Throttling is a technique to ensure a function is only called at most once in a specified period, regardless of how many times it’s triggered. It helps improve performance by limiting the execution rate of event handlers. Example:
                
//                 ```jsx
//                 javascriptCopy code
//                 function throttle(func, limit) {
//                   let inThrottle;
//                   return function(...args) {
//                     if (!inThrottle) {
//                       func.apply(this, args);
//                       inThrottle = true;
//                       setTimeout(() => (inThrottle = false), limit);
//                     }
//                   };
//                 }
                
//                 window.addEventListener('scroll', throttle(() => {
//                   console.log('Scrolling');
//                 }, 1000));
                
//                 ```


// ----------------------END-----------------------------------------------