document.getElementById('searchBtn').addEventListener('click', function ()
{
    const searchInput = document.getElementById('searchInput').value;
    if (searchInput) {
        searchRecipes(searchInput);
    }
});

function searchRecipes(query)
{
    const url = `https://www.themealdb.com/api/json/v1/1/search.php?s=${query}`;
    fetch(url)
        .then(response => response.json())
        .then(data => {
            const recipeList = document.getElementById('recipeList');
            recipeList.innerHTML = '';
            document.getElementById('message').classList.add('d-none'); // Hide No dishes message

            if (data.meals) {
                data.meals.forEach(meal => {
                    const card = `
                        <div class="col-md-4 recipe-card">
                            <div class="card">
                                <img src="${meal.strMealThumb}" class="card-img-top" alt="${meal.strMeal}">
                                <div class="card-body">
                                    <h5 class="card-title">${meal.strMeal}</h5>
                                    <button class="btn btn-primary" onclick="showIngredients(${meal.idMeal}, '${meal.strMealThumb}')">View Ingredients</button>
                                </div>
                            </div>
                        </div>
                    `;
                    recipeList.innerHTML += card;
                });
            } else {
                document.getElementById('message').classList.remove('d-none');
            }
        })
        .catch(error => console.error('Error:', error));
}

function showIngredients(mealId, mealImage) {
    const url = `https://www.themealdb.com/api/json/v1/1/lookup.php?i=${mealId}`;
    fetch(url)
        .then(response => response.json())
        .then(data => {
            const meal = data.meals[0];
            let ingredients = '';

            for (let i = 1; i <= 20; i++) {
                const ingredient = meal[`strIngredient${i}`];
                const measure = meal[`strMeasure${i}`];
                if (ingredient) {
                    ingredients += `<li>${ingredient} - ${measure}</li>`;
                }
            }

            // Display ingredients and image in modal
            const ingredientsList = document.getElementById('ingredientsList');
            const dishImage = document.getElementById('dishImage');
            ingredientsList.innerHTML = ingredients;
            dishImage.src = mealImage;

            // Show the modal
            const ingredientsModal = new bootstrap.Modal(document.getElementById('ingredientsModal'));
            ingredientsModal.show();
        })
        .catch(error => console.error('Error:', error));
}
