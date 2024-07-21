const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const testCase = Number(input[0]);

for (let i = 1; i <= testCase; i++) {
  const N = Number(input[2 * i - 1]);
  const A = input[2 * i].split(" ").map(Number);
  const maxArray = [];

  let maxSoFar = 0;
  let answer = 0;

  // 뒤에서부터 앞으로 진행하면서 최대값을 추적
  for (let k = N - 1; k >= 0; k--) {
    if (A[k] > maxSoFar) {
      maxSoFar = A[k];
    }
    answer += maxSoFar - A[k];
  }

  console.log(answer);
}
