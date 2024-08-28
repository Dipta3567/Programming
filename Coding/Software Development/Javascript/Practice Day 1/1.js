const readline = require('readline');

const rl = readline.createInterface
    (
        {
            input: process.stdin,
            output: process.stdout
        }
    );

rl.question('Enter your result: ', (input) => {
    let result = parseFloat(input);

    if (isNaN(result) || result < 0 || result > 100)
        console.log("Invalid input. Enter a number.");
    else if (result >= 0 && result < 33)
        console.log("failed");
    else if (result >= 33 && result < 40)
        console.log("tumi D grade paico");
    else if (result >= 40 && result < 50)
        console.log("tumi C grade paico");
    else if (result >= 50 && result < 60)
        console.log("tumi B grade paico");
    else if (result >= 60 && result < 70)
        console.log("tumi A- grade paico");
    else if (result >= 70 && result < 80)
        console.log("tumi A grade paico");
    else if (result >= 80 && result <= 100)
        console.log("tumi A+ grade paico");
    else
        console.log("invalid");


    rl.close();
}
);
