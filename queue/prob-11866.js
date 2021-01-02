const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, k;

rl.on("line", async (line) => {
  [n, k] = line.split(" ").map((e) => Number(e));
}).on("close", () => {
  console.log(solver());
});

const solver = () => {
  const queue = Array.from(Array(n + 1).keys()).splice(1);
  const result = [];
  while (queue.length !== 0) {
    for (let i = 0; i < k - 1; i++) {
      const a = queue.shift();
      queue.push(a);
    }
    const element = queue.shift();
    result.push(element);
  }
  return arrayToAnswer(result);
};

const arrayToAnswer = (array) => {
  let answer = "<";
  array.forEach((e) => {
    answer += `${e}, `;
  });
  answer = answer.substr(0, answer.length - 2);
  answer += ">";
  return answer;
};
