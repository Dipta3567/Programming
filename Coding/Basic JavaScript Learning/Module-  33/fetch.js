//  fetching 

function loadData(){

    fetch('https://jsonplaceholder.typicode.com/users')

    .then(res => res.json())

    .then( data => console.log(data))
}



//  pass data to one function to another

function loadData_2(){

    fetch('https://jsonplaceholder.typicode.com/users')

    .then(res => res.json())

    .then( data => passing(data))
}


function passing(data){
    console.log(data);
}


//  fetch , pass , show on UI 

function show(){

    fetch('https://jsonplaceholder.typicode.com/users')

    .then(res=> res.json())

    .then( data => passing(data))
}


function passing(data){

    const getData = document.getElementById('getinput')

    for(const item of data){
      
        const li = document.createElement('li');

        li.innerText = item.name;

        getData.appendChild(li);

    }
}

