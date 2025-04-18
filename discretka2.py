# Задание 1
'''
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats

n = 1000
p = 0.003

# Генерация графа Эрдёша-Реньи
G = nx.erdos_renyi_graph(n, p)

# 1. Оценка разницы между количеством рёбер и их ожидаемым количеством
actual_edges = G.number_of_edges()
expected_edges = p * (n * (n - 1)) / 2
edge_difference = actual_edges - expected_edges

print(f"Фактическое число рёбер: {actual_edges}")
print(f"Ожидаемое число рёбер: {expected_edges:.2f}")
print(f"Разница (фактическое - ожидаемое): {edge_difference:.2f}")

# 2. Получение распределения степеней
degrees = [d for n, d in G.degree()]  # Список степеней вершин
degree_counts = np.bincount(degrees)  # Частота каждой степени
degree_values = np.arange(len(degree_counts))  # Возможные степени

# Убираем нулевые степени и нулевые частоты
nonzero_mask = (degree_counts > 0) & (degree_values > 0)  # Исключаем k=0
degree_values = degree_values[nonzero_mask]
degree_counts = degree_counts[nonzero_mask]

if len(degree_values) == 0:
    print("Ошибка: нет ненулевых степеней для анализа")
    exit(1)

# Нормализация для получения вероятностей
degree_probs = degree_counts / degree_counts.sum()

# 3. Построение log-log графика
plt.figure(figsize=(8, 6))
plt.loglog(degree_values, degree_probs, 'o', label='Данные')

# 4. Аппроксимация степенного закона
# Логарифмируем данные для линейной регрессии: log(P(k)) = log(a) - gamma * log(k)
log_degrees = np.log(degree_values)
log_probs = np.log(degree_probs)

# Линейная регрессия
slope, intercept, r_value, p_value, std_err = stats.linregress(log_degrees, log_probs)
gamma = -slope  # Показатель степени
a = np.exp(intercept)  # Коэффициент a

# Построение аппроксимации
fit_line = a * degree_values ** (-gamma)
plt.loglog(degree_values, fit_line, 'r-', label=f'Fit: P(k) ~ {a:.2e} k^(-{gamma:.2f})')

plt.xlabel('Степень вершины (k)')
plt.ylabel('Доля вершин (P(k))')
plt.title('Распределение степеней вершин в log-log координатах')
plt.legend()
plt.grid(True, which="both", ls="--")
plt.show()

print(f"Оценка показателя степени (γ): {gamma:.2f}")
print(f"Коэффициент a: {a:.2e}")
print(f"Коэффициент корреляции R²: {r_value**2:.4f}")
'''
# Задание 2
'''
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import random

n = 1000
p = 0.003

# Генерация графа Эрдёша-Реньи
G = nx.erdos_renyi_graph(n, p)

# 1. Число компонент связности
components = list(nx.connected_components(G))
num_components = len(components)
print(f"Число компонент связности: {num_components}")

# 2. Гигантская компонента
# Находим наибольшую компоненту (по числу вершин)
giant_component = max(components, key=len)
giant_size = len(giant_component)
print(f"Размер гигантской компоненты: {giant_size} вершин")
print(f"Доля вершин в гигантской компоненте: {giant_size/n:.3f}")

# Диаметр гигантской компоненты
giant_subgraph = G.subgraph(giant_component)
if nx.is_connected(giant_subgraph):
    diameter = nx.diameter(giant_subgraph)
    print(f"Диаметр гигантской компоненты: {diameter}")
else:
    print("Гигантская компонента не связна (невозможно вычислить диаметр)")

# 3. Удаление 10% вершин
num_to_remove = int(0.1 * n)  # 100 вершин
vertices = list(G.nodes())
random.shuffle(vertices)
vertices_to_remove = vertices[:num_to_remove]

# Создаём копию графа и удаляем вершины
G_removed = G.copy()
G_removed.remove_nodes_from(vertices_to_remove)

# Проверяем компоненты после удаления
components_removed = list(nx.connected_components(G_removed))
num_components_removed = len(components_removed)
print(f"\nПосле удаления 10% вершин:")
print(f"Число компонент связности: {num_components_removed}")

# Проверяем гигантскую компоненту
giant_component_removed = max(components_removed, key=len)
giant_size_removed = len(giant_component_removed)
print(f"Размер гигантской компоненты: {giant_size_removed} вершин")
print(f"Доля вершин в гигантской компоненте: {giant_size_removed/(n-num_to_remove):.3f}")

# 4. Исследование порога разрушения гигантской компоненты
fractions = np.linspace(0, 0.8, 20)  # Доли от 0 до 80%
giant_sizes = []

for f in fractions:
    num_to_remove = int(f * n)
    vertices = list(G.nodes())
    random.shuffle(vertices)
    vertices_to_remove = vertices[:num_to_remove]
    
    G_temp = G.copy()
    G_temp.remove_nodes_from(vertices_to_remove)
    
    components_temp = list(nx.connected_components(G_temp))
    giant_size = len(max(components_temp, key=len))
    giant_sizes.append(giant_size / (n - num_to_remove))  # Доля оставшихся вершин

# Построение графика зависимости размера гигантской компоненты от доли удалённых вершин
plt.figure(figsize=(8, 6))
plt.plot(fractions, giant_sizes, 'o-', label='Доля вершин в гигантской компоненте')
plt.axvline(x=0.667, color='r', linestyle='--', label='Теоретический порог (f ≈ 0.667)')
plt.xlabel('Доля удалённых вершин (f)')
plt.ylabel('Доля вершин в гигантской компоненте')
plt.title('Разрушение гигантской компоненты')
plt.legend()
plt.grid(True)
plt.show()

# Вывод порога разрушения
threshold = 1 - 1/(n*p)
print(f"Теоретический порог разрушения гигантской компоненты: f ≈ {threshold:.3f}")
'''
# Задание 3
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

# Параметры графа
n = 1000  # Число вершин
p = 0.003  # Вероятность ребра

# Генерация графа Эрдёша-Реньи
G = nx.erdos_renyi_graph(n, p)

# 1. Число компонент связности
components = list(nx.connected_components(G))
num_components = len(components)
print(f"Число компонент связности: {num_components}")

# 2. Гигантская компонента
giant_component = max(components, key=len)
giant_size = len(giant_component)
print(f"Размер гигантской компоненты: {giant_size} вершин")
print(f"Доля вершин в гигантской компоненте: {giant_size/n:.3f}")

# Диаметр гигантской компоненты
giant_subgraph = G.subgraph(giant_component)
if nx.is_connected(giant_subgraph):
    diameter = nx.diameter(giant_subgraph)
    print(f"Диаметр гигантской компоненты: {diameter}")
else:
    print("Гигантская компонента не связна (невозможно вычислить диаметр)")

# 3. Удаление 50 вершин с наибольшими степенями
# Сортируем вершины по степени (в убывающем порядке)
degrees = [(node, G.degree(node)) for node in G.nodes()]
degrees_sorted = sorted(degrees, key=lambda x: x[1], reverse=True)
vertices_to_remove = [node for node, degree in degrees_sorted[:50]]

# Создаём копию графа и удаляем вершины
G_removed = G.copy()
G_removed.remove_nodes_from(vertices_to_remove)

# Проверяем компоненты после удаления
components_removed = list(nx.connected_components(G_removed))
num_components_removed = len(components_removed)
print(f"\nПосле удаления 50 вершин с наибольшими степенями:")
print(f"Число компонент связности: {num_components_removed}")

# Проверяем гигантскую компоненту
giant_component_removed = max(components_removed, key=len)
giant_size_removed = len(giant_component_removed)
print(f"Размер гигантской компоненты: {giant_size_removed} вершин")
print(f"Доля вершин в гигантской компоненте: {giant_size_removed/(n-50):.3f}")

# 4. Исследование порога разрушения гигантской компоненты
fractions = np.linspace(0, 0.5, 20)  # Доли от 0 до 50%
giant_sizes = []

# Сохраняем отсортированный список вершин по степени
vertices_by_degree = [node for node, degree in degrees_sorted]

for f in fractions:
    num_to_remove = int(f * n)
    vertices_to_remove = vertices_by_degree[:num_to_remove]
    
    G_temp = G.copy()
    G_temp.remove_nodes_from(vertices_to_remove)
    
    components_temp = list(nx.connected_components(G_temp))
    giant_size = len(max(components_temp, key=len))
    giant_sizes.append(giant_size / (n - num_to_remove))  # Доля оставшихся вершин

# Построение графика
plt.figure(figsize=(8, 6))
plt.plot(fractions, giant_sizes, 'o-', label='Доля вершин в гигантской компоненте')
plt.axvline(x=0.667, color='r', linestyle='--', label='Порог для случайного удаления (f ≈ 0.667)')
plt.xlabel('Доля удалённых вершин (f)')
plt.ylabel('Доля вершин в гигантской компоненте')
plt.title('Разрушение гигантской компоненты при удалении вершин с наибольшими степенями')
plt.legend()
plt.grid(True)
plt.show()

# Оценка порога разрушения
# Находим f, при котором доля вершин в гигантской компоненте падает ниже 0.1
threshold_idx = np.where(np.array(giant_sizes) < 0.1)[0]
if len(threshold_idx) > 0:
    threshold_f = fractions[threshold_idx[0]]
    print(f"Экспериментальный порог разрушения гигантской компоненты: f ≈ {threshold_f:.3f}")
else:
    print("Гигантская компонента не разрушилась в диапазоне f до 0.5")
