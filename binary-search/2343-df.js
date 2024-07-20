const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const A = input[1].split(" ").map(Number);

function solution() {
  let end = A.reduce((acc, cur) => acc + cur, 0);
  let start = Math.max(1, Math.max(...A) - 1);

  while (start + 1 < end) {
    const mid = Math.floor((start + end) / 2);
    if (canSave(mid)) {
      end = mid;
    } else start = mid;
  }

  return end;
}

function canSave(maxLength) {
  const checked = Array(N).fill(false);

  let m = 1;
  let length = 0;
  for (let i = 0; i < N; i++) {
    // 담을 수 있는 경우
    if (length + A[i] <= maxLength) {
      length += A[i];
      checked[i] = true;
      continue;
    }
    m++;

    if (m > M || maxLength < A[i]) return false;
    length = A[i];
    checked[i] = true;
  }

  return checked.every((v) => Boolean(v));
}

console.log(solution());
