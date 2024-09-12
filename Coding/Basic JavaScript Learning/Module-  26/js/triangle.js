function tiangleCal(){
    // base
    const collectbase = document.getElementById("base-id");
    const collectbase2 = collectbase.value;
    const base = parseFloat(collectbase2);

    // console.log(base)


    // height

    const collectheight = document.getElementById("height-id");
    const collectheight2 = collectheight.value;
    const height = parseFloat(collectheight2);
     

    // console.log(height);

    const total_area = 0.5 * base * height ;
    console.log(total_area)

    const show = document.getElementById('t-area');
    show.innerText = total_area ;


}