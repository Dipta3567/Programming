function romArea(){
    

    const width = shortbyId('width_1');

    const length = shortbyId('length_1');

    const area = width * length ;

    console.log(area);


    //   SHOWING IN UI
    show("rom-area",area);


}


function shortbyId(get_all_value){

    const collect = document.getElementById(get_all_value);

    const collecting = collect.value;

    const final_value = parseFloat(collecting);

    return final_value;
}

//  SHOWING IN UI
function show(showing1,area){

    const element = document.getElementById(showing1);

    element.innerText = area ;

    // return show_1;

}