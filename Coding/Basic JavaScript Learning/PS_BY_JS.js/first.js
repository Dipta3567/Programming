//  PROBLEM SOLVING BY JAVASCRIPT ........

// Your first program in any programming language is usually "Hello World!". In this first problem all you have to do is print this message on the screen.

console.log("Hello World");

// Read 2 variables, named A and B and make the sum of these two variables, assigning its result to the variable X. Print X as shown below. Print endline after the result otherwise you will get “Presentation Error”.

function sum(A,B){

    let add = A + B ;

    return add;
}

let result = sum(18,12);

console.log("X=",result);


// The formula to calculate the area of a circumference is defined as A = π . R2. Considering to this problem that π = 3.14159:

// Calculate the area using the formula given in the problem description.


function area(r){

    let total_area = Math.PI* ( r * r) ;

    return total_area;
}

let radius = area(2);

console.log("Total Area = ",radius.toFixed(2));


// Read four integer values named A, B, C and D. Calculate and print the difference of product A and B by the product of C and D (A * B - C * D).

function  calculation(A,B,C,D){

    let Result = (A * B) - (C * D );

    return Result;
}

let result2 = calculation(10,10,10,10)
console.log("Result Is =" ,result2);


// Write a program that reads an employee's number, his/her worked hours number in a month and the amount he received per hour. Print the employee's number and salary that he/she will receive at end of the month, with two decimal places.

function salary(hour , rate){

    let employe_number = 25 ;
     
    console.log("EMPLOYE NUMBER IS : ", employe_number);

    let total_salary = hour * rate ;

    return total_salary ;
}

let s = salary(100,5.50);
console.log("Total salary is : $",s);


// Make a program that calculates and shows the volume of a sphere being provided the value of its radius (R) . The formula to calculate the volume is: (4/3) * pi * R3. Consider (assign) for pi the value 3.14159.

function value(R){
    
    let result3 = (4/3) * Math.PI * (R*R*R);

    return result3;
}

let v = value(3);

console.log("VOLUME",v.toFixed(2));

//  MULTIPLICATION TABLE OF 10 

for(let i = 1 ; i <= 10 ; i++){

    let m_t = i * 10 ;

    console.log(m_t);
}

//  ASCENDING / DESCENDING

function as_des(x,y){

    if(x>y){

        return "Ascending";
    }
    return "Descending";
}

let asds = as_des(4,6);

console.log(asds);



//  ODD NUMBERS BEETWEEN 1 - 10

function odd(x){

    for( let i = 0; i <= x ; i++){
        if(i%2 !== 0){
            console.log(i)
        }        
    }   
}
odd(10);

//  1.

function zooEarn(sell){

    let per_t = 120 ;
    let total_cost = (1*500) + (50*8);

    let total_sell = sell * per_t ;

    let total_earn = total_sell - total_cost ;

    if(total_earn < 0){
        return "LOSS";
    }
    return total_earn;
}

let per_day = zooEarn(10);
console.log("TOTAL EARN PER DAY =", per_day);




// 2. GOOD NAME = IF THE LAST WORD OF THE NAME IS VOWEL ; OTHERWISE IT IS BAD NAME

function name1(x){
   
    let l = x.length;

    // console.log(l)

     if( x[l-1] === "a" || x[l-1] === "e" || x[l-1] === "i" || x[l-1] === "o" ||x[l-1] === "u" || x[l-1] === "A" || x[l-1] === "E" || x[l-1] === "I" || x[l-1] === "O" ||x[l-1] === "U"    ){

        return "GOOD NAME"
     }    

     return "BAD NAME"
         
    }
    

let n = name1("Affnan Sawad ");
console.log(n);



