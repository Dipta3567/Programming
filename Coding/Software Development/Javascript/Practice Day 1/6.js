var friends = ["rahim", "karim", "abdul", "sadsd", "heroAlom"];

let x=friends[0];
for (let i=0;i<friends.length;i++){
    if (x.length<friends[i].length){
        x=friends[i];
    }
}
console.log(x);