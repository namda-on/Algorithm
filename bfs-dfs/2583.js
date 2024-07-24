const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [M, N, K] = input[0].split(" ").map(Number);

const rectangle = [];
for (let i = 0; i < K; i++) {
  const [startX, startY, endX, endY] = input[i + 1].split(" ").map(Number);
  rectangle.push({ startX, startY, endX, endY });
}

const visited = Array.from({ length: N }, () => Array(M).fill(false));

const colored = Array.from({ length: N }, () => Array(M).fill(false));

// input 기반 color 처리
for (let k = 0; k < K; k++) {
  const { startX, startY, endX, endY } = rectangle[k];
  for (let i = startX; i < endX; i++) {
    for (let j = startY; j < endY; j++) {
      colored[i][j] = true;
    }
  }
}
const result = [];

// 계산
for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (!visited[i][j] && !colored[i][j]) {
      bfs({ x: i, y: j });
    }
  }
}

function bfs({ x, y }) {
  let area = 0;
  const needVisit = [];

  needVisit.push({ x, y });
  while (needVisit.length !== 0) {
    const { x: currentX, y: currentY } = needVisit.shift();
    if (!visited[currentX][currentY] && !colored[currentX][currentY]) {
      visited[currentX][currentY] = true;
      area++;
      if (currentX + 1 < N) needVisit.push({ x: currentX + 1, y: currentY });
      if (currentX > 0) needVisit.push({ x: currentX - 1, y: currentY });
      if (currentY + 1 < M) needVisit.push({ x: currentX, y: currentY + 1 });
      if (currentY > 0) needVisit.push({ x: currentX, y: currentY - 1 });
    }
  }

  result.push(area);
}

console.log(result.length);
console.log(result.sort((a, b) => a - b).join(" "));
