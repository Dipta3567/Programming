//  TOPIC : - STRINGS & OBJECTS

// 3 WAYS TO DECLARE A STRING
const name = 'samin';
const name1 = "samin";
const name2 = `samin`;

console.log(name1,name1,name2);


// TOUPPERCASE / LOWERCASE

let a = "samin";
console.log(a.toLowerCase());
console.log(a.toUpperCase());

let b = 'mimnun';
let c = 'Mimnun';

if( b.toLowerCase() === c.toLowerCase() ) {
    console.log("same same");
}
else{
    console.log("same same but different");
}

// TRIIM  => vanish white space

let d = "lopa";
let e = "    lopa"


console.log(d);

console.log(e.trim());


//  slice . join , concat & includes

let f = "samin";
let g = ["mimnun","khan"];

console.log(f.slice(1,3));

console.log(g.join("+"));

console.log(f.concat(' ').concat(g));

console.log(f.includes("a"));



// Object

let bottle = {
    brand : "Best Buy",
    price : 200 ,
    gurranty: false ,
    size : [10,12,16],
    location : {
        ctg : 'joynogor',
        dhk : ["mirpur" , "dhanmodi"]
    }
}

console.log(bottle);


console.log(bottle.brand);
console.log(bottle.size[1]);
console.log(bottle.size);
console.log(bottle.price);

//another way to get a value
console.log(bottle["gurranty"]);


//  KEYS => PROPERTY . VALUES => PROPERTY ER VALUE

let p = Object.keys(bottle);

console.log(p)


let v = Object.values(bottle);

console.log(v)


//nested 
console.log(bottle.location.dhk[1])


// looping

for(const prop in bottle){

    console.log(prop);

    console.log(bottle[prop])
}

// 