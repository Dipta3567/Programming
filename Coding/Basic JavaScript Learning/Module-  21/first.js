// MODULE - 21 => PROBLEM SOLVING

//  Unit Convert Inch To Feet,  Meter To Kilometre

//  1 FEET = 12 INCH


function inch(feet){

    let result = feet * 12 ;

    return result;
}

let number_feet = inch(5);

console.log("5 feet = ",number_feet);


function kilometer(meter){

    let result = meter / 1000 ;

    return result; 
}

let number_meter = kilometer(10);

console.log("10 meter = ",number_meter);


// Calculate The Average Of The Odd Numbers In An Array

function array(array_1){
    
    let odds = [];
    
    for (const number of array_1){
        
        if(number % 2 !== 0){

            odds.push(number);
      
        }         
    }
    // console.log(odds);

    let sum = 0 ;

    for (const num of odds){

        sum = sum + num ;
    }

    let number_odds = odds.length;

    let average = sum / number_odds;

    return average;
  
}

let parameter = array([1,2,3,4,5,7]);

console.log( "The Average Of The Odd Numbers In An Array IS :" ,parameter);


// MATH , MIN , MAX , ABS , FLOOR , CEIL , PI
 
let min = Math.min(2,-12,100,99);
console.log(min);

let max = Math.max(100,23,45,22);
console.log(max);

let pie = Math.PI;
console.log(pie.toFixed(2));


let absulote = Math.abs(-12.00);
console.log(absulote);

let rounding = Math.round(10.8);
console.log(rounding);


let floor = Math.floor(12.88);
console.log(floor);


let ceiling = Math.ceil(12.88);
console.log(ceiling);



// SWAPPING  through temporary value.

let a = 10 ;

 let b = 5 ;

 let tem_value = a ;

 a = b ;
 b = tem_value;

 console.log(a,b);


//   another way of swapping through destructing 

let x = 2 ;

let y = 8 ;

[x,y] = [y,x];

console.log(x,y);


