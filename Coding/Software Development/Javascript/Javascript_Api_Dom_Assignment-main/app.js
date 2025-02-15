document.getElementById('searchBtn').addEventListener('click', function ()
{
    const searchInput = document.getElementById('searchInput').value;
    if (searchInput)
    {
        searchPlayer(searchInput);
    }
});

function searchPlayer(query)
{
    const url = `https://www.thesportsdb.com/api/v1/json/3/searchplayers.php?p=${query}`;
    fetch(url)
        .then(res => res.json())
        .then(data =>
        {
            const playerList = document.getElementById('playerList');
            playerList.innerHTML = '';
            document.getElementById('message').classList.add('d-none');
            if (data.player)
            {
                data.player.forEach(player =>
                {
                    if (player?.strThumb)
                    {
                        const card = `
                        <div class="col-md-4 player-card">
                            <div class="card">
                                <!-- Player Image -->
                                <img src="${player.strThumb}" class="card-img-top" alt="${player.strPlayer}">
                                <div class="card-body">
                                    <h5 class="card-title">${player.strPlayer}</h5>
                                    <p class="card-text"><strong>Nationality:</strong> ${player.strNationality}</p>
                                    <p class="card-text"><strong>Sport:</strong> ${player.strSport}</p>
                                    <p class="card-text"><strong>Team:</strong> ${player.strTeam}</p>
                                    <p class="card-text"><strong>Height:</strong> ${player.strHeight}</p>
                                    <p class="card-text"><strong>Weight:</strong> ${player.strWeight}</p>
                                    <p class="card-text"><strong>Gender:</strong> ${player.strGender}</p>
                                    <!-- Social Media Links -->
                                    <div class="social-icons">
                                        ${player.strFacebook ? `<a href="${player.strFacebook}" target="_blank" class="btn btn-primary  btn-sm"><i class="fab fa-facebook"></i> Facebook</a>` : ''}
                                        ${player.strTwitter ? `<a href="${player.strTwitter}" target="_blank" class="btn btn-primary    btn-sm"><i class="fab fa-twitter"></i> Twitter</a>` : ''}
                                        ${player.strInstagram ? `<a href="${player.strInstagram}" target="_blank" class="btn btn-primary    btn-sm"><i class="fab fa-instagram"></i> Instagram</a>` : ''}
                                    </div>
                                    <button class="btn btn-info mt-2" onclick="viewDetails('${player.idPlayer}')">Details</button>
                                    <button class="btn btn-success mt-2" onclick="addPlayer('${player.strPlayer}', '${player.strGender}')   ">Add To List</button>
                                </div>
                            </div>
                        </div>`;
                        playerList.innerHTML += card;
                    }
                });
            }
            else
            {
                document.getElementById('message').classList.remove('d-none');
            }
        })
        .catch(error => console.log('Error:', error));
}

function addPlayer(Name, gender)
{
    const total = document.getElementById('total');
    const men = document.getElementById('men');
    const female = document.getElementById('female');
    const spot = document.getElementById('spot');

    if (total.innerHTML == 11)
    {
        alert('You can select only 11 players');
        return;
    }

    if (gender == 'Male')
    {
        men.innerHTML++;
        total.innerHTML++;
        spot.innerHTML--;
    }
    else if (gender == 'Female')
    {
        female.innerHTML++;
        total.innerHTML++;
        spot.innerHTML--;
    }

    const info = document.getElementById('player-info');
    const p = document.createElement('p');
    p.innerText = Name;
    info.appendChild(p);

}

function viewDetails(id)
{
    const url = `https://www.thesportsdb.com/api/v1/json/3/lookupplayer.php?id=${id}`;

    fetch(url)
        .then(res => res.json())
        .then(data =>
        {
            const player = data.players[0];

            let details = `
                <img src="${player.strThumb}" class="img-fluid mb-3" alt="${player.strPlayer}">
                <h5>${player.strPlayer}</h5>
                <p><strong>Nationality:</strong> ${player.strNationality}</p>
                <p><strong>Sport:</strong> ${player.strSport}</p>
                <p><strong>Team:</strong> ${player.strTeam}</p>
                <p><strong>Height:</strong> ${player.strHeight}</p>
                <p><strong>Weight:</strong> ${player.strWeight}</p>
                <p class="card-text"><strong>Gender:</strong> ${player.strGender}</p>
                <p><strong>Birth Location:</strong> ${player.strBirthLocation}</p>
                <p class="card-text"><strong>Birth DOB:</strong> ${player.dateBorn}</p>
                <p><strong>Description:</strong> ${player.strDescriptionEN.slice(0,100)}</p>
                
                <div class="social-icons">
                    ${player.strFacebook ? `<a href="${player.strFacebook}" target="_blank" class="btn btn-primary btn-sm"><i class="fab fa-facebook"></i> Facebook</a>` : ''}
                    ${player.strTwitter ? `<a href="${player.strTwitter}" target="_blank" class="btn btn-primary btn-sm"><i class="fab fa-twitter"></i> Twitter</a>` : ''}
                    ${player.strInstagram ? `<a href="${player.strInstagram}" target="_blank" class="btn btn-primary btn-sm"><i class="fab fa-instagram"></i> Instagram</a>` : ''}
                </div>
            `;


            document.querySelector('.modal-body').innerHTML = details;

            const modal = new bootstrap.Modal(document.getElementById('playerModal'));
            modal.show();
        })
        .catch(err => console.error('Error fetching player details:', err));
}
