//      


//  HOW TO ACCES NESTED DATA

const data = {

    product: "mobile",
    brand: "apple",

    price: [1000,1200,1300],
 
   madein: [
    {
        m1: "china",
        m2: "usa"
    },
    {
         ram: [6,8,10],
         rom : {
            lla : [64,128],
            jpg: ["1TB"]
         }
    }
   ]
    
}

//  access m2 = "usa"

console.log(data.madein[0].m2);

// access jpg

console.log(data.madein[1].rom.jpg[0]);


//  optional chaining =>  jdi answer thake taile show korb nahoi UNDEFINED SHOW KORBE..

console.log(data.madein[1].rom?.jpg[0])

console.log(data.madein[1].rom?.jpg[1])

// ANSWERS :
//  usa
// 1TB
// 1TB
// undefined



//  MAP => array er element gula loop kore kore pawa jai.
// then arrow funtion use kore jkno kichu kora jai

const num = [1,2,3,45,5];

const double = num.map(n=> n*2);
console.log(double);
// [ 2, 4, 6, 90, 10 ]



//  MAP

const data_1 = [ {

    product: "mobile",
    brand: "apple",

    price: 1000,
    
    price2: [1000,10,20,40,2,1],
 
   madein: [
    {
        m1: "china",
        m2: "usa"
    },
    {
         ram: [6,8,10],
         rom : {
            lla : [64,128],
            jpg: ["1TB"]
         }
    }
   ]
    
} 
]

//  MAP =>  LOOP KORE VALUE GULA ARRAY HISEBE DIBE.
// ARROW FUNCTION USE KORE JKNO ELEMENT KE RETURN KORA JABE.

const mapping =data_1.map( x => x.price * 2 );

console.log(mapping);

//  FOR EACH => FUNCTION HISEBE KONO KAJ KORE VALUE RETURN DITE PARE NA.
const forEach =data_1.forEach( x => x.price * 2 );
console.log(forEach);


//  FILTER => CONDITION MILLE  SEGULA RETURN KORE

const filtering =data_1.filter( x => x.price2 > 2 );
console.log(filtering);
//  answer =[1000,10,20,40]



//  find => j  condtion milbe tader mdde first take dibe khali
const finding =data_1.find( x => x.price2 > 2 );
console.log(finding);

// [10]

const notation = {
    
    name_1 : "Affnan",
    school : "gmhs",
    clg : "mohsin"
}
// dot notation
console.log(notation.name_1);

// bracket notation .. IT ITS POWERFULL

console.log(notation['clg']);
