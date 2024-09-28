const loadAllProduct = () =>
{
    fetch('https://fakestoreapi.com/products')
            .then(res=>res.json())
            .then(data=>{
                displayProduct(data)
            })
}


// Display all product
const displayProduct = (products) =>
{
    const productContainer = document.getElementById("product-container")

    products.forEach(product =>
    {
        console.log(product)
        const div = document.createElement("div") // Create a div element
        div.classList.add("card") // Add a class name to the div element

        div.innerHTML = `
            <img class="card-img" src=${product.image} alt="">
            <h3>Price : $${product.price}</h3>
            <h5>${product.title.slice(0,70)}</h5>
            <p>${product.description.slice(0,70)}</p>
            <button onclick="singleProduct('${product?.id}')">Details</button>
            <button onclick="hadleAddToCart('${product?.title.slice(0,12)}',${product?.price})">Add to Cart</button>
        `
        productContainer.appendChild(div) // Append the div element to the product container
    });
}



const hadleAddToCart = (name,price) =>
{
    const container = document.getElementById("cart-main-container")

    const div = document.createElement("div")
    div.classList.add("cart-info") // Add a class name to the div element
    div.innerHTML = `
        <p>${name}</p>
        <h3 class="price">${price}</h3>
    `
    container.appendChild(div)
    updateTotal()
    
    const cartCount = document.getElementById("count").innerText

    let convertedCount = parseInt(cartCount)
    convertedCount++
    document.getElementById("count").innerText = convertedCount
}


const updateTotal= () =>
{
    const allPrice= document.getElementsByClassName("price")
    let cnt=0
    for (const element of allPrice) {
        cnt+=parseFloat(element.innerText)
    }
    document.getElementById("total").innerText=cnt.toFixed(2)
}


const singleProduct = (id) =>
{
    fetch(`https://fakestoreapi.com/products/${id}`)
            .then(res=>res.json())
            .then(json=>console.log(json))
}


loadAllProduct() // Load all product when the page is loaded

