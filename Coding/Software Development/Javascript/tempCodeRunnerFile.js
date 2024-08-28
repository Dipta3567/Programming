const readline = require('readline');

// Function to calculate the monthly savings
function monthlySavings(arr, cost) {
    if (!Array.isArray(arr) || typeof cost !== 'number') {
        return "invalid input";
    }
    
    let sum = 0;
    let tax = 0;
    
    for (let i = 0; i < arr.length; i++) {
        if (typeof arr[i] !== 'number') {
            return "invalid input";
        }
        
        if (arr[i] >= 3000) {
            tax = arr[i] * 0.2;
            arr[i] -= tax;
        }
        sum += arr[i];
    }

    let savings = sum - cost;

    if (savings >= 0) {
        return savings;
    } else {
        return "earn more";
    }
}

// Setup the readline interface
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Ask for input from the user
rl.question('Enter your monthly payments as an array (e.g., 1000,2000,3000): ', (inputArr) => {
    rl.question('Enter your living cost: ', (inputCost) => {
        // Parse the inputs
        let payments = inputArr.split(',').map(Number); // Convert the array input into numbers
        let cost = Number(inputCost); // Convert the living cost into a number
        
        // Call the function and print the result
        let result = monthlySavings(payments, cost);
        console.log(result);
        
        rl.close(); // Close the interface after the operation is done
    });
});
