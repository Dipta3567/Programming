function leap(year) 
{
    if (year % 4 == 0) 
    {
        if (year % 100 == 0) 
        {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}


const readline = require('readline');

const r=readline.createInterface
(
    {
        input: process.stdin,
        output: process.stdout
    }
);

r.question('Enter the year: ', (input) =>
    {
        let year=parseInt(input);
        if (leap(year))
            console.log("Leap year");
        else
            console.log("Not leap year");
        r.close();
    }
)
