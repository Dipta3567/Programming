//  TOPIC - FUNCTION

// BASIC FUNCTION

function sum( a , b){

    let summation = a + b ;
    console.log(summation);
}

sum(10,10);


// 

function square(a){

    let result = a * a ;

    console.log(result)
}

let value = 2 ;

square(value);

// RETURN 

function add(a,b,c,d){

    let sum2 = a + b + c + d ;

    return sum2 ;
}

let result2 = add(2,2,2,2);

console.log("SUM2 IS = ", result2);


// even 

function even(a){

    if( a % 2 === 0){
        return true ;
    }

    return false ;
}

let parameter = even(2)

console.log(parameter);



function name11(name1){

    let length = name1.length;

    if(length % 2 === 0){
        return true;
    }
    return false;
}

let parameter1 = name11("AFFNAN");

console.log(parameter1);

// SUM OF ALL NUMBERS IN A ARRAY

function array(a1){
    
    let add = 0;

    for(const num of a1){

        console.log(num);

         add = add + num ;
    }

    return add ;

}

let number = [ 1,2,3,4,5];

let result_1 = array(number);

console.log("SUM OF ALL ARRAYS = ", result_1);
