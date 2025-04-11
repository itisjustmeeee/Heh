import networkx as nx

# Определяем граф
G = nx.DiGraph()

# Определяем вершины и ребра
edges = [
    (0, 1), (0, 2), (0, 3), (1, 2), (1, 4), (1, 5),
    (2, 6), (2, 9), (3, 2), (3, 6), (3, 7), (4, 5),
    (4, 8), (4, 11), (5, 8), (5, 10), (6, 1), (7, 10),
    (7, 14), (8, 14), (8, 9), (8, 12), (9, 6), (9, 10),
    (9, 14), (10, 14), (11, 1), (11, 12), (12, 13), (13, 8),
    (13, 14)
]

# Задаем веса ребер
N = 6
for (i, j) in edges:
    weight = (N * (i**2 + j**2) + i**2 + j**2 + i + j) % 10 + 5
    G.add_edge(i, j, capacity=weight)

# Определяем исток и сток
source = 0  # s
sink = 14   # t

# Находим максимальный поток
flow_value, flow_dict = nx.maximum_flow(G, source, sink)

# Находим минимальный разрез
cut_value, partition = nx.minimum_cut(G, source, sink)
reachable, non_reachable = partition

# Вывод результатов
print(f"Максимальный поток: {flow_value}")
print("Поток по ребрам:")
for u in flow_dict:
    for v in flow_dict[u]:
        if flow_dict[u][v] > 0:
            print(f"{u} -> {v}: {flow_dict[u][v]}")

print(f"Минимальный разрез: {cut_value}")
print("Вершины в достижимой части:")
print(reachable)
print("Вершины в недостижимой части:")
print(non_reachable)
'''
import networkx as nx
from collections import deque

# Создаём граф
G = nx.DiGraph()
vertices = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]  # s=0, t=14
edges = [
    (0, 1), (0, 2), (0, 3), (1, 2), (1, 4), (1, 5), (2, 6), (2, 9),
    (3, 2), (3, 6), (3, 7), (4, 5), (4, 8), (4, 11), (5, 8), (5, 10),
    (6, 1), (7, 10), (7, 14), (8, 14), (8, 9), (8, 12), (9, 6), (9, 10),
    (9, 14), (10, 14), (11, 1), (11, 12), (12, 13), (13, 8), (13, 14)
]

# Функция для вычисления веса дуги
def compute_weight(i, j, N=6):
    return ((N * (i**2 + j**2) + i**2 + j**2 + i + j) % 10) + 5

# Добавляем вершины и дуги с весами
G.add_nodes_from(vertices)
for i, j in edges:
    weight = compute_weight(i, j)
    G.add_edge(i, j, capacity=weight)

# Функция для поиска пути BFS в остаточном графе
def bfs_residual_path(G, source, sink, flow):
    parent = {source: None}
    queue = deque([source])
    while queue:
        u = queue.popleft()
        for v in G.neighbors(u):
            if v not in parent and G[u][v]['capacity'] - flow.get((u, v), 0) > 0:
                parent[v] = u
                queue.append(v)
                if v == sink:
                    path = []
                    curr = sink
                    while curr is not None:
                        path.append(curr)
                        curr = parent[curr]
                    return path[::-1]
    return None

# Алгоритм Форда-Фалкерсона
def ford_fulkerson(G, source, sink):
    flow = {}
    max_flow = 0
    while True:
        path = bfs_residual_path(G, source, sink, flow)
        if not path:
            break
        # Находим минимальную остаточную пропускную способность
        flow_value = float('inf')
        for i in range(len(path) - 1):
            u, v = path[i], path[i + 1]
            flow_value = min(flow_value, G[u][v]['capacity'] - flow.get((u, v), 0))
        # Обновляем поток
        for i in range(len(path) - 1):
            u, v = path[i], path[i + 1]
            flow[(u, v)] = flow.get((u, v), 0) + flow_value
            # Добавляем обратное ребро для остаточного графа
            flow[(v, u)] = flow.get((v, u), 0) - flow_value
        max_flow += flow_value
    return max_flow, flow

# Находим минимальный разрез
def find_min_cut(G, source, flow):
    visited = set()
    queue = deque([source])
    visited.add(source)
    while queue:
        u = queue.popleft()
        for v in G.neighbors(u):
            if v not in visited and G[u][v]['capacity'] - flow.get((u, v), 0) > 0:
                visited.add(v)
                queue.append(v)
    cut_edges = [(u, v) for u in visited for v in G.neighbors(u) if v not in visited]
    cut_capacity = sum(G[u][v]['capacity'] for u, v in cut_edges)
    return visited, cut_edges, cut_capacity

# Выполняем алгоритм
max_flow, flow = ford_fulkerson(G, 0, 14)
reachable, cut_edges, cut_capacity = find_min_cut(G, 0, flow)

# Вывод результатов
print(f"Максимальный поток: {max_flow}")
print("Минимальный разрез:")
print(f"Множество вершин, достижимых из s: {sorted(reachable)}")
print(f"Дуги разреза: {cut_edges}")
print(f"Пропускная способность разреза: {cut_capacity}")

# Проверка корректности
assert max_flow == cut_capacity, "Максимальный поток не равен пропускной способности разреза!"
'''
