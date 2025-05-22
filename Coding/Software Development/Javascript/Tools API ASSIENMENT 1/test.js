// Get the saved cart from localStorage, or initialize an empty cart if none exists
let cart = JSON.parse(localStorage.getItem('cart')) || []; // cart holds an array of product IDs

// Initialize totalAmount for calculating total price and a flag to check if discount has been applied
let totalAmount = 0; // total price of all items in cart
let discountApplied = false; // prevents applying the discount multiple times

// Wait for the HTML content to fully load
document.addEventListener('DOMContentLoaded', function () {
    // Get various HTML elements by their IDs or classes
    const topProductContainer = document.getElementById('top_product'); // container for product cards
    const cartCount = document.getElementById('cart-count'); // cart icon badge
    const cartItemsContainer = document.getElementById('cart-items'); // list where cart items will appear
    const totalAmountElement = document.getElementById('total-amount'); // element to show total cart amount
    const discountCodeInput = document.getElementById('discount-code'); // input box for discount code
    const applyDiscountButton = document.getElementById('apply-discount'); // apply discount button
    const proceedCheckoutButton = document.querySelector('.btn-success.mt-4'); // proceed to checkout button

    // Fetch the product data from external JSON file
    fetch('https://dipta3567.github.io/tools_assignment_api_1/products.json')
        .then(response => response.json()) // convert the response into JSON
        .then(data => { // 'data' is now an array of products
            data.forEach(product => { // loop through each product in the data array
                const productCard = document.createElement('div'); // create a div for product card
                productCard.classList.add('col-md-4'); // assign a Bootstrap class to make 3 columns per row

                // Set the inner HTML of productCard to show image, name, price, and add-to-cart button
                productCard.innerHTML = `
                    <div class="card mb-4" style="background-color: #f8f9fa; border: 1px solid #ddd; border-radius: 10px;">
                        <img src="${product.image}" class="card-img-top" alt="${product.name}" style="border-radius: 10px 10px 0 0;">
                        <div class="card-body" style="padding: 1.25rem; background-color: #ffffff;">
                            <h5 class="card-title" style="color: #2d3748; font-size: 1.2rem; font-weight: 600;">${product.name}</h5>
                            <p class="card-text" style="color: #4a5568;">$${product.price}</p>
                            <button class="btn add-to-cart" data-id="${product.id}" style="background: linear-gradient(45deg, #4caf50, #2196f3); color: white; padding: 10px 15px; border-radius: 5px; cursor: pointer; transition: all 0.3s; border: none; font-weight: bold;">
                                Add to Cart
                            </button>
                        </div>
                    </div>
                `;
                topProductContainer.appendChild(productCard); // add the product card to the product container
            });
        });

    // When a button inside the topProductContainer is clicked
    topProductContainer.addEventListener('click', function (e) {
        if (e.target.classList.contains('add-to-cart')) { // check if the clicked button is an "add to cart" button
            const productId = e.target.getAttribute('data-id'); // get the product ID from data-id attribute
            if (!cart.includes(productId)) { // only add if product not already in the cart
                cart.push(productId); // add product ID to the cart array
                localStorage.setItem('cart', JSON.stringify(cart)); // save the cart to localStorage
                updateCart(); // refresh the cart UI
            }
        }
    });

    // Function to update cart UI
    function updateCart() {
        cartItemsContainer.innerHTML = ''; // clear previous cart items
        totalAmount = 0; // reset total amount to 0

        if (cart.length === 0) { // if cart is empty
            totalAmountElement.textContent = '0.00'; // show 0 as total
            cartCount.textContent = '0'; // set cart badge to 0
            return; // exit the function
        }

        // Loop through each product ID in the cart
        cart.forEach(itemId => {
            fetch('https://dipta3567.github.io/tools_assignment_api_1/products.json') // fetch the product list again
                .then(response => response.json()) // convert to JSON
                .then(data => {
                    const product = data.find(p => p.id == itemId); // find the matching product by ID
                    if (product) {
                        const cartItem = document.createElement('li'); // create list item for the cart
                        cartItem.classList.add('list-group-item', 'd-flex', 'justify-content-between', 'align-items-center'); // styling classes

                        // Add product info and remove button inside cart item
                        cartItem.innerHTML = `
                            <img src="${product.image}" alt="${product.name}" class="img-fluid" style="width: 40px; height: 40px;">
                            <span>${product.name} - $${product.price}</span>
                            <button class="btn remove-item" data-id="${product.id}" style="background-color: #e91e63; color: white; padding: 5px 10px; border-radius: 5px; cursor: pointer; font-size: 0.85rem; transition: all 0.3s; border: none;">
                                Remove
                            </button>
                        `;
                        cartItemsContainer.appendChild(cartItem); // add item to cart list
                        totalAmount += product.price; // add price to total
                        totalAmountElement.textContent = totalAmount.toFixed(2); // update total price in UI
                    }
                });
        });

        cartCount.textContent = cart.length; // update cart count badge
    }

    // When remove button is clicked inside the cart
    cartItemsContainer.addEventListener('click', function (e) {
        if (e.target.classList.contains('remove-item')) { // check if clicked button is "remove"
            const productId = e.target.getAttribute('data-id'); // get product ID to remove
            removeFromCart(productId); // call function to remove it
        }
    });

    // Remove product from cart and update UI
    function removeFromCart(productId) {
        cart = cart.filter(itemId => itemId != productId); // remove product ID from cart
        localStorage.setItem('cart', JSON.stringify(cart)); // update localStorage
        updateCart(); // refresh cart UI
    }

    // When apply discount button is clicked
    applyDiscountButton.addEventListener('click', function () {
        const discountCode = discountCodeInput.value.trim(); // get entered code and trim whitespace
        if (discountApplied) { // if discount already used
            alert('Discount has already been applied.'); // show warning
            return;
        }

        if (discountCode === 'DISCOUNT10') { // check if code is correct
            const discountAmount = totalAmount * 0.1; // calculate 10% discount
            totalAmount -= discountAmount; // reduce total amount
            totalAmountElement.textContent = totalAmount.toFixed(2); // update total price in UI
            discountApplied = true; // mark discount as used
            alert('Discount applied successfully!'); // show success message
        } else {
            alert('Invalid discount code'); // wrong code message
        }
    });

    // When checkout button is clicked
    proceedCheckoutButton.addEventListener('click', function () {
        if (cart.length === 0) { // check if cart is empty
            alert('Your cart is empty.'); // show message
            return;
        }

        alert('✅ Order placed successfully! Thank you for your purchase.'); // success message
        cart = []; // empty the cart
        localStorage.removeItem('cart'); // clear from localStorage
        discountApplied = false; // reset discount flag
        discountCodeInput.value = ''; // clear discount input
        updateCart(); // refresh cart UI
    });

    updateCart(); // update the cart UI when page loads
});


// Get sidebar and buttons for opening/closing it
const viewCartButton = document.getElementById('view-cart'); // button to open sidebar
const closeCartButton = document.getElementById('close-cart'); // button to close sidebar
const cartSidebar = document.getElementById('cart-sidebar'); // sidebar element

// Show sidebar when 'View Cart' is clicked
viewCartButton.addEventListener('click', function () {
    cartSidebar.style.transform = 'translateX(0)'; // slide in the sidebar
});

// Hide sidebar when 'Close' is clicked
closeCartButton.addEventListener('click', function () {
    cartSidebar.style.transform = 'translateX(100%)'; // slide it back out
});
