const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", async (line) => {
  input.push(line);
}).on("close", () => {
  const n = Number(input[0]);
  const linkNum = Number(input[1]);
  const graph = new Graph(n);

  for (let i = 2; i <= linkNum + 1; i++) {
    const [v, w] = input[i].split(" ").map((e) => Number(e));
    graph.addAdEdge(v, w);
  }

  const result = DFS(graph);
  console.log(result.length - 1);
  process.exit();
});

const DFS = (graph) => {
  const visited = [];
  let needVisit = [1];

  while (needVisit.length !== 0) {
    const current = needVisit.pop();
    if (!visited.includes(current)) {
      visited.push(current);
      needVisit.push(...graph.getAdVertices(current));
    }
  }

  return visited;
};

class Graph {
  constructor(numOfVertices) {
    this.numOfVertices = numOfVertices;
    this._adjacencyList = this._initAdjacencyList();
  }

  getAdVertices(v) {
    return this._adjacencyList.get(v);
  }

  addAdEdge(v, w) {
    this._adjacencyList.get(v).push(w);
    this._adjacencyList.get(w).push(v);
  }

  _initAdjacencyList() {
    const AdjacencyMap = new Map();
    for (let i = 1; i <= this.numOfVertices; i++) {
      AdjacencyMap.set(i, []);
    }
    return AdjacencyMap;
  }
}
