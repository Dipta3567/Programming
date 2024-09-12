//  MODULE - 22  => PROBLEM SOLVING 

//  IF THE PRICE OF SHIRTS , PANTS , T-SHIRTS ARE 600,700,400. HOW MUCH MONEY DO YOU NEED TO BUY 5 SHIRTS, 5 PANTS AND 8 T-SHIRTS


function quantity(shirts,pants,t_shirt){

    const shirts_price = 600 ;
    const pants_price  = 700 ;
    const tshirt_price = 400 ;

    const total_shirt_price = shirts * shirts_price ;
    const total__pant_price = pants * pants_price ;
    const total_tshirt_price = t_shirt * tshirt_price ;


    const total_cost = total_shirt_price + total__pant_price + total_tshirt_price;

    return total_cost;
}

const quantities = quantity(5,6,8);

console.log("Total Cost Is = ",quantities);
