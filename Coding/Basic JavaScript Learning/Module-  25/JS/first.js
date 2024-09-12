console.log("DOM EVENTS COLLECTION");

// <!-- 1 -->
// <button onclick="document.body.style.backgroundColor='red'" >BUTTON-1</button>


// 2 = MOST IMPORTANT

function button2(){

    document.body.style.backgroundColor = 'blue'
}

// 3

const option3 = document.getElementById("button3");

option3.onclick = makepink ;

function makepink(){
     document.body.style.backgroundColor = 'pink'
}


//4
const option4 = document.getElementById("button4");

option4.onclick = function makegray(){
    document.body.style.backgroundColor = 'gray'
} ;

//5

const option5 = document.getElementById('button5');

option5.addEventListener("click", makeGreen);

function makeGreen(){
    document.body.style.backgroundColor = 'green';
}


// 6 = MOST IMPORTANT

document.getElementById("button-6").addEventListener("click",

function()
{
    document.body.style.backgroundColor = 'pink';
}

)


// 1

function use1(){
    document.body.style.backgroundColor = 'pink';
}

// 2

document.getElementById('handler').addEventListener('click',

    function(){
        document.body.style.backgroundColor = 'blue';
    }

)

