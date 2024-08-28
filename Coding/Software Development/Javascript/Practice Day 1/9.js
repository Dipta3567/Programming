const readline = require('readline');

function monthlySavings(arr, cost)
{
    if (!Array.isArray(arr) || typeof cost !== 'number') // array check korar jonno and == and === er difference hocce == sudhu value check korbe but === value and type check korbe
    {
        return "invalid input";
    }
    
    let sum = 0;
    let tax = 0;
    
    for (let i = 0; i < arr.length; i++)
    {

        if (arr[i] >= 3000)
        {
            tax = arr[i] * 0.2;
            arr[i] -= tax;
        }
        sum += arr[i];
    }

    let savings = sum - cost;

    if (savings >= 0)
    {
        return savings;
    } 
    else
    {
        return "earn more";
    }
}

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

rl.question('Enter your monthly payments (space-separated, e.g., 1000 2000 3000): ', (arr) =>
{
    rl.question('Enter your living cost: ', (cost) =>
    {
        
        let payments = arr.split(' ').map(Number); // Convert the space-separated input into an array of numbers
        let liv = Number(cost); // Convert the living cost to a number
        if (isNaN(liv)) // Check if the living cost is not a number
        {
            console.log("invalid input");
        }
        else
        {
            let result = monthlySavings(payments, liv);
            console.log(result);
        }

        rl.close();
    });
});
