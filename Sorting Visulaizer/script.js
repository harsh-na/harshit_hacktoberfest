let n;
let spd;
const array = [];
let container = document.getElementById('container');
let size = document.getElementById('arr_sz');
let speed = document.getElementById('arr_sp');

spd = 50;
n = size.value;

size.addEventListener("input", update);
speed.addEventListener("input", newSpeed);

init();

function init() {
  container.innerHTML = "";
  for (let i = 0; i < n; i++) {
    array[i] = Math.random();
  }
  showBrs();
}

function update() {
  n = size.value;
  console.log(size.value);
  init();
}

function newSpeed() {
  spd = (103 - speed.value);
  console.log(spd + " this is speed");
}

function play() {
  //bubbleSort(array);
  //showBrs(); 
  const copy = [...array];
  const moves = bubbleSort(copy);
  animate(moves);

}

function animate(moves) {
  if (moves.length == 0)
    return;

  const move = moves.shift();
  const [i, j] = move.indices;
  if (move.type == 'swap') { [array[i], array[j]] = [array[j], array[i]]; }

  showBrs(move);
  setTimeout(function () {
    animate(moves);
  }, spd);

}

// bubble sort starts
function bubbleSort(array) {
  const moves = [];

  for (var i = 0; i < array.length; i++) {

    // Last i elements are already in place 
    var j;

    for (j = 0; j < (array.length - i - 1); j++) {

      // Checking if the item at present iteration
      // is greater than the next iteration
      moves.push({ indices: [j, j + 1], type: "comp" });
      if (array[j] > array[j + 1]) {

        // If the condition is true then swap them
        moves.push({ indices: [j, j + 1], type: "swap" });
        var temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
    //  moves.push({indices:[j,j+1],type:"done"});
    // update_div(array[j+1],"green"); 
  }

  return moves;
}

// bubble sort ends

// function update_div( cont){

//   const bar=document.createElement('div');
//   bar.style.height= cont*100 + "%";
//   bar.classList.add("bar");
//   bar.style.color="green";
//   container.appendChild(bar);

// }


function showBrs(move) {
  container.innerHTML = "";
  for (let i = 0; i < n; i++) {
    const bar = document.createElement('div');
    bar.style.height = array[i] * 100 + "%";
    bar.classList.add("bar");

    if (move && move.indices.includes(i)) {
      // if(move.type== 'done')
      //bar.style.backgroundColor='green';
      // else
      bar.style.backgroundColor = move.type == 'swap' ? "red" : "blue";
    }

    //bar.style.backgroundColor="green";
    container.appendChild(bar);

  }
}

