//  ES6  

//  DEFAULT VALUE : JDI ARGUMENT E KONO VALUE NA THAKE . TAILE OUTPUT NAN/ UNIDENFIED SHOW KORE. AR EI JNNO PARAMETER E DEAFULT VALUE SET KORA HOI... + , - ER JNNO =0  , * ER JNNO 1 . ARRAY ER JNNO EMPTY ARRAY. OBJECT ER JNNO EMPTY OBJECT EVABE.

function sum(a=0,b){
    let add = a+b ;

    console.log(a,b,add);
}
sum(2,4);

// array
function array( a=[] , b  ){
    
    console.log(a,b);
}

const ab = [1,2,3];
array(ab);


// ANSWER : 2 4 6
// [ 1, 2, 3 ] undefined 
// UNEFINED BEACUSE B ARRAY TE DEFAULT VALUE NAI....


// BACTICK (` `) / TEMPLATE STRING ;

let bd = 4 ;

let  ef = 5 ;

const addition = `sum of ${bd} and ${ef} is ${bd+ef} `;

console.log(addition);


//  ES 5 => REGULAR FUNCTION  

function add( x , y ){

    const z = x + y ;

   return z;
}

const p = add(5,5);
console.log(p);


// es6 = arrow Function 

const xyz = ( a , b) => a + b ;

const summ = xyz(2,2);
console.log(summ);


//  MORE ARROW FUNCTION

const arrowF = ( x , y , z) => {

    const sum = x+y;
    const diff = x - z ;

    const multi = sum * diff ;

    return multi;
}

const argument = arrowF(2,2,5);

console.log(argument);


// one parameter 

const ar= (a) => a[2];

const ll = ar([1,2,3]);

console.log(ll);



//  SPREAD OPERATOR 

const array1 = [1,2,100,5];

const max = Math.max(array1);

console.log(max);
// ANSWER = NAN 

//  etar jnno spread operator use korte hbe

const array_1 = [1,2,100,5];

const max_1 = Math.max(...array_1);

console.log(max_1);

//  answer 100

// COPY BY SPREAD OPERATOR.

const numbers = [1,2,3,4];

const humm = [...numbers];

numbers.push(100,200);


// // [ 1, 2, 3, 4, 100, 200 ]
console.log(numbers);


// [ 1, 2, 3, 4 ]
console.log(humm);



//  DESTRUCTURE

const object = {
    phone : "Apple",
    pp : 1000 ,
    madeIn : "USA"
}

//  destructure throgh property name
const {phone,pp} = object ;

console.log(phone,pp);

//  ARRAY DESTRUCTURE 

const a_1 = [1,2,3];

const [ first , second ] = a_1 ;

console.log(first , second);


//  FOR IN

const object_1 = {
    phone : "Apple",
    pp : 1000 ,
    madeIn : "USA"
}

for ( const item in object_1){

    const PROPERTY = item ;

    const values = object_1[item]

    console.log(values);

    console.log(PROPERTY);
}



