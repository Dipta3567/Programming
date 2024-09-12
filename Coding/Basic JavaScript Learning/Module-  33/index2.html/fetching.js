// console.log("it's working");

function fetching(){

    fetch('https://jsonplaceholder.typicode.com/users')

    .then( res => res.json())

    .then( data => passing(data))
}


//another functinf by passing value

function passing(data){

     const getdata = document.getElementById('container')

     for( const item of data){
        const create = document.createElement('div')

        create.innerHTML = `
         
        <h4> ID : ${item.id}  </h4>

        <p> Name : ${item.name} </p>
        
        <p> EMAIL : ${item.email} </p>

        `
        getdata.appendChild(create)
     }
}


// calling 
fetching()