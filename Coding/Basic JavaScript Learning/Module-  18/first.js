//  TOPIC :  LOOPS

// LOOPS => 1. FOR OF   2.WHILE    3.FOR 


// 1. FOR OF 

const num = [1,2,3,4,5];

for(const numbers of num){
    console.log(numbers);
}


const names = ["Didar", "Lopa","Samin","Mimnun"];

for(const name of names){
    console.log(name);
}


//  While Loop 

let  a = 1 ;

while(a <= 10){
   
    console.log(a);
    
    a++;
}


let b = 1 ;

let sum = 0 ;

while(b < 10 ){

    sum = sum + b ;

    b++;
}

console.log("Summation Is=", sum);




let c = 1 ;



while( c < 10 ){

   if( c % 2 !== 0 ){
    console.log("Odd Number Is=", c);
   }

   c++;

}



let d = 81 ;

let sum1 = 0 ;

while( d <= 131 ){
   
    if(d%2 !== 0){

        sum1 = sum1 + d ;
    }
    d++;
}
console.log("sum of all the odd numbers from 81 to 131 IS =",sum1);


// Implement a countdown timer that counts down from 21 to 15.

let e = 21 ;

while(e >= 15 ){
    console.log("Implement a countdown timer that counts down from 21 to 15.", e);
    e--;
}



//  FOR LOOP

for (let i = 0 ; i <= 10 ; i++){
    console.log("NUMBERS ARE =", i);
}


for (let i = 10 ; i >= 0 ; i--){
    console.log("NUMBERS ARE =", i);
}


for (let i = 1 ; i <= 10 ; i+=2){
    console.log("ODD NUMBERS ARE =", i);
}

// Find Sum of all the odd numbers from 61 to 100.

let summ2 = 0 ;

for(let i = 61 ; i <= 100 ; i++){
    
    if(i%2 !== 0){
        summ2 = summ2 + i ;
    }
}

console.log("Sum of all the odd numbers from 61 to 100 Is =", summ2)



// break

for(let i= 0 ; i< 20 ; i++){

    if(i>=15){
        break;
    }
    console.log(i);
}



//  CONTINUE :  ( SKIP KORE DEI CONDITION TRUE HOLE )

for(let i= 1 ; i< 20 ; i++){

    if(i % 2 === 0){
        continue;
    }
    console.log(i);
}






