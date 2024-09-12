
//  STEP - 1 = GET THE PARENT ID / CLASS
const m = document.getElementById("mains");

//  CREATE 
const c = document.createElement("section");

// ADD
c.innerHTML = `

<h1> NEW SECTION</h1>

<p> CREATED A PARAGRAPH </p>

<ol>

<li>a</li>
<li>b</li>
<li>c</li>
<li>d</li>

</ol>

`
//  FINALLY ADD
m.appendChild(c);


