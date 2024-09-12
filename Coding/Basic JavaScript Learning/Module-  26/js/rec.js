function recArea(){
    // console.log("rec working")

    // width
    const collect = document.getElementById("width-id");

    const collecting = collect.value ;

    const width = parseFloat(collecting);

    // console.log(width);



    // length

    const collect1 = document.getElementById("length-id");

    const collecting1 = collect1.value ;

    const length = parseFloat(collecting1);

    // console.log(length);


    // calculating

    const total_area = width * length ;

    // console.log(total_area);

    const show = document.getElementById("r-area");

     show.innerText = total_area;

     console.log("total area of rectangle is", total_area)


}