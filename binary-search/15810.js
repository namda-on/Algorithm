const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const A = input[1].split(" ").map(Number);

function solution() {
  let start = 1;
  let end = Math.max(...A) * M;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    const sum = A.reduce((prev, cur) => {
      return prev + Math.floor(mid / cur);
    }, 0);

    if (sum >= M) end = mid - 1;
    else start = mid + 1;
  }

  return start;
}

console.log(solution());
