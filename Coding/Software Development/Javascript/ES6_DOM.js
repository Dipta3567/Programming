// Tamplet litarels
    // `` this is used for dynamic value and to access the value we have to use ${}

const name= "Bangladesh";

const country = `My country name is ${name}`;

console.log(country);

// Spread Operators
    // ... this is used to copy the value of an array or object
const numbers1 = [1,2,3,4,5];
const numbers2 = [6,7,8,9,10];

console.log([numbers1, numbers2]);


console.log(...numbers1);
console.log([...numbers1, ...numbers2]) ;// using spread operator


//console.log(numbers1.max()); // it will show an error because max is not a method of array
console.log(Math.max(...numbers1)); // using spread operator  


// Distructuring array and object
    // {} this is used for object
    // [] this is used for array

// object example :
const person = {
    name: "Rahim",
    age: 20,
    address: "Dhaka",
    friends: ["Karim", "Ali"],
};

console.log(person.age);

const agee = person.age;

console.log(agee);

const {age, friends} = person;// Distructuring object

console.log(age);
console.log(friends);

const names = ["Rahim", 10, "lores asd fsa d"];

const [name1, age1, address1] = names; // Distructuring array


// Arrow function
    // () => {} this is used for arrow function
    // if we have only one line of code then we can remove the {} and return keyword
    // if we have only one parameter then we can remove the () also

function add(num1, num2)
{
    const r= num1 + num2;
    //colsole.log(r);
    return r;
}

const out=add(10, 20);
console.log(out);

const out2= (num1, num2) => num1 + num2; 

console.log(out2(10, 20));

// Find
const products = [
    {name: "laptop", price: 1000}, // this is an object
    {name: "mobile", price: 500},
    {name: "watch", price: 100},
    {name: "tablet", price: 300},
    {name: "camera", price: 400},
    {name: "keyboard", price: 50},
    {name: "watch", price: 100},
    {name: "watch", price: 100},
    {name: "watch", price: 100},
    {name: "watch", price: 100},
]; // this is an array

for (let i=0;i<products.length;i++)
{
    if(products[i].price == 500)
    {
        console.log(products[i]);
    }
}

const result = products.find(product => product.price == 100); // find is used to find the first element
console.log(result);

// Filter-ES

const result2 = products.filter(product => product.price == 100); // filter is used to find all the element 
console.log(result2);

// map and forEach
    // map is used to get the value of an array and return the value
    // forEach is used to get the value of an array and do the operation but it will not return the value

const result3 = products.map(product => product.price); 
console.log(result3);

const result4 = products.forEach(product => console.log(product.price));
console.log(result4);


const numbers = [1,2,3,4,5,6,7,8,9,10];
const oddEven = (arr) => {
    let even=[]
    let odd=[]
    for (let i=0;i<arr.length;i++)
        if (arr[i]%2==0)
            even.push(arr[i]);
        else
            odd.push(arr[i]);

    return {even, odd};
}

const result5=oddEven(numbers);
console.log(result5);

// find the largest name in array


const checkname=(arr) =>
{
    let max=arr[0];
    for (let i=1;i<arr.length;i++)
    {
        if (arr[i].length>max.length)
            max=arr[i];
    }
    return max;
}


const names2 = ["Rahim", "Karim", "Ali", "Kamal", "Jabbar", "Salam", "Bangladesh", "India", "Pakistan", "Nepal", "Bhutan", "Sri Lanka", "Maldives", "Afghanistan", "China", "Japan", "Korea", "Vietnam", "Thailand", "Myanmar", "Cambodia", "Laos", "Malaysia", "Singapore", "Indonesia", "Philippines", "Australia", "New Zealand", "Fiji", "Samoa", "Tonga", "Solomon Islands", "Vanuatu", "Papua New Guinea", "Kiribati", "Tuvalu", "Nauru", "Marshall Islands", "Micronesia", "Palau", "United States", "Canada", "Mexico", "Guatemala", "Belize", "Honduras", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Colombia", "Venezuela", "Guyana", "Suriname", "French Guiana", "Brazil", "Ecuador", "Peru", "Bolivia", "Paraguay", "Chile", "Argentina", "Uruguay", "Antarctica", "South Africa", "Namibia", "Botswana", "Zimbabwe", "Mozambique", "Zambia", "Angola", "Malawi", "Tanzania", "Kenya", "Uganda", "Rwanda", "Burundi", "Somalia", "Ethiopia", "Sudan", "South Sudan", "Eritrea", "Djibouti", "Egypt", "Libya", "Tunisia", "Algeria", "Morocco", "Western Sahara", "Mauritania", "Mali", "Niger", "Nigeria", "Benin", "Togo", "Ghana", "Ivory Coast", "Liberia", "Sierra Leone", "Guinea", "Guinea-Bissau", "Senegal", "Gambia", "Mauritania", "Cape Verde", "Spain", "Portugal", "France", "Italy", "Germany", "Netherlands", "Belgium", "Luxembourg", "Switzerland", "Austria", "Liechtenstein", "Monaco", "Andorra", "San Marino", "Vatican City", "United Kingdom", "Ireland", "Denmark", "Norway"];


console.log(checkname(names2));
