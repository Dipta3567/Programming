// const target = document.getElementById("title"); // Use getElementById

// target.style.color = "red";

// target.style.backgroundColor = "black";

// console.log(target);

// ctrl + k + ctrl + c : multiple line comment

// DOm-Looop-if-else

// const allBox=document.getElementsByClassName("box");

// for (let i=0;i<allBox.length;i++)
// {   
//     const element=allBox[i];

//     if (element.textContent=="Box-5") // innerText
//     {
//         element.style.backgroundColor="red";
//     }
// }


// Add event listener

//1st way

//  document.getElementById("handle").addEventListener("click",(event) => {
    
//      //console.log("Hello Boss");

//      const input=document.getElementById("search-box").value;
//      console.log(input);
//  })

//2nd way

// const handleSearch = (event) => 
// {
//     console.log("Hello Dipta");
// }



// ------------------------------------------
// DOM-Manupulation

document.getElementById("handle").addEventListener("click",(event) => {
    
    //console.log("Hello Boss");

    const input=document.getElementById("search-box").value;
    const container = document.getElementById("comment-container");

    const p = document.createElement("p");
    p.classList.add("child");
    p.innerText = input;
    container.appendChild(p);

    document.getElementById("search-box").value = "";

    // value gula upor click kore value gula delete er jonno p.classList.add("child"); use korte hobe ata child namer akta class create korbe

    const allcoment= document.getElementsByClassName("child");
    for (const element of allcoment)
    {
        element.addEventListener("click", (e) => {
            console.log(e.target);
        })
    }




})