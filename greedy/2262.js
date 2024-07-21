const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);

const A = input[1].split(" ").map(Number);

function solution() {
  let sum = 0;

  let current = A;

  while (current.length !== 1) {
    let max = 0;
    let maxIdx = -1;

    current.forEach((value, idx) => {
      if (value > max) {
        max = value;
        maxIdx = idx;
      }
    });

    if (maxIdx === 0) {
      sum += current[maxIdx] - current[maxIdx + 1];
    } else if (maxIdx === current.length - 1) {
      sum += current[maxIdx] - current[maxIdx - 1];
    } else {
      const rightDiff = current[maxIdx] - current[maxIdx + 1];
      const leftDiff = current[maxIdx] - current[maxIdx - 1];
      sum += Math.min(leftDiff, rightDiff);
    }
    current = current.filter((v) => v !== max);
  }

  return sum;
}

console.log(solution());
