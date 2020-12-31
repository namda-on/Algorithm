const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", async (line) => {
  input.push(line);
}).on("close", () => {
  const array = input[1].split(" ");
  console.log(solver(array));
});

const solver = (array) => {
  const word = array[0][0];
  let result = 1;
  for (let i = 0; i < array.length; i++) {
    if (array[i][0] != word) {
      result = 0;
      break;
    }
  }
  return result;
};
