// ARRAY_PART-> 1 

// how to declare an array 

let numbers = [1,2,3,4,5];
console.log(numbers);

let names = ["Affnan", "Sawad"];
console.log(names);

let mixedArray = [10,11,"Mimnun","Lopa","Didar"];
console.log(mixedArray);

// length

let age = [18,2,33,44,12,3,5,8,10];
console.log(age.length);

// index = get item in a array by index number

console.log(age[5]);


// set  value by indexing in a array

let marks = [90,93,80,41,49,68];

marks[3] = 50 ;

console.log(marks);


// PUSH , POP

//push
let abc = [1,2,3,4,5];
abc.push(6);
console.log(abc);
abc.push(7,8,9);
console.log(abc);


//pop

let def = [1,2,3,4,5,6];
def.pop();
console.log(def);


// shift , unshift 

//shift : prothom theke delete kore.

let g = [1,2,3,4,5,6,7];
g.shift();
console.log(g);

// unshift => first e ADD kore.

let h = [2,3,4,5];
h.unshift(1);
console.log(h);



// includes , indexof , isArray

let z = [1,2,3,4,5,100];

console.log(z.includes(2));

console.log(z.indexOf(100));

console.log(z.indexOf(500));

console.log(Array.isArray(z));




