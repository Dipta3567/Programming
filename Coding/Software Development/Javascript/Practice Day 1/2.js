const readline = require('readline');

const r=readline.createInterface(
    {
        input: process.stdin,
        output: process.stdout
    }
);

r.question('Enter the number: ', (input) => {
    let x=parseInt(input);
    if(x%2==0)
        console.log("Even");
    else
        console.log("Odd");

    r.close();
});
