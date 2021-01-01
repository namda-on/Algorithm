const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, m, l;
const position = [];
const input = [];
rl.on("line", async (line) => {
  input.push(line);
}).on("close", () => {
  [n, m, l] = input[0].split(" ").map((e) => Number(e));
  input[1].split(" ").forEach((e) => {
    position.push(Number(e));
  });
  position.push(0);
  position.push(Number(l));
  console.log(solver(m));
});

const solver = (m) => {
  position.sort((a, b) => a - b);
  const diff = getDiff(position);
  let start = 0,
    end = l,
    mid = 0;
  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    let x = 0;
    diff.forEach((e) => {
      if (e % mid === 0) x += e / mid - 1;
      else x += Math.floor(e / mid);
    });
    if (x > m) start = mid + 1;
    else end = mid - 1;
  }

  return start;
};

const getDiff = (array) => {
  const sectionDistance = [];
  for (let i = 0; i < array.length - 1; i++) {
    sectionDistance.push(array[i + 1] - array[i]);
  }
  return sectionDistance;
};
