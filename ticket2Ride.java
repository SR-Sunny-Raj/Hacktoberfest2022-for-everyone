import java.io.*;
import java.util.*;

public class Solution {

  static final int BASE = 1 << 19;
  static long[] t = new long[BASE * 2];
  static long[] upd = new long[BASE * 2];

  static long get() {
    return t[1] + upd[1];
  }

  static int l, r, delta;

  static void put(int v, int cl, int cr) {
    if (r <= cl || cr <= l) {
      return;
    }
    if (l <= cl && cr <= r) {
      upd[v] += delta;
      return;
    }
    int cc = (cl + cr) >> 1;
    put(v << 1, cl, cc);
    put((v << 1) + 1, cc, cr);
    t[v] = Math.max(t[v << 1] + upd[v << 1], t[(v << 1) + 1] + upd[(v << 1) + 1]);
  }

  static int[] in;
  static int[] out;

  static void add(int v, int deltat) {
    l = in[v];
    r = out[v];
    delta = deltat;
    put(1, 0, BASE);
  }

  static boolean isPrev(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
  }

  static class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }

  static List<Pair>[] other;
  static List<Pair>[] down;
  static List<Pair>[] up;
  static List<Pair>[] g;

  static long best = 0;

  static class NodeGo {
    int u;
    int prev;
    Pair p;
    boolean start = true;

    public NodeGo(int u, int prev, Pair p) {
      this.u = u;
      this.prev = prev;
      this.p = p;
    }
  }

  static void go() {
    Deque<NodeGo> deque = new LinkedList<>();
    deque.add(new NodeGo(0, 0, null));

    while (!deque.isEmpty()) {
      NodeGo node = deque.peekLast();

      if (node.start) {
        if (node.p != null) {
          add(node.p.first, 2 * node.p.second);
          upd[1] -= node.p.second;
        }

        for (Pair p : other[node.u]) {
          add(p.first, p.second);
        }
        for (Pair p : down[node.u]) {
          add(p.first, -p.second);
          upd[1] += p.second;
        }
        for (Pair p : up[node.u]) {
          add(p.first, -p.second);
        }
        best = Math.max(best, get());

        for (Pair p : g[node.u]) {
          if (p.first == node.prev) {
            continue;
          }
          deque.add(new NodeGo(p.first, node.u, p));
        }

        node.start = false;
      } else {
        for (Pair p : other[node.u]) {
          add(p.first, -p.second);
        }
        for (Pair p : down[node.u]) {
          add(p.first, p.second);
          upd[1] -= p.second;
        }
        for (Pair p : up[node.u]) {
          add(p.first, p.second);
        }

        if (node.p != null) {
          add(node.p.first, -2 * node.p.second);
          upd[1] += node.p.second;
        }

        deque.removeLast();
      }
    }
  }

  static int sc = 0;
  static int[] st;
  static int[] visits;
  static int[] needh;
  static int[] step;
  static int timer = 0;
  static List<Integer>[] endings;

  static class NodeDfs {
    int u;
    int p;
    long depth;
    boolean start = true;

    public NodeDfs(int u, int p, long depth) {
      this.u = u;
      this.p = p;
      this.depth = depth;
    }
  }

  static void dfs() {
    Deque<NodeDfs> deque = new LinkedList<>();
    deque.add(new NodeDfs(0, 0, 0));

    while (!deque.isEmpty()) {
      NodeDfs node = deque.peekLast();

      if (node.start) {
        st[sc++] = node.u;
        for (int id : endings[node.u]) {
          visits[id]++;
          if (visits[id] == 1) {
            needh[id] = sc;
          } else if (visits[id] == 2) {
            step[id] = st[needh[id]];
          }
        }
        in[node.u] = timer++;
        t[in[node.u] + BASE] = -node.depth;

        for (Pair p : g[node.u]) {
          if (p.first != node.p) {
            deque.add(new NodeDfs(p.first, node.u, node.depth + p.second));
          }
        }

        node.start = false;
      } else {
        for (int id : endings[node.u]) {
          visits[id]--;
        }
        out[node.u] = timer;
        --sc;

        deque.removeLast();
      }
    }
  }

  @SuppressWarnings("unchecked")
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    StringTokenizer stk = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(stk.nextToken());

    other = new List[n];
    down = new List[n];
    up = new List[n];
    g = new List[n];
    endings = new List[n];

    for (int i = 0; i < g.length; i++) {
      g[i] = new ArrayList<>();
      endings[i] = new ArrayList<>();
      other[i] = new ArrayList<>();
      up[i] = new ArrayList<>();
      down[i] = new ArrayList<>();
    }

    for (int i = 0; i < n - 1; i++) {
      stk = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(stk.nextToken()) - 1;
      int v = Integer.parseInt(stk.nextToken()) - 1;
      int l = Integer.parseInt(stk.nextToken());
      g[u].add(new Pair(v, l));
      g[v].add(new Pair(u, l));
    }

    stk = new StringTokenizer(br.readLine());
    int m = Integer.parseInt(stk.nextToken());
    Pair[] tickets = new Pair[m];
    int[] ticket_cost = new int[m];

    for (int i = 0; i < m; i++) {
      stk = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(stk.nextToken()) - 1;
      int v = Integer.parseInt(stk.nextToken()) - 1;
      int c = Integer.parseInt(stk.nextToken());
      endings[u].add(i);
      endings[v].add(i);
      tickets[i] = new Pair(u, v);
      ticket_cost[i] = c;
    }

    step = new int[m];
    Arrays.fill(step, -1);
    in = new int[n];
    out = new int[n];
    st = new int[n];
    visits = new int[m];
    needh = new int[m];

    dfs();
    for (int i = BASE - 1; i > 0; --i) {
      t[i] = Math.max(t[i * 2], t[i * 2 + 1]);
    }

    for (int i = 0; i < m; i++) {
      int u = tickets[i].first;
      int v = tickets[i].second;
      int c = ticket_cost[i];
      if (isPrev(v, u)) {
        int temp = u;
        u = v;
        v = temp;
      }
      if (isPrev(u, v)) {
        u = step[i];
        add(v, c);
        up[u].add(new Pair(v, c));
        down[v].add(new Pair(u, c));
      } else {
        other[u].add(new Pair(v, c));
        other[v].add(new Pair(u, c));
      }
    }
    go();

    bw.write(String.valueOf(best));
    bw.newLine();

    bw.close();
    br.close();
  }
}
