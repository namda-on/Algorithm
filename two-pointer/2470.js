const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const A = input[1].split(" ").map(Number);
A.sort((a, b) => a - b);

let start = 0;
let end = N - 1;

let min = Infinity;
let pair = [];

while (start < end) {
  const sum = A[start] + A[end];

  if (Math.abs(sum) < min) {
    min = Math.min(Math.abs(A[start] + A[end]));
    pair = [A[start], A[end]];
  }
  if (sum === 0) break;

  if (sum > 0) {
    end--;
  } else start++;
}

console.log(pair[0], pair[1]);
