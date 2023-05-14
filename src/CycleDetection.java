import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class CycleDetection {
    private final int V; // numărul de noduri
    private final List<List<Integer>> adj; // lista de adiacență

    public CycleDetection(int V) {
        this.V = V;
        adj = new ArrayList<>(V);

        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
    }

    // sortare topologică
    private boolean topologicalSortUtil(int v, boolean[] visited, boolean[] recStack, Stack<Integer> stack) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbour : adj.get(v)) {
            if (!visited[neighbour] && topologicalSortUtil(neighbour, visited, recStack, stack)) {
                return true;
            } else if (recStack[neighbour]) {
                return true;
            }
        }

        recStack[v] = false;
        stack.push(v);

        return false;
    }

    public boolean topologicalSort() {
        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i] && topologicalSortUtil(i, visited, recStack, stack)) {
                return true;
            }
        }

        return false;
    }

    public boolean hasCycle() {
        return topologicalSort();
    }
}
