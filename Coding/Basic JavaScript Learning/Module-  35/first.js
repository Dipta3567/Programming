// MODULE 35 = > MORE ABOUT JAVASCRIPT .. .. 

// IMPORTANT FOR INTERVIEW...



// ## **What is JavaScript? Why JS is called highly abstracted , interpreted , dynamic type , JIT compiled , garbage collection Language.**

// **JavaScript is a programming language mainly used for creating interactive features on websites. Here’s a breakdown of the terms used to describe JavaScript:**

// 1. **Highly Abstracted: JavaScript allows developers to write code without worrying about complex details of the computer's hardware or memory management. This makes it easier to write and understand.**
// 2. **Interpreted: JavaScript code is executed line by line by the browser, rather than being compiled into machine code beforehand. This allows for immediate execution and easier debugging.**
// 3. **Dynamic Type: In JavaScript, variables can hold any type of data, and their type can change at runtime. You don't have to specify data types explicitly.**
// 4. **JIT Compiled: Just-In-Time (JIT) compilation means that JavaScript code is compiled to machine code at the moment it is needed, which improves performance.**
// 5. **Garbage Collection: JavaScript automatically manages memory, freeing up space that is no longer in use, which helps prevent memory leaks and makes the language easier to use.**

// **In summary, JavaScript is a versatile, easy-to-use language that powers much of the interactivity on the web.**

// # What Is V8 Engine ?

// **The V8 engine is an open-source JavaScript engine developed by Google. It is used in Google Chrome and Node.js, among other applications. Here's a simple breakdown:**

// - **Purpose: V8 is designed to execute JavaScript code quickly and efficiently. IT is written by C++.**

// ## Why JS is called singled threaned . Give the idea of asynchronous and syncronous?

// **JavaScript is called single-threaded because it executes code on a single main thread, meaning it can only perform one task at a time. However, it handles tasks efficiently using asynchronous programming. Here's a breakdown:**

// ### **Single-Threaded**

// - **Single Main Thread: JavaScript runs on one main thread, processing one task at a time.**
// - **Event Loop: Manages the execution of multiple tasks, ensuring the smooth running of applications by handling asynchronous tasks.**

// ### **Synchronous**

// - **Definition: Tasks are executed one after another, in the order they appear. Each task waits for the previous one to complete.**
// - **Example:Output:**
    
//     ```jsx
//     javascriptCopy code
//     console.log("First Task");
//     console.log("Second Task");
//     console.log("Third Task");
    
//     ```
    
//     ```arduino
//     arduinoCopy code
//     First Task
//     Second Task
//     Third Task
    
//     ```
    

// ### **Asynchronous**

// - **Definition: Tasks can start before previous tasks finish, allowing the program to continue running while waiting for the asynchronous tasks to complete.**
// - **Example:Output:**
    
//     ```jsx
//     javascriptCopy code
//     console.log("First Task");
    
//     setTimeout(() => {
//       console.log("Second Task (Async)");
//     }, 1000);
    
//     console.log("Third Task");
    
//     ```
    
//     ```arduino
//     arduinoCopy code
//     First Task
//     Third Task
//     Second Task (Async)  // This appears after 1 second
    
//     ```
    

// ## NORMAL FETCH VS ASYNC AWAIT FETCH

// ### Normal Fetch with `.then()`

// **Example:**

// ```jsx

// fetch('https://api.example.com/data')
//   .then(response => response.json())
//   .then(data => console.log(data))
//   .catch(error => console.error('Error:', error));

// ```

// ### Async/Await Fetch

// **Example:**

// ```jsx
// async function fetchData() {
//   try {
//     const response = await fetch('https://api.example.com/data');
//     const data = await response.json();
//     console.log(data);
//   }
//    catch (error) {
//     console.error('Error:', error);
//   }
// }

// fetchData();

// ```

// # Settimeout , cleartimeout , setinterval , clearinterval.

// ### `setTimeout`

// **Purpose**: Executes a function once after a specified delay.

// **Example**:

// ```jsx

// function sayHello() {
//   console.log("Hello!");
// }

// setTimeout(sayHello, 2000); // Says "Hello!" after 2 seconds

// ```

// ### `clearTimeout`

// **Purpose**: Cancels a timeout set with `setTimeout`.

// **Example**:

// ```jsx
// javascriptCopy code
// let timeoutID = setTimeout(sayHello, 2000);
// clearTimeout(timeoutID); // Cancels the timeout, "Hello!" will not be logged

// ```

// ### `setInterval`

// **Purpose**: Executes a function repeatedly, with a fixed time delay between each call.

// **Example**:

// ```jsx

// function sayHelloRepeatedly() {
//   console.log("Hello!");
// }

// let intervalID = setInterval(sayHelloRepeatedly, 1000); // Says "Hello!" every 1 second

// ```

// ### `clearInterval`

// **Purpose**: Cancels a repeated action set with `setInterval`.

// **Example**:

// ```jsx

// clearInterval(intervalID); // Stops the repeated "Hello!" messages

// ```

// ### Summary

// - **`setTimeout`**: Run a function once after a delay.
// - **`clearTimeout`**: Cancel a `setTimeout`.
// - **`setInterval`**: Run a function repeatedly with a delay.
// - **`clearInterval`**: Cancel a `setInterval`.

// ## What Is Event Loop ? Why it is used ?

// **The Event Loop is a fundamental part of JavaScript's runtime system. It manages the execution of asynchronous code, allowing JavaScript to be non-blocking and handle multiple tasks concurrently even though it is single-threaded.**

// ### **Why It Is Used?**

// **The Event Loop is used to ensure smooth execution of JavaScript code by:**

// - **Managing Asynchronous Tasks: It allows the execution of code that doesn't block the main thread, like fetching data from a server or waiting for user input.**
// - **Handling Callbacks: It manages and executes functions (callbacks) that are waiting to run after asynchronous tasks are completed.**

// ### **How It Works**

// 1. **Call Stack: Where JavaScript code is executed line by line.**
// 2. **Web APIs: Handles asynchronous operations (e.g., setTimeout, HTTP requests).**
// 3. **Callback Queue: Stores callbacks from asynchronous operations, waiting to be executed.**
// 4. **Event Loop: Continuously checks if the call stack is empty. If it is, it pushes the first callback from the callback queue to the call stack for execution.**

// ### **Example**

// ```jsx

// console.log("Start");

// setTimeout(() => {
//   console.log("Callback");
// }, 2000);

// console.log("End");

// ```

// **Output:**

// ```arduino

// Start
// End
// Callback // This appears after 2 seconds

// ```

// ### **Summary**

// **The Event Loop allows JavaScript to handle asynchronous tasks, ensuring that the main thread is not blocked and that the application remains responsive. It does this by managing the execution of code through the call stack and callback queue.**

// ## TRY , CATCH , FINALLY , THROW

// ### `try`

// **Purpose**: Used to wrap code that might throw an error.

// **Example**:

// ```jsx
// javascriptCopy code
// try {
//   // Code that might throw an error
//   let result = 10 / 0; // This will throw an error (division by zero)
// } catch (error) {
//   // Code to handle the error
//   console.error('Error caught:', error);
// }

// ```

// ### `catch`

// **Purpose**: Executes if an error is thrown in the corresponding `try` block.

// **Example**:

// ```jsx
// javascriptCopy code
// try {
//   let result = 10 / 0; // This will throw an error (division by zero)
// } catch (error) {
//   console.error('Error caught:', error); // Handles the division by zero error
// }

// ```

// ### `finally`

// **Purpose**: Executes regardless of whether an error was thrown or caught. It's often used for cleanup tasks.

// **Example**:

// ```jsx
// javascriptCopy code
// try {
//   let result = 10 / 0; // This will throw an error (division by zero)
// } catch (error) {
//   console.error('Error caught:', error);
// } finally {
//   console.log('This always runs, regardless of errors.');
// }

// ```

// ### `throw`

// **Purpose**: Used to manually throw an error.

// **Example**:

// ```jsx
// javascriptCopy code
// function divide(a, b) {
//   if (b === 0) {
//     throw new Error('Division by zero is not allowed.');
//   }
//   return a / b;
// }

// try {
//   console.log(divide(10, 0)); // This will throw an error
// } catch (error) {
//   console.error('Error caught:', error.message);
// }

// ```

// ### Summary

// - **`try`**: Wraps code that might throw an error.
// - **`catch`**: Handles errors thrown in the corresponding `try` block.
// - **`finally`**: Executes cleanup code, whether an error occurred or not.
// - **`throw`**: Manually throws an error with a custom message or object.

// These constructs are essential for handling errors and ensuring robustness in JavaScript applications.