let c = document.getElementById("count_el");
let inc_btn = document.getElementById("_inc");
let save_btn = document.getElementById("save");
let result = document.getElementById("comment");

let count = 0;

function inc(){
    count+=1;
    c.innerHTML = count;
}


  let count_ = "";

function save(){
  
    count_+=count + " - ";
    result.textContent = count_;
    count = 0;
    c.innerHTML = 0;
}