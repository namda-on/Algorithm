const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const Numbers = input[1].split(" ").map((v) => Number(v));
// [+, -, x, /];
const operationCount = input[2].split(" ").map((v) => Number(v));
const arr = [];
const result = [];

function dfs(m) {
  if (m === N - 1) {
    result.push(arr.slice());
    return;
  }

  for (let i = 0; i < 4; i++) {
    if (operationCount[i] > 0) {
      operationCount[i]--;
      arr[m] = i;
      dfs(m + 1);
      operationCount[i]++;
    }
  }
}

dfs(0);

let min = 1000000000;
let max = -1000000000;

function calResult() {
  result.forEach((operation) => {
    const operationResult = Numbers.reduce((prev, current, idx) => {
      if (idx === 0) return current;
      switch (operation[idx - 1]) {
        case 0:
          return prev + current;
        case 1:
          return prev - current;
        case 2:
          return prev * current;
        case 3:
          if (prev < 0) {
            return Math.floor(Math.abs(prev) / current) * -1;
          }
          return Math.floor(prev / current);
      }
    }, 0);

    if (operationResult < min) {
      min = operationResult;
    }

    if (operationResult > max) {
      max = operationResult;
    }
  });
}

calResult();

console.log(max === -0 ? 0 : max);
console.log(min === -0 ? 0 : min);
