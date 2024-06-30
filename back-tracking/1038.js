const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const targetOrder = Number(input[0]);

let digitCount = 0;
let currentOrder = 0;

const arr = [];
const checked = [];
let done = false;

function solution() {
  if (targetOrder === 0) {
    console.log(0);
    return;
  }

  while (true) {
    if (done || digitCount === 11) break;
    dfs(0, digitCount);
    digitCount++;
  }

  if (!done) console.log(-1);
}

function dfs(n, maxN) {
  if (n === maxN) {
    if (targetOrder === currentOrder) {
      done = true;
      console.log(arr.join(""));
    }
    currentOrder++;
    return;
  }

  for (let i = 0; i < 10; i++) {
    if (!checked[i]) {
      // 맨 앞자리
      if (n === 0 && i === 0) continue;
      if (n !== 0 && arr[n - 1] <= i) continue;

      checked[i] = true;
      arr[n] = i;

      if (!done) {
        dfs(n + 1, maxN);
      }
      checked[i] = false;
    }
  }
}

solution();
