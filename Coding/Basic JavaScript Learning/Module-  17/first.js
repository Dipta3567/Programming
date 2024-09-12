// Comparison Operators 
// > , < , == , >= , <= , !=

// and , or Operataor
//  &&  , ||  .....


// Special : === , !==  [  value + type(numeric/double,string) check kore ]

// == , !=  sudhu value check kore.

let apple = 10 ;
let mango = 12 ;

console.log(mango > apple);

console.log( 10 == "10" );


console.log( 10 === "10" );



// if - else 

//      if (  condition ) {
//              }

//       else {
//              }


let  keyboard_price = 2000 ;

if ( keyboard_price < 2500 ) {

    console.log("I will Buy");
}

else {
    console.log("I will not Buy");
}



// MULTIPLE CONDITIONS 

let math = 85 ;

let bangla = 97 ;

let english = 90 ;

if ( math >= 80 && english >= 80 && bangla >= 80 ){
    console.log("Golden A+")
}
else {
    console.log("A+ Miss")
}



// complex 

let math1 = 85 ;

let bangla1 = 77 ;

let english1 = 90 ;

if ((math1 >= 80  &&  english >= 80 ) && bangla1 < 80 ){
    console.log("Just A+")
}
else {
    console.log("A+ Miss")
}



//  else - if 

let age = 10 ;

let price = 2000 ;

if ( age >= 1 && age <= 18   ){
     
    // 10% discount
    let discount = price * 0.10 ;

    let pay = price - discount ;

    console.log("I have to Pay = " , pay);
}

else if(  age > 19 &&  age <= 22  ) {

    //5% discount 

    let discount = price * 0.5 ;

    let pay = price - discount ;

    console.log("i have to pay " , pay);
}

else{
    console.log(price);
}



// TERNARY OPERATOR

//  CONDITION ?  TRUE HOLE : FALSE HOLE

let number = 82 ;

number >= 80 ? console.log("a+") : console.log("not a+");



// LOGICAL NOT => value ultai dei

if (!true){
    console.log("false");
}



