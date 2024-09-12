console.log("HELLO DOM");

const head = document.getElementById("heading");
console.log(head);

const head1 = document.getElementById("heading");
console.log(head1.innerText);


const list = document.getElementsByTagName("li")
console.log(list);

const list1 = document.getElementsByClassName("class1")
console.log(list1);

for(const list of list1){
    list.style.color = "red";
    list.style.paddingLeft = "200px"
}

const elements = document.querySelectorAll("#mains")
for(const element of elements){
    element.style.backgroundColor = "gray";
}


//  create element & addchild
const element = document.getElementById("class2");
const li = document.createElement('li')
li.innerText = "xyz";

element.appendChild(li);


// const m = document.getElementById("mains");

// const c = document.createElement("section");

// c.innerHTML = `

// <h1> NEW SECTION</h1>

// `

// m.appendChild(c);

